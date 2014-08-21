#pragma once
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <bitset>
#include <iterator>

using std::map;
using std::string;
using std::stringstream;
using std::bitset;



class assembly_mapper
{
public:

	map<string, string> opcode_mapper;
	map<string, string> func_code_mapper;
	map<string, string> register_mapper;
	map<string, string> instruction_types;
	map<string, unsigned int> labels;
	stringstream river;
	vector<string> inputData;
	
	string output;
	


	assembly_mapper(void)
	{
		map_R_Types();

	}

	~assembly_mapper(void)
	{
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

	void translate()
	{
		//clean input data
		stripAllComments();
		stripEmptyLines();
		//get labels
	}
	
	
	
	void storeInstruction(string &instructionLine)
	{
		inputData.push_back(stripComments(instructionLine));
	}
	
	bool value_is_valid_16b(int val)
	{
		unsigned int testVal = val;
		return (testVal <= 0xFFFF); // maximum value to be held in 16 bits
	}

	bool value_is_valid_26b(int val)
	{
		unsigned int testVal = val;
		return (testVal <= 0x3FFFFFF); // maximum value to be held in 26 bits
	}
	string toBinary(int val, int bits)
	{
		return std::to_string(0);
	}

	string stripString(string str, string charsToStrip)
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
	
	void stripAllComments()
	{
		for(int i = 0; i < inputData.size(); i++)
		{
			inputData[i] = stripComments(inputData[i]);
		}
	}
	
	string stripComments(string str)
	{
		return
		str.substr(0, 
				((str.find("#") != std::string::npos) ? 
						str.find("#") : victor[i].size()));
	}
	
	void stripEmptyLines()
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
	
	bool isEmptyOrWhiteSpace(string &str)
	{
		for(int i = 0; i < str.length(); i++)
		{
			if (!isspace(str[i]))
				return false;
		}
		return true;
		
	}


	void map_R_Types()
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

	void map_I_Types()
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

	void map_J_Types()
	{
		opcode_mapper	["j"] = bitset<6>(2).to_string();
		func_code_mapper["j"] = bitset<6>(0x0).to_string();

		opcode_mapper	["jal"] = bitset<6>(3).to_string();
		func_code_mapper["jal"] = bitset<6>(0x0).to_string();
	}

	void map_Registers()
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

	void map_Instruction_Types()
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

};

