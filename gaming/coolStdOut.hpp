#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>










using std::srand;
using std::rand;
using std::time;
using std::cin;
using std::cout;
using std::endl;
using std::string;




class coolStdOut
{
private:
	
	int gen(int min, int max)
	{
		return (rand() % (max - min)) + min;
	}
	
	
	string randString(int len)
	{
		string ret = "";
		
		
		for(int i = 0; i < len; i++)
		{
			ret += (char)gen(32,126);
		}
		return ret;
	}
	
	
	
public:
	coolStdOut()
	{
		srand(time(0));
		dura = std::chrono::milliseconds(32);
	}
	std::chrono::milliseconds dura;
	void prnt(std::string &str)
	{
		std::string out;
		for(int i = 0; i < str.length() + 1; i++)
		{
			cout << '\r';
			cout.flush();
			out = str.substr(0, i) + randString(str.length()).substr(i, str.length());
			cout << out;
			cout.flush();
			std::this_thread::sleep_for(dura);
		}
	}
	void prntln(std::string &str)
	{
		prnt(str);
		cout << endl;
	}
};

