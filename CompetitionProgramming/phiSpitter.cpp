
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

int min(int a, int b)
{
	if (a < b)
	return a;
	return b;
}

int gcd(int a, int b)
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
	return temp;
}

bool relativelyPrime(int a, int b)
{
	return (gcd(a, b) == 1);
}

int phi(int n)
{
	int ret = 1;
	for(int curr = 1; curr < n; curr++)
	{
		if (relativelyPrime(curr, n))
			ret++;
	}
	//cout << "phi(" << n << ") = " << ret << endl;
	return ret;
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
	A = 1;
	B = 250000;
	int curr = 1;
	cout << "int phiFunc[250001] = [" << endl;
	
	for(curr = 1; curr <= B; curr++)
	{
		cout <<
	}
	
	return 0;
}

