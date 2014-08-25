#pragma once

class token
{
	std::string val;
	int token_class;
	int token_subs;
};

class lex
{
	std::vector<token> token_list;
};
