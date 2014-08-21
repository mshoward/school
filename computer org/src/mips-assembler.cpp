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
using std::stringstream;



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
	mapper.readf(programStream);
	cout << " done!" << endl;
	cout << "Validating program...";
	cout.flush();
	if (!mapper.validate())
	{
		cout << " broke on line: " << mapper.instruction_no + 1 << endl;
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
			outputStream.open(outputFilePath.c_str(), std::ios::out);
			for(int i = 0; i < mapper.outputData.size(); i++)
				outputStream << mapper.outputData[i] << endl;
		}
		else
		{
			for(int i = 0; i < mapper.outputData.size(); i++)
				cout << mapper.outputData[i] << endl;
		}
		//cout << mapper.step << endl;
		//for(int i = 0; i < mapper.inputData.size(); i++)
		//	cout << mapper.inputData[i] << endl;
	}
	
	//cout << mapper.step << endl;
	return 0;
}

