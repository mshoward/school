#include <iostream>
#include <string>
#include <sstream>

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


int main()
{
	int inputNum = -1;
	unsigned long long int currSum = 0;
	cin >> inputNum;
	while(inputNum != 0)
	{
		for(int i = 0; i <= inputNum; i++)
		{
			if((i % 3 == 0) || (i % 5 == 0))
			{
				currSum += i;
			}
		}
		cout << currSum << endl;
		currSum = 0;
		cin >> inputNum;
	}
	return 0;
}
