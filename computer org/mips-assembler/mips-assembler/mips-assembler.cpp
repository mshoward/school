// mips-assembler.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "assembly_mapper.hpp"
#include "assembly_mapper.cpp"

using std::string;
using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::fstream;

int main()
{
	assembly_mapper mapper;
	string filepath;
	string outputFilePath;
	char reply = '\0';
	fstream programStream;
	fstream outputStream;
	
	cout << "Enter filepath:" << endl;
	cin >> filepath;
	programStream.open(filepath.c_str(), std::ios::in);
	
	//read program
	cout << "Reading program...";
	cout.flush();
	mapper.read(programStream);
	cout << " done!" << endl;
	cout << "Validating program...";
	cout.flush();
	if (!mapper.validate())
	{
		cout << " broke on line: " << instruction_no << endl;
	}
	else
	{
		cout << " done!" << endl;
		cout << "Output to a file? (y / N) ";
		cout.flush();
		cin >> reply;
		if (reply == 'y')
		{
			cout << "Enter output filepath: " << endl;
			cin >> outputFilePath;
			outputStream.open(ouputFilePath.c_str(), std::ios::out);
			for(int i = 0; i < mapper.outputData.size(); i++)
				outputStream << mapper.outputData[i] << endl;
		}
		else
		{
			for(int i = 0; i < mapper.outputData.size(); i++)
				cout << mapper.outputData[i] << endl;
		}
	}
	return 0;
}

