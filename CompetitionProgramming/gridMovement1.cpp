#include <iostream>
#include <string>
#include <sstream>

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


enum DIRECTION {UPPER_LEFT, UP, UPPER_RIGHT, LEFT, RIGHT, BOTTOM_LEFT,
				BOTTOM, BOTTOM_RIGHT};

#define NUM_NEIGHBORS 8

class gridNode
{
public:
	int val;
	gridNode **neighbors;
	gridNode()
	{
		neighbors = new gridNode*[NUM_NEIGHBORS];
		for(int i = 0; i < NUM_NEIGHBORS; i++)
		{
			neighbors[i] = NULL;
		}
	}
	gridNode(int _val)
	{
		val = _val;
		neighbors = new gridNode*[NUM_NEIGHBORS];
	}
	
};

int shortestPath(int ** grid, int BoundX, int BoundY, int Sum)
{
	if ((BoundX == 0) && (BoundY == 0))
	{
		return Sum;
	}
	else
	{
		if ((BoundX > 0) && (BoundY > 0))
		{
			if ((grid[BoundY][BoundX - 1] > grid[BoundY - 1][BoundX]))
			{
				Sum += grid[BoundY - 1][BoundX];
				BoundY--;
				return shortestPath(grid, BoundX, BoundY, Sum);
			}
			else
			{
				Sum += grid[BoundY][BoundX - 1];
				BoundX--;
				return shortestPath(grid, BoundX, BoundY, Sum);
			}
		}
		else
		{
			if (BoundX > 0)
			{
				Sum += grid[BoundY][BoundX - 1];
				BoundX--;
				return shortestPath(grid, BoundX, BoundY, Sum);
			}
			else
			{
				Sum += grid[BoundY - 1][BoundX];
				BoundY--;
				return shortestPath(grid, BoundX, BoundY, Sum);
			}
		}
	}
}



int main()
{
	//get input
	int R, C;
	int ** grid;
	
	cin >> R;
	cin >> C;
	int RCONST = R;
	int CCONST = C;
	//get grid mem
	
	// have input
	// do things
	int temp;
	int currR = 0;
	int currC = 0;
	int revR = R - 1;
	int revC = C - 1;
	
	
	while(R != 0)
	{
		grid = new int*[R];
		for(int i = 0; i < R; i++)
		{
			grid[i] = new int[C];
		}
		//get grid numbers
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				cin >> grid[i][j];
			}
		}
		cout << shortestPath(grid, C - 1, R - 1, grid[R - 1][C - 1]) << endl;
		for(int i = 0; i < R; i++)
			delete grid[i];
		delete grid;
		cin >> R;
		cin >> C;
	}
	
	return 0;
}

