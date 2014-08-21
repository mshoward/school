/*
 * 
 * Your professor has given the statistics for the last exam. 
 * He has told the class how many of each letter grade were made. 
 * You would like to know the range in which the class average could 
 * fall. The grade ranges are the traditional grade ranges: 
 * (A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: 0-59). 
 * You may assume that all grades are integral.
 * 
 * Your task is, given the number of A's, B's, C's, D's, and F's 
 * made by the members of the class, determine the minimum and maximum
 * values for the class average. 
 * Compute this value to two decimal places.
 * 
 * The input file consists of multiple test cases. Each test case 
 * consists of a single line containing 5 space-separated integers. 
 * These are, in order, the number of A's, the number of B's, the 
 * number of C's, the number of D's, and the number of F's received on 
 * the exam for this test case. Each of these values will be in the 
 * range 0-10000, and there will be at least one value greater than 
 * zero. Input will be terminated by end of file (that is, reading 
 * more input should give you null)
 * 
 * For each test case, output the minimum and maximum possible class 
 * averages given the grade distribution, as formatted below. Each 
 * value should be output to two decimal places.
 */


#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using std::stringstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class gradeSet
{
	public:
	int bins[5];
	gradeSet()
	{
		for(int i = 0; i < 5; i++) bins[i] = 0;
	}
	~gradeSet(){}
	void clear() {for(int i = 0; i < 5; i++) bins[i] = 0;}
	void set(string &grades)
	{
		stringstream strm(grades);
		for(int i = 0; i < 5; i++)
		{
			strm >> bins[i];
		}
	}
	double min()
	{
		double total = 0;
		int numGrades = 0;
		for(int i = 0; i < 5; i++)
		{
			total += (bins[i] * getMin(i));
			numGrades += bins[i];
		}
		
		return total / (double)numGrades;
	}
	double max()
	{
		double total = 0;
		int numGrades = 0;
		for(int i = 0; i < 5; i++)
		{
			total += bins[i] * getMax(i);
			numGrades += bins[i];
		}
		return total / (double)numGrades;
	}
	
	double getMin(int index)
	{
		switch(index)
		{
			case 0://a
			return 90;
			break;
			case 1://b
			return 80;
			break;
			case 2://c
			return 70;
			break;
			case 3://d
			return 60;
			break;
			case 4://f
			return 0;
			break;
			default:
			return 0;
			break;
		}
		return 0;
	}
	
	double getMax(int index)
	{
		switch(index)
		{
			case 0://a
			return 100;
			break;
			case 1://b
			return 89;
			break;
			case 2://c
			return 79;
			break;
			case 3://d
			return 69;
			break;
			case 4://f
			return 59;
			break;
			default:
			return 59;
			break;
		}
		return 0;
	}
};

double round_two_places(double x)
{
	long long int temp = x * 100;
	long double temp2 = x * 100;
	double rem = temp2 - temp;
	if (rem >= 0.5)
		temp += 1;
	return (double)temp / 100;
}

int main()
{
	string inputData;
	gradeSet worker;
	double min, max;
	bool should_output = true;
	
	while(!cin.eof())
	{
		getline(cin, inputData);
		worker.set(inputData);
		min = worker.min();
		max = worker.max();
		if (!cin.eof())
		{
			cout << std::fixed << std::setprecision(2) << "Min: " << round_two_places(min) << ", " <<
				"Max: " << round_two_places(max) << endl;
		}
	}
	return 0;
}

