#include <iostream>
#include <string>
#include <sstream>

struct CoinSystem
{
	int values[20];
	int timesUsed[20];
} coins;

void CoinsInit()
{
	for(int i = 0; i < 20; i++)
	{
		coins.values[i] = -1;
		coins.timesUsed[i] = 0;
	}
}

void putCoinsIntoCoinSystem(stringstream &inputs)
{
	for(int i = 0; (i < 20) && inputs.good(); i++)
	{
		inputs >> coins.values[i];
	}
}

int getLargestNotOver(int num)
{
	for(int i = 19; i >= 0; i++)
	{
		if ((coins.values[i] < num) && (coins.values[i] != -1))
			return coins.values[i];
	}
	return 0;
}


//returns count of coins found using greedy alg
int greedyCoins(int val)
{
	//greedy algorithm
	int retVal = 0;
	int currVal = 0;
	int workingVal = val;
	while(currVal != retVal)
	{
		currVal += getLargestNotOver(workingVal);
		workingVal -= getLargestNotOver(workingVal);
		retVal++;
	}
	return retVal;
}


//returns count of coins found using brute force
int bruteForce(int val)
{
	int bestCount = -1;
	int workingCount = -1;
	int workingVal = val;
	int currVal = 0;
	
	//for(int i = 0; (i < 20) &&	
	
}




using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


int main()
{
	CoinsInit();
	string inputData;
	stringstream inputStream;
	getline(cin, inputData);
	while(inputData!= "0")
	{
		inputStream.str(inputData);
		putCoinsIntoCoinSystem(&inputStream);
		
		
		
		
		
		
	}
	
	return 0;
}



















