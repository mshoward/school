// mips-assembler.cpp : Defines the entry point for the console application.
//

#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <bitset>
#include <iterator>
#define AM 

using std::vector;
using std::string;
using std::stringstream;
using std::cin;
using std::getline;
using std::endl;
using std::cout;
using std::bitset;
using std::iterator;

bool isEmptyOrWhiteSpace(string &str);

void stripEmptyLines(vector<string> &vect)
{
	for(int i = 0; i < vect.size(); i++)
	{
		if (isEmptyOrWhiteSpace(vect[i]))
		{
			vect.erase(vect.begin() + i);
			i--;
		}
	}
}

bool isEmptyOrWhiteSpace(string &str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			return false;
	}
	return true;
	
}

int indexOfLabel(string &str)
{
	int ret = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == ':')
		{
			return i;
		}
	}
	return -1;
}

string AM pullOp(string &str)
{
	string ret(16, '\0');
	stringstream strm(str);
	strm.getline(&ret[0], 16, ' ');
	return ret;
}

string pullLabel(int index, string &str)
{
	if (index >=0)
		return str.substr(0,index);
	else
		return str;
}

string remainingString(int index_of_colon, string &str)
{
	if (index_of_colon >= 0)
		return str.substr(index_of_colon + 1, str.size());
	else
		return str;
}

void changeString(string &str)
{
	str = "this is the changed string";
	
}
string AM getWord(string &str)
{
	string ret = "";
	bool wordStarted = false;
	bool wordStopped = false;
	int index_of_space = -1;
	int i;
	//get the first word. dont return commas.
	for(i = 0; (i < str.length()) && !wordStopped; i++)
	{
		if ((!isspace(str[i])) && !wordStarted)
		{
			wordStarted = true;
		}
		if(wordStarted)
		{
			if(!isspace(str[i]))
			{
				if(str[i] != ',') //don't do commas ---- no reason for them
				ret += str[i];
			}
			else
			{
				index_of_space = i;
				str = str.substr(i+1, str.length());
				wordStopped = true;
				return ret;
			}
		}
	}
	if (i == str.length())
	str = "";
	return ret;
}
template <typename T>
T StringToNumber ( const string &Text )
{
	stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

int main()
{
	
	string input;
	vector<string> victor;
	
	while(!cin.eof())
	{
		getline(cin, input);
		victor.push_back(input);
		//cout << input << endl;
		cout << StringToNumber<int>(input) << endl;
		input.clear();
	}
	string temp;
	stripEmptyLines(victor);
	for(int i = 0; i < victor.size(); i++)
	{
		temp = victor[i];
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
		cout << "\"" << getWord(temp) << "\"" << endl;
	}
	cout << bitset<8>(1300) << endl;
	
	return 0;
}

