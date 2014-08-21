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

struct char_pair
{
	char A;
	char B;
	bool isEqual(char_pair C)
	{
		return
		(
			((A == C.A) && (B == C.B)) ||
			((B == C.A) && (A == C.B))
		);
	}
};



class char_pairs
{
	public:
	vector<char_pair> pairs;
	char_pairs()
	{
	}
	~char_pairs(){}
	void add(char A, char B)
	{
		char_pair adding;
		adding.A = tolower(A);
		adding.B = tolower(B);
		bool has = false;
		for(int i = 0; i < pairs.size(); i++)
		{
			has = has || pairs[i].isEqual(adding);
		}
		if (!has) pairs.push_back(adding);
	}
	int count() { return pairs.size(); }
	void clear()
	{
		pairs.clear();
	}
};



int main()
{
	char_pairs my_list;
	string inputData;
	while(cin.good())
	{
		getline(cin, inputData);
		if (cin.good())
		{
			for(int i = 1; i < inputData.length(); i++)
			{
				if (isalpha(inputData[i]) && isalpha(inputData[i - 1]))
				{
					my_list.add(inputData[i], inputData[i - 1]);
				}
			}
			cout << my_list.count() << endl;
			my_list.clear();
			inputData.clear();
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
