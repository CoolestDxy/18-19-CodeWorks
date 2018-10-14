//week04.cpp
/*
	模拟随机行走
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
//Para limits
//#define MIN_N 2
//#define MAX_N 40
//#define MIN_M 2
//#define MAX_M 20

#define M 15
#define N 15
#define INIT_M 9
#define INIT_N 9

struct Bug
{
	int i;
	int j;
};
inline int * avliableList(Bug me,int * res)
{
	switch (me.i)
	{
	case 0:
		switch (me.j)
		{
		case 0:
			//int * res = new int[4];
			res[0] = 3;	//Total
			res[1] = 1;res[2] = 2;res[3] = 3;
			return res;
			break;
		case N:
			//int * res = new int[4];
			res[0] = 3;	//Total
			res[1] = 3; res[2] = 4; res[3] = 5;
			return res;
			break;
		default:
			//int * res = new int[6];
			res[0] = 5;	//Total
			res[1] = 1; res[2] = 2; res[3] = 3; res[4] = 4; res[5] = 5;
			return res;
			break;
		}
		break;
	case M:
		switch (me.j)
		{
		case 0:
			//int * res = new int[4];
			res[0] = 3;	//Total
			res[1] = 0; res[2] = 1; res[3] = 7;
			return res;
			break;
		case N:
			//int * res = new int[4];
			res[0] = 3;	//Total
			res[1] = 5; res[2] = 6; res[3] = 7;
			return res;
			break;
		default:
			//int * res = new int[6];
			res[0] = 5;	//Total
			res[1] = 0; res[2] = 1; res[3] = 5; res[4] = 6; res[5] = 7;
			return res;
			break;
		}
		break;
	default:
		switch (me.j)
		{
		case 0:
			//int * res = new int[6];
			res[0] = 5;	//Total
			res[1] = 0; res[2] = 1; res[3] = 2; res[4] = 3; res[5] = 7;
			return res;
			break;
		case N:
			//int * res = new int[6];
			res[0] = 5;	//Total
			res[1] = 3; res[2] = 4; res[3] = 5; res[4] = 6; res[5] = 7;
			return res;
			break;
		default:
			//int * res = new int[9];
			res[0] = 8;	//Total
			res[1] = 1; res[2] = 2; res[3] = 3; res[4] = 4; res[5] = 5; res[6] = 6; res[7] = 7;
			return res;
			break;
		}
		break;
	}
}
void P123N08()
{
	srand(time(0));
	int matrix[M][N] = { 0 };
	int overRide = 1;
	int * res;
	int * resList;
	int stepCode;
	const int imove[8] = { -1,0,1,1,1,0,-1,-1 };
	const int jmove[8] = { 1,1,1,0,-1,-1,-1,0 };
	Bug bug{ INIT_M,INIT_N };
	++matrix[INIT_M][INIT_N];
	std::cout << "Searching started" << std::endl;
	while (overRide < M*N)
	{
		resList = avliableList(bug,res);
		stepCode = resList[rand() % resList[0] + 1];
		bug.i += imove[stepCode]; bug.j += jmove[stepCode];
		++matrix[bug.i][bug.j];
		matrix[bug.i][bug.j] == 1 ? ++overRide:NULL;
	}
}