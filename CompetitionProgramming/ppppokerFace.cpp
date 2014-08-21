
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <map>
#include <utility>

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::tolower;
using std::map;
using std::pair;
using std::make_pair;

map<pair<int,int>, int> GCD;
map<int, int> PHI;


int min(int a, int b)
{
	if (a < b)
	return a;
	return b;
}

int gcd(int a, int b)
{
	if (GCD.count(make_pair(a,b)) > 0)
	{
		return GCD[make_pair(a,b)];
	}
	else
	{
		int temp = 1;
		int curr = 1;
		while (curr <= min(a, b))
		{
			if ((a % curr == 0) && (b % curr == 0))
				temp = curr;
			curr++;
		}
		//cout << "GCD(" << a << ", " << b << ") = " << temp << endl;  
		GCD[make_pair(a,b)] = temp;
		GCD[make_pair(b,a)] = temp;
		return temp;
	}
}

bool relativelyPrime(int a, int b)
{
	return (gcd(a, b) == 1);
}

int phi(int n)
{
	if (PHI.count(n) > 0)
	{
		return PHI[n];
	}
	else
	{
		int ret = 1;
		for(int curr = 1; curr < n; curr++)
		{
			if (relativelyPrime(curr, n))
				ret++;
		}
		//cout << "phi(" << n << ") = " << ret << endl;
		PHI[n] = ret;
		return ret;
	}
}

double n_Over_Phi_n(int n)
{
	return ((double)n) / ((double)phi(n));
}

int find_least_n(int a, int b)
{
	int ret = b;
	double currMax = 0;
	double temp;
	for(int traverse = b; traverse >=a; traverse--)
	{
		temp = n_Over_Phi_n(traverse);
		//cout << traverse << " traverse" << endl;
		//cout << temp << " temp" << endl;
		if (currMax <= temp)
		{
			//cout << "TRIPPED" << endl;
			ret = traverse;
			currMax = temp;
		}
	}
	return ret;
}





int main()
{
	int A, B;
	while(cin.good())
	{
		cin >> A;
		cin >> B;
		cout << find_least_n(A, B) << endl;
	}
	
	return 0;
}

