#include "includes.hpp"

using std::cin;
using std::cout;
using std::endl;
int main(int agrc, char *argv[])
{
	lex lexer;
	std::string inFile, outFile;
	if(argc > 2)
	{
		inFile = argv[1];
		outFile = argv[2];
	}
	else
	{
		cout << "Please enter the input file: " << endl;
		cin >> inFile;
		cout << "Please enter the output file: " << endl;
		cin >> outFile;
	}
	
	if(lexer.setFileIn(inFile) && lexer.setFileOut(outFile))
	{
		cout << "Reading... ";
		cout.flush();
		lexer.readFile();
		lexer.tokenizeFile();
		lexer.printFile();
		cout << "Complete!" << endl;
	}
	else
	{
		cout << "I/O Error" << endl;
		
	}
	return 0;
}
