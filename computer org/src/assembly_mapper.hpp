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

using std::map;
using std::string;
using std::stringstream;
using std::vector;
using std::bitset;
using std::fstream;
using std::cin;
using std::cout;
using std::endl;



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
	vector<string> outputData;
	int step;
	unsigned int instruction_no;
	string output;
	


	assembly_mapper(void);
	~assembly_mapper(void);
	
	//CHECK
	void init_this();
	//TODO
	string translate(string &instr); //translates instr into machine language, outputs it
	//CHECK
	void storeInstruction(string &instructionLine);
	//
	void stripAllComments();
	//
	void stripEmptyLines();
	//
	void getLabels();
	//CHECK
	void readf(fstream &sourceCode);
	//TODO
	bool validate();
	
	//
	void map_R_Types();
	//
	void map_I_Types();
	//
	void map_J_Types();
	//
	void map_Registers();
	//
	void map_Instruction_Types();
	//CHECK
	int indexOfLabel(string &str);
	//CHECK
	string remainingString(int index, string &str);
	void replaceAllCommasWithSpaces();
	
	
	//
	bool value_is_valid_16b(int val);
	//
	bool value_is_valid_26b(int val);
	//
	bool isEmptyOrWhiteSpace(string &str);
	//
	bool mapNextLabel(); //returns true if it mapped a label, also removes the label/labelLine from the input data
	
	
	//
	string toBinary(int val, int bits);
	//
	string stripString(string str, string charsToStrip);
	//
	string stripComments(string str);
	//
	string pullLabel(int index, string &str);
	//
	string zeros(int numZeros);
	string getWord(string &str); //danger danger this modifies the passed string
	/*
	string pullOp(string &str);
	string pull_Rd(string &opc, string &str);
	string pull_Rs(string &opc, string &str);
	string pull_Rt(string &opc, string &str);
	string pull_shamt(string &opc, string &str);
	string pull_imm(string &opc, string &str);
	string pull_offset(string &opc, string &str);
	string pull_target(string &opc, string &str);
	*/
	
	template <typename T>
	T StringToNumber ( const string &Text )
	{
		stringstream ss(Text);
		T result;
		return ss >> result ? result : 0;
	}

};


