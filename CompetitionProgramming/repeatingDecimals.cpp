#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::tolower;


typedef unsigned long long int ulli;
int spit = 0;

struct repeatingDecimal
{
	string fixed;
	ulli upper;
	ulli lower;
	ulli fixedTens;
	ulli fixedPart;
	string repeating;
	string nines;
	
	ulli gcd(ulli x, ulli y)
	{
		if (y == 0)
			return x;
		return gcd(y, x % y);
	}
	
	void put(string str)
	{
		fixed.clear();
		repeating.clear();
		nines.clear();
		fixedTens = 0;
		int i;
		fixed = "";
		for(i = 0; str[i] != '.'; i++);
		for(i = i; str[i] != ' '; i++)
		{
			fixed += str[i];
			//fixedTens++;
		}
		if (fixed != "")
		{
			stringstream strm(fixed)
		}
		for(i = i + 1; i < str.length(); i++)
		{
			repeating += str[i];
			nines += '9';
		}
		fixedTens = fixed.length();
		nines += '\0';
		repeating += '\0';
		//fixed += '\0';
		
		cout << "repeating: " << repeating << endl;
		cout << "nines: " << nines << endl;
		cout << "fixed: " << fixed << endl;
		
		
	}
	
	string get(string str)
	{
		put(str);
		stringstream strm(repeating);
		strm >> upper;
		strm.str(nines);
		strm >> lower;
		strm.str(fixed);
		strm >> fixedPart;
		cout << "upper: " << upper << endl;
		cout << "lower: " << lower << endl;
		cout << "fixedPart: " << fixedPart << endl;
		cout << "fixedTens: " << fixedTens << endl;
		ulli div = gcd(lower, upper);
		lower = lower / div;
		upper = upper / div;
		cout << "spit: " << spit++ << endl;
		cout << upper << "/" << lower << endl;
		ulli fpart;
		ulli ipart;
		ulli tens = 1; 
		for(int j = fixedTens; j > 0; j++)
			tens = tens * 10;
		ipart = fixedPart;
		cout << "spit: " << spit++ << endl;
		cout << tens << ": tens\nipart: " << ipart << endl;
		// fixed part to add
		// is ipart over tens
		/*
		 * a/b + c/d = ad/bd + cb/bd
		 */
		ipart = ipart * lower;
		tens = tens * lower;
		upper = upper * tens;
		lower = lower * tens;
		upper = upper + ipart;
		cout << "spit 2" << endl;
		cout << upper << "/" << lower << endl;
		div = gcd(lower, upper);
		lower = lower / div;
		upper = upper / div;
		string ret = "";
		strm.str(ret);
		strm << upper << "/" << lower;
		strm.flush();
		cout << ret;
		cout.flush();
		return ret;
	}
	
	
};

int main()
{
	repeatingDecimal rep;
	string inputData;
	while(!cin.eof())
	{
		getline(cin, inputData);
		if(!cin.eof())
		cout << rep.get(inputData) << endl;
		inputData.clear();
	}
	
	return 0;
}

