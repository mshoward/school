#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "coolStdOut.hpp"







int main(int argc, char ** argv)
{
	coolStdOut outputter;
	std::string inp;
	while(getline(cin, inp))
	{
		outputter.prntln(inp);
	}
	return 0;
}
