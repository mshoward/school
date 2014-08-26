#pragma once


using std::string;
using std::fstream;
using std::vector;

token::token()
{
	val = "";
	token_class = 0;
	token_subscript = 0;
}

token::~token()
{
	val.clear();
}

lex::lex()
{
	//fund
	curr_char = 0;
	current_token = 0;
	curr_state = ALL_NUMBERS;
	CT_should_be_pushed = false;
	
	//stl
	//nothing to do
	
	//custom
	//nothing to do
}

lex::~lex()
{
	file_stream.sync();
	file_stream.flush();
	file_stream.close();
	file_stream_out.flush();
	file_stream_out.close();
	token_list.clear();
	id_table.clear();
}

bool lex::isDelimiter(char c)
{
	
}

bool lex::isDelimiter(token c)
{
}

bool lex::isConstant(token c);
{
}

bool lex::isKeyWord(char c)
{
	return
	(
		(c == ';') ||
		(c == ',') ||
		(c == '+') ||
		(c == '*') ||
		(c == '-') ||
		(c == '/') ||
		(c == ':')
	);
}

bool lex::isKeyWord(token c)
{
}



