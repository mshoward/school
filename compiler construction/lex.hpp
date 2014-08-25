#pragma once


using std::string;
using std::fstream;
using std::vector;

class token
{
public:
	std::string val;
	int token_class;
	int token_subscript;
	
	token();
	~token();
	
};

class lex
{
public:
	//fundamental data types
	char curr_char;
	unsigned int current_token;
	
	//stl data structs
	std::fstream file_stream;
	std::vector<token> token_list;
	std::vector<token> id_table;
	//custom data structs
	token curr_token;
	
	//constructor
	lex();
	~lex();
	
	
	bool isDelimiter(char c); 
	bool isDelimiter(token c);
	
	bool isConstant(token c);
	bool isKeyWord(char c);
	bool isKeyWord(token c);
};
