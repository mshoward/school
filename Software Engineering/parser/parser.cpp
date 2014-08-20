#include "parser-includes.hpp"

using namespace parser_sqli;

int main()
{
	std::string buf;
	
	std::cout << "hello world" << std::endl;
	for (int i = 0; i < SQLI_LIST_LENGTH; i++)
	{
		std::cout << SQLI_LIST[i] << std::endl;
	}
	std::fstream f1("logfile.txt", std::ios::in);
	while (!(f1.eof()))
	{
		std::getline(f1, buf, ' ');
		std::cout << buf << std::endl;
	}
	f1.close();
	std::cout << std::endl;
return 0;
}