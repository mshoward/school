// ppppokerface.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::getline;


map<char, int> cardVals;
map<int, char> backwards;

void mapVals()
{
	cardVals['2'] = 2;
	cardVals['3'] = 3;
	cardVals['4'] = 4;
	cardVals['5'] = 5;
	cardVals['6'] = 6;
	cardVals['7'] = 7;
	cardVals['8'] = 8;
	cardVals['9'] = 9;
	cardVals['T'] = 10;
	cardVals['J'] = 11;
	cardVals['Q'] = 12;
	cardVals['K'] = 13;
	cardVals['A'] = 14;
	backwards[2] = '2';
	backwards[3] = '3';
	backwards[4] = '4';
	backwards[5] = '5';
	backwards[6] = '6';
	backwards[7] = '7';
	backwards[8] = '8';
	backwards[9] = '9';
	backwards[10] = 'T';
	backwards[11] = 'J';
	backwards[12] = 'Q';
	backwards[13] = 'K';
	backwards[14] = 'A';
}


struct card
{
	int val;
	char suit;
	void assign(card a)
	{
		val = a.val;
		suit = a.suit;
	}
};

struct hand
{
	card cards[5];
	void assign(hand a)
	{
		for(int i = 0; i < 5; i++)
		{
			cards[i].assign(a.cards[i]);
		}
	}
}pokerHand;

void sortHand()
{
	card temp;
	hand retHand;
	retHand.assign(pokerHand);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 1; j < 5; j++)
		{
			if (retHand.cards[j - 1].val > retHand.cards[j].val)
			{
				temp.assign(retHand.cards[j - 1]);
				retHand.cards[j - 1].assign(retHand.cards[j]);
				retHand.cards[j].assign(temp);
			}
		}
	}
	pokerHand.assign(retHand);
}

void print()
{
	for(int i = 0; i < 5; i++)
	{
		cout << backwards[pokerHand.cards[i].val] << pokerHand.cards[i].suit << " ";
	}
	cout << endl;
}


int max(int *vals, int numVals)
{
	int ret = vals[0];
	for (int i = 0; i < numVals; i++)
	{
		if (ret < vals[i])
		{
			//cout << ret << " to ";
			ret = vals[i];
			//cout << ret << endl;
		}
	}
	return ret;
}
bool thereExistsA(int val, int *vals, int numVals)
{
	for(int i = 0; i < numVals; i++)
	{
		if (vals[i] == val)
			return true;
	}
	return false;
}


int pairs[5];
bool pairsRan;

void numPair(hand input)
{
	
	if (!pairsRan)
	{
		for(int i = 0; i < 5; i++)
			pairs[i] = 0;
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				if ((input.cards[i].val == input.cards[j].val) && (i != j))
				{
					pairs[i]++;
				}
			}
		}
		pairsRan = true;
	}
	//for(int i = 0; i < 5; i++)
	//	cout << pairs[i] << " "; cout << endl;
}

bool onePair(hand input)
{
	numPair(input);
	return (max(pairs, 5) == 1);
}
///broken
bool twoPair(hand input)
{
	numPair(input);
	int count = 0;
	for(int i = 0; i < 5; i++)
	{
		if (pairs[i] == 1)
			count++;
	}
	return count == 4;
}
bool threeKind(hand input)
{
	numPair(input);
	//cout << max(pairs, 5) << endl;
	return ((max(pairs, 5) == 2) && (!thereExistsA(1, pairs, 5)));
}
bool fullHouse(hand input)
{
	numPair(input);

	return ((max(pairs, 5) == 2) && (thereExistsA(1, pairs, 5)));
}
bool fourKind(hand input)
{
	numPair(input);
	return (max(pairs, 5) == 3);
}

bool straight(hand input)
{
	for(int i = 1; i < 5; i++)
	{
		if (input.cards[i].val != input.cards[i - 1].val + 1)
			return false;
	}
	return true;
}
bool flush(hand input)
{
	for(int i = 1; i < 5; i++)
	{
		if (input.cards[i].suit != input.cards[i - 1].suit)
			return false;
	}
	return true;
}
bool straightFlush(hand input)
{
	return straight(input) && flush(input);
}
bool royal(hand input)
{
	return input.cards[0].val == 10;
}
bool royalFlush(hand input)
{
	return royal(input) && straightFlush(input);
}

void processInput(string str)
{
	char temp;
	int card = 0;
	
	stringstream strm(str);
	while(strm.good())
	{
		strm >> temp;
		if (isalnum(temp))
		{
			pokerHand.cards[card].val = cardVals[temp];
			strm>> temp;
			pokerHand.cards[card].suit = temp;
			card++;
		}
	}
	sortHand();
	//print();
}





int main()
{
	string inputData;
	mapVals();

	while(!cin.eof())
	{
		getline(cin, inputData);
		if(!cin.eof())
		{
			pairsRan = false;
			processInput(inputData);
			if (royalFlush(pokerHand))
			{
				cout << "ROYAL FLUSH" << endl;
			}
			else if (straightFlush(pokerHand))
				cout << "STRAIGHT FLUSH" << endl;
			else if (fourKind(pokerHand))
				cout << "FOUR OF A KIND" << endl;
			else if (fullHouse(pokerHand))
				cout << "FULL HOUSE" << endl;
			else if (flush(pokerHand))
				cout << "FLUSH" << endl;
			else if (straight(pokerHand))
				cout << "STRAIGHT" << endl;
			else if (threeKind(pokerHand))
				cout << "THREE OF A KIND" << endl;
			else if (twoPair(pokerHand))
				cout << "TWO PAIR" << endl;
			else if (onePair(pokerHand))
				cout << "ONE PAIR" << endl;
			else
				cout << "NOTHING" << endl;
		}
	}
	return 0;
}
