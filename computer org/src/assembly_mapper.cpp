#pragma once
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <bitset>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include "assembly_mapper.hpp"

using std::map;
using std::string;
using std::stringstream;
using std::bitset;
using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::fstream;

template <typename T>
T StringToNumber ( const string &Text )
{
	stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

#define AM assembly_mapper::

AM assembly_mapper(void)
{
	init_this();
	step = 0;
}

AM ~assembly_mapper(void)
{
}

void AM readf(fstream &sourceCode)
{
	string buffer;
	while(!sourceCode.eof())
	{
		getline(sourceCode, buffer);
		inputData.push_back(buffer);
	}
	step = 1;
}

//returns true if valid program in memory
//else false
bool AM validate()
{
	bool retVal = true;
	if (step != 1) return false;
	//remove comments
	stripAllComments();
	//remove empty lines
	stripEmptyLines();
	//find labels, mapping them and adjusting data
	while(mapNextLabel())
	{
		//map a label
		//remove empty lines
		stripEmptyLines();
	}
	replaceAllCommasWithSpaces(); //don't want commas
	retVal = (step == 1);
	//string op, rs, rt, rd;
	//string bucket;
	//int shamt, imm, offset, target;
	
	for(int i = 0; (i < inputData.size()) && (step > 0); i++)
	{
		instruction_no = i;
		//start the translation
		//op = pullOp(inputData[i]);
		//translate
		outputData.push_back(translate(inputData[i]));
		if (outputData[i].length() != 32)
			step = -4;
			//cout << outputData[i].length() << endl;
	}
	if (step < 0) return false;
	return true;
	
}

void AM replaceAllCommasWithSpaces()
{
	for(int i = 0; i < inputData.size(); i++)
	{
		for(int j = 0; j < inputData[i].length(); j++)
		{
			if (inputData[i][j] == ',')
				inputData[i][j] = ' ';
		}
	}
}

void AM init_this()
{
	map_R_Types();
	map_I_Types();
	map_J_Types();
	map_Registers();
	map_Instruction_Types();
}




/*
R-TYPE:
	op $rd, $rs, $rt

I-TYPE:
	op $rt, $rs, imm
J-TYPE:
	j target
	jal target
*/

string AM translate(string &instr)
{
	string words[10];  //there should never be 10 words in an assembly
	//code line at this point.........  but whatever
	string temp = instr;
	string ret = "";
	for(int i = 0; i < 10; i++)
	{
		words[i] = getWord(temp);
	}
	//words[0] is the op
	
	
	
	// ************************************************* //
	
	// R-TYPE //
	
	if(instruction_types[words[0]] == "R")
	{
		if(words[0] == "jr")
		{
			//next word is $rs
			if (register_mapper.count(words[1]) < 1)
			{
				return ret;
			}
			ret += opcode_mapper[words[0]];
			ret += register_mapper[words[1]];
			ret += zeros(15);
			ret += func_code_mapper[words[0]];
			return ret;
		}
		else
		{
			if ((words[0] == "sll") || (words[0] == "srl"))
			{
				ret += opcode_mapper[words[0]];//op
				ret += zeros(5);//rs
				ret += register_mapper[words[2]];//rt
				ret += register_mapper[words[1]];//rd
				ret += toBinary(atoi(words[3].c_str()), 5);//shamt
				ret += func_code_mapper[words[0]];//func
				return ret;
			}
			ret += opcode_mapper[words[0]];//op
			ret += register_mapper[words[2]];//rs
			ret += register_mapper[words[3]];//rt
			ret += register_mapper[words[1]];//rd
			ret += zeros(5);//shamt
			ret += func_code_mapper[words[0]];
			return ret;
		}
	}
	
	
	
	// ******************************************* //
	
	// I-TYPE //
	
	else if (instruction_types[words[0]] == "I")
	{
		if ((words[0] == "beq") || (words[0] == "bne"))
		{
			bool lookedUp = false;
			int check = StringToNumber<int>(words[3]);//attempt to convert
			if (!check) //if it didn't work
			{
				check = labels[words[3]];//attempt a look-up
				lookedUp = true;
			}
			//conversion would have worked correctly,
			//but also looking it up on the label map would
			//have given the correct value because of value
			//initialization.....  so w/e  either way
			//verify that the program's not sending you back to the
			//beginning
			if ((!check) && (words[3] != "0"))
			{
				step = -3;
				return ret;
			}
			ret += opcode_mapper[words[0]];
			ret += register_mapper[words[1]];
			ret += register_mapper[words[2]];
			ret += toBinary((lookedUp ? (check - instruction_no) : (check)), 16);
			return ret;
		}
		if ((words[0] == "lw") || (words[0] == "sw"))
		{
			ret += opcode_mapper[words[0]];
			string off, rs;
			int i = 0;
			while ((words[2][i] != '(') && (i < words[2].length()))
			{
				off += words[2][i];
				i++;
			}
			i++;
			while((words[2][i] != ')')&& (i < words[2].length()))
			{
				rs += words[2][i];
				i++;
			}
			int offi = StringToNumber<int>(off);
			ret += register_mapper[rs];
			ret += register_mapper[words[1]];
			ret += toBinary(offi, 16);
			return ret;
		}
		ret += opcode_mapper[words[0]];
		ret += register_mapper[words[2]];
		ret += register_mapper[words[1]];
		ret += toBinary(StringToNumber<int>(words[3]), 16);
		return ret;
		
	}
	
	
	// *************************************** //
	
	// J-TYPE //
	
	else if (instruction_types[words[0]] == "J")
	{
		ret += opcode_mapper[words[0]];
		bool lookedUp = false;
		int check = StringToNumber<int>(words[1]);//attempt to convert
		if (!check) //if it didn't work
		{
			check = labels[words[1]];//attempt a look-up
			lookedUp = true;
		}
		//conversion would have worked correctly,
		//but also looking it up on the label map would
		//have given the correct value because of value
		//initialization.....  so w/e  either way
		//verify that the program's not sending you back to the
		//beginning
		if ((!check) && (words[3] != "0"))
		{
			step = -3;
			return ret;
		}
		ret += toBinary((lookedUp ? (check - instruction_no) : (check)), 26);
	}
	else
	{
		step = -3;
		return ret;
	}
	
}


//danger danger this modifies the passed string
string AM getWord(string &str)
{
	string ret = "";
	bool wordStarted = false;
	bool wordStopped = false;
	int index_of_space = -1;
	int i;
	//get the first word. dont return commas.
	for(i = 0; (i < str.length()) && !wordStopped; i++)
	{
		if ((!isspace(str[i])) && !wordStarted)
		{
			wordStarted = true;
		}
		if(wordStarted)
		{
			if(!isspace(str[i]))
			{
				if(str[i] != ',') //don't do commas ---- no reason for them
				ret += str[i];
			}
			else
			{
				index_of_space = i;
				str = str.substr(i+1, str.length());
				wordStopped = true;
				return ret;
			}
		}
	}
	if (i == str.length())
	str = "";
	return ret;
}
/*
string AM pullOp(string &str){}
string AM pull_Rd(string &opc, string &str){}
string AM pull_Rs(string &opc, string &str){}
string AM pull_Rt(string &opc, string &str){}
string AM pull_shamt(string &opc, string &str){}
string AM pull_imm(string &opc, string &str){}
string AM pull_offset(string &opc, string &str){}
string AM pull_target(string &opc, string &str){}
*/
void AM getLabels()
{
	int temp;
	string str;
	string label;
	for(int i = 0; i < inputData.size(); i++)
	{
		temp = indexOfLabel(inputData[i]);
		if (temp >= 0) //indicate the presence of a label
		{
			label = pullLabel(temp, inputData[i]);
			
			
		}
	}
}

//returns true if mapped a label
bool AM mapNextLabel()
{
	int temp = 0;
	string tempLabel = "";
	//return true if found a label
	for(int i = 0; i < inputData.size(); i++)
	{
		//look through the code for a label
		temp = indexOfLabel(inputData[i]);
		if (temp >= 0)
		{
			//if found one, pull the label from the line of code
			tempLabel = pullLabel(temp, inputData[i]);
			if (!labels.count(tempLabel)) // if it's unique
			{
				//map the label and line number
				labels[tempLabel] = i;
				//remove the label from the line number
				inputData[i] = remainingString(temp, inputData[i]);
				//return true, that we have found a label
				return true;
			}
			else
			{
				//if it's not unique, go to error step and return false
				step = -1;
				return false;
			}
			
		}
	}
	//if loop completes and did not return
	return false;
}

int AM indexOfLabel(string &str)
{
	int ret = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == ':')
		{
			return i;
		}
	}
	return -1;
}

string AM pullLabel(int index, string &str)
{
	if (index >=0)
		return str.substr(0,index);
	else
		return str;
}

string AM remainingString(int index, string &str)
{
	if (index >= 0)
		return str.substr(index + 1, str.size());
	else
		return str;
}

void AM storeInstruction(string &instructionLine)
{
	inputData.push_back(stripComments(instructionLine));
}

bool AM value_is_valid_16b(int val)
{
	unsigned int testVal = val;
	return (testVal <= 0xFFFF); // maximum value to be held in 16 bits
}

bool AM value_is_valid_26b(int val)
{
	unsigned int testVal = val;
	return (testVal <= 0x3FFFFFF); // maximum value to be held in 26 bits
}
string AM toBinary(int val, int bits)
{
	if (bits == 5)
	return bitset<5>(val).to_string();
	if (bits == 6)
	return bitset<6>(val).to_string();
	if (bits == 16)
	return bitset<16>(val).to_string();
	if (bits == 26)
	return bitset<26>(val).to_string();
	else
	return bitset<5>(val).to_string();
}

string AM stripString(string str, string charsToStrip)
{
	string retString = "";
	bool mem = true;
	for(int i = 0; i < str.length(); i++)
	{
		mem = true;
		for(int j = 0; (j < charsToStrip.length()) && mem; j++)
		{
			if (str[i] == charsToStrip[j])
			{
				mem = false;
				j = charsToStrip.length();
			}
		}
		if (mem)
		{
			retString += str[i];
		}
	}
	return retString;
}

void AM stripAllComments()
{
	for(int i = 0; i < inputData.size(); i++)
	{
		inputData[i] = stripComments(inputData[i]);
	}
}

string AM stripComments(string str)
{
	return
	str.substr(0, 
			((str.find("#") != std::string::npos) ? 
					str.find("#") : str.size()));
}

void AM stripEmptyLines()
{
	for(int i = 0; i < inputData.size(); i++)
	{
		if (isEmptyOrWhiteSpace(inputData[i]))
		{
			inputData.erase(inputData.begin() + i);
			i--;
		}
	}
}

bool AM isEmptyOrWhiteSpace(string &str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			return false;
	}
	return true;
	
}
/*
string AM pullOp(string &str)
{
	string ret(16, '\0');
	stringstream strm(str);
	strm.getline(&ret[0], 16, ' ');
	return ret;
}
*/

void AM map_R_Types()
{
	opcode_mapper	["add"] = bitset<6>(0).to_string();
	func_code_mapper["add"] = bitset<6>(0x20).to_string();

	opcode_mapper	["sub"] = bitset<6>(0).to_string();
	func_code_mapper["sub"] = bitset<6>(0x22).to_string();

	opcode_mapper	["and"] = bitset<6>(0).to_string();
	func_code_mapper["and"] = bitset<6>(0x24).to_string();

	opcode_mapper	["or"]  = bitset<6>(0).to_string();
	func_code_mapper["or"] = bitset<6>(0x25).to_string();

	opcode_mapper	["nor"] = bitset<6>(0).to_string();
	func_code_mapper["nor"] = bitset<6>(0x27).to_string();

	opcode_mapper	["slt"] = bitset<6>(0).to_string();
	func_code_mapper["slt"] = bitset<6>(0x2a).to_string();

	opcode_mapper	["sll"] = bitset<6>(0).to_string();
	func_code_mapper["sll"] = bitset<6>(0x0).to_string();

	opcode_mapper	["srl"] = bitset<6>(0).to_string();
	func_code_mapper["srl"] = bitset<6>(0x2).to_string();

	opcode_mapper	["jr"]  = bitset<6>(0).to_string();
	func_code_mapper["jr"] = bitset<6>(0x8).to_string();
}

void AM map_I_Types()
{
	opcode_mapper	["addi"] = bitset<6>(8).to_string();
	func_code_mapper["addi"] = bitset<6>(0x0).to_string();

	opcode_mapper	["andi"] = bitset<6>(0xc).to_string();
	func_code_mapper["andi"] = bitset<6>(0x0).to_string();

	opcode_mapper	["ori"] = bitset<6>(0xd).to_string();
	func_code_mapper["ori"] = bitset<6>(0x0).to_string();

	opcode_mapper	["beq"] = bitset<6>(4).to_string();
	func_code_mapper["bew"] = bitset<6>(0x0).to_string();
	
	opcode_mapper	["bne"] = bitset<6>(5).to_string();
	func_code_mapper["bne"] = bitset<6>(0x0).to_string();

	opcode_mapper	["lw"] = bitset<6>(0x23).to_string();
	func_code_mapper["lw"] = bitset<6>(0x0).to_string();

	opcode_mapper	["sw"] = bitset<6>(0x2b).to_string();
	func_code_mapper["sw"] = bitset<6>(0x0).to_string();
}


string AM zeros(int numZeros)
{
	string ret = "";
	for(int i = 0; i < numZeros; i++)
		ret += '0';
	return ret;
}

void AM map_J_Types()
{
	opcode_mapper	["j"] = bitset<6>(2).to_string();
	func_code_mapper["j"] = bitset<6>(0x0).to_string();

	opcode_mapper	["jal"] = bitset<6>(3).to_string();
	func_code_mapper["jal"] = bitset<6>(0x0).to_string();
}


void AM map_Registers()
{
	register_mapper["$zero"] = bitset<5>(0).to_string();
	register_mapper["$at"] = bitset<5>(1).to_string();
	register_mapper["$v0"] = bitset<5>(2).to_string();
	register_mapper["$v1"] = bitset<5>(3).to_string();
	register_mapper["$a0"] = bitset<5>(4).to_string();
	register_mapper["$a1"] = bitset<5>(5).to_string();
	register_mapper["$a2"] = bitset<5>(6).to_string();
	register_mapper["$a3"] = bitset<5>(7).to_string();
	register_mapper["$t0"] = bitset<5>(8).to_string();
	register_mapper["$t1"] = bitset<5>(9).to_string();
	register_mapper["$t2"] = bitset<5>(10).to_string();
	register_mapper["$t3"] = bitset<5>(11).to_string();
	register_mapper["$t4"] = bitset<5>(12).to_string();
	register_mapper["$t5"] = bitset<5>(13).to_string();
	register_mapper["$t6"] = bitset<5>(14).to_string();
	register_mapper["$t7"] = bitset<5>(15).to_string();
	register_mapper["$s0"] = bitset<5>(16).to_string();
	register_mapper["$s1"] = bitset<5>(17).to_string();
	register_mapper["$s2"] = bitset<5>(18).to_string();
	register_mapper["$s3"] = bitset<5>(19).to_string();
	register_mapper["$s4"] = bitset<5>(20).to_string();
	register_mapper["$s5"] = bitset<5>(21).to_string();
	register_mapper["$s6"] = bitset<5>(22).to_string();
	register_mapper["$s7"] = bitset<5>(23).to_string();
	register_mapper["$t8"] = bitset<5>(24).to_string();
	register_mapper["$t9"] = bitset<5>(25).to_string();
	register_mapper["$k0"] = bitset<5>(26).to_string();
	register_mapper["$k1"] = bitset<5>(27).to_string();
	register_mapper["$gp"] = bitset<5>(28).to_string();
	register_mapper["$sp"] = bitset<5>(29).to_string();
	register_mapper["$fp"] = bitset<5>(30).to_string();
	register_mapper["$ra"] = bitset<5>(31).to_string();
}

void AM map_Instruction_Types()
{
	instruction_types["add"] = "R";
	instruction_types["sub"] = "R";
	instruction_types["and"] = "R";
	instruction_types["or"] = "R";
	instruction_types["nor"] = "R";
	instruction_types["slt"] = "R";
	instruction_types["sll"] = "R";
	instruction_types["srl"] = "R";
	instruction_types["jr"] = "R";
	instruction_types["addi"] = "I";
	instruction_types["andi"] = "I";
	instruction_types["ori"] = "I";
	instruction_types["beq"] = "I";
	instruction_types["bne"] = "I";
	instruction_types["lw"] = "I";
	instruction_types["sw"] = "I";
	instruction_types["j"] = "J";
	instruction_types["jal"] = "J";
}


