#include "parser-includes.hpp"

using namespace parser_sqli;
//demo
int main()
{
	std::string buf;
	int n;
	std::cout << "hello world" << std::endl;
	for (int i = 0; i < SQLI_LIST_LENGTH; i++)
	{
		std::cout << SQLI_LIST[i] << std::endl;
	}
	std::fstream f1("samples/logfile.txt", std::ios::in);
	HoneyDLogStatement stmt;
	int counter = 0;
	while (!(f1.eof()))
	{
		std::getline(f1, buf);
		stmt.populateFields(buf);
		
		std::cout << std::endl << "Entry Number: " << counter << std::endl;
		std::cout << stmt.timeStamp << std::endl;
		std::cout << stmt.packetType << std::endl;
		std::cout << stmt.sourceIP << std::endl;
		std::cout << stmt.sourceSocket << std::endl;
		std::cout << stmt.targetIP << std::endl;
		std::cout << stmt.targetSocket << std::endl;
		std::cout << stmt.osVersion << std::endl;
		//std::cout << counter << std::endl;
		counter++;
		std::cin >> n;
	}
	f1.close();
	std::cout << std::endl;
return 0;
}
