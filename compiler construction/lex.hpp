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
	
	token(); //check
	~token(); //check
	void push(char c) //check
	{
		val += c;
	}
};



class lex
{
public:
	//fundamental data types
	char curr_char;
	unsigned int current_token;
	enum curr_tok_state {ALL_NUMBERS = 0, MIXED};
	curr_tok_state curr_state;
	bool CT_should_be_pushed;
	
	//stl data structs
	std::fstream file_stream;
	std::fstream file_stream_out;
	
	std::vector<token> token_list;
	std::vector<token> id_table;
	
	std::vector<std::string> inputData;
	std::vector<std::string> outputData;
	
	//custom data structs
	token curr_token;
	
	/** Methods */
	
	//constructor
	lex();
	~lex();
	
	bool setFileIn(std::string filename);
	bool setFileOut(std::string filename);
	
	void readFile();
	void tokenizeFile();
	void printFile();
	
	bool isDelimiter(char c); 
	bool isDelimiter(token c);
	
	bool isConstant(token c);
	bool isKeyWord(char c);
	bool isKeyWord(token c);
};



