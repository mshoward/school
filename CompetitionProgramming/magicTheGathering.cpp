#include <iostream>
#include <string>
#include <sstream>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::stringstream;
using std::endl;
using std::getline;
using std::map;

template <typename T>
T StringToNumber ( const string &Text )
{
	stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}


string getWord(string &str)
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

map<char, int> M;
int totalMana;
map<char, char>LTM;
map<char, int> L;

string canCast(string &cost)
{
	//{no Color restriction cost} + {color restricted costs}
	string ret = "YES ";
	return ret;
}

void initScript()
{
	LTM['P'] = 'W';
	LTM['I'] = 'U';
	LTM['S'] = 'B';
	LTM['M'] = 'R';
	LTM['F'] = 'G';
	totalMana = 0;
}

void clearMap()
{
	totalMana = 0;
	/*
	 * W  U  B  R  G 
	 * P  I  S  M  F
	 */
	 M['W'] = 0;
	 M['U'] = 0;
	 M['B'] = 0;
	 M['R'] = 0;
	 M['G'] = 0;
	 
	 L['P'] = 0;
	 L['I'] = 0;
	 L['S'] = 0;
	 L['M'] = 0;
	 L['F'] = 0;
}
void fillMap(string &str)
{
	for(int i = 0; i < str.length(); i++)
	{
		M[LTM[str[i]]] += 1;
		totalMana++;
	}
}


int main()
{
	string lands;
	initScript();
	string spells;
	string inputData;
	while (!cin.eof())
	{
		//get input
		//cin >> inputData;
		lands = getWord(inputData);
		fillMap(lands);
		
		//perform processing
		
		//output
		if(!cin.eof())
		{
			cin >> spells;
			cout << StringToNumber<int>(spells) << endl;
		}
	}
	return 0;
}
