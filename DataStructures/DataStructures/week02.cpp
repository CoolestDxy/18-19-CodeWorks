//week02.cpp
//Page:093
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

struct Item;

void P093N02();
int P093N02_Cal();
void P093N06();
long P093N06_Cal(std::vector<Item>,int);
void P093N02()
{
	int result = P093N02_Cal();

	switch (result)
	{
	case -1:
		std::cout << "a<b\n";
		break;
	case 0:
		std::cout << "a=b\n";
		break;
	case 1:
		std::cout << "a>b\n";
		break;
	default:
		std::cout << "Not define\n";
		break;
	}
}
int P093N02_Cal()
{
	using std::vector;
	vector<int>a = { 1,3,5,7,11,13,17 };
	vector<int>b = { 1,6,7,8,12,15 };

	bool flag = false;
	bool Lflag = true;
	bool Rflag = true;

	for (int i = 0; i < a.size() && i < b.size(); i++)
	{
		if (a[i] == b[i])
		{
			flag = true;
		}
		if (flag && a[i] > b[i])
		{
			Lflag = false;
		}
		else if (flag && a[i] < b[i])
		{
			Rflag = false;
		}
	}
	if (!flag)
	{
		return 0;
	}
	else if (flag)
	{
		if (Lflag)
		{
			return -1;
		}
		else if (Rflag)
		{
			return 1;
		}
		else
		{
			if (a.size() == b.size())
			{
				return 0;
			}
			else if (a.size() > b.size())
			{
				return 1;
			}
			else if (a.size() < b.size())
			{
				return -1;
			}
		}
	}
}

struct Item
{
	int power;
	int cow;
};
void P093N06()
{
	std::vector<Item> pol{ {0,1} ,{1,5},{2,6},{9,7} };
	int x = 2;
	std::cout << P093N06_Cal(pol,x);
}
long P093N06_Cal(std::vector<Item> pol, int x)
{
	long result{ 0 };
	for (int i = 0; i < pol.size(); i++)
	{
		result += pol[i].cow*pow(x, pol[i].power);
	}
	return result;
}
