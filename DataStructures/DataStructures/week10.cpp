//week10.cpp
//P31603 Benchmark
#include"public.h"
class Sets
{
public:
	Sets(int element)
	{
		if (element < 2)
		{
			throw "At least 2 elements.";
		}
		n = element;
		parent = new int[n];
		fill(parent, parent + n, -1);
	}
	void simpleUnion(int i, int j)
	{
		parent[i] = j;
	}
	int simpleFind(int i)
	{
		while (parent[i] > 0)
		{
			i = parent[i];
		}
		return i;
	}
	void widgetUnion(int i, int j)
	{
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j])
		{
			parent[i] = i;
			parent[j] = temp;
		}
		else
		{
			parent[j] = i;
			parent[i] = temp;
		}

	}
	int collapsingFind(int i)
	{
		int r;
		for (r = i; parent[r] >= 0; r = parent[r]);
			while (i!=r)
			{
				int s = parent[i];
				parent[i] = r;
				r = s;
			}
		return r;
	}
private:
	int * parent;
	int n;
	void fill(int * start, int* end, int element)
	{
		int * key = start;
		while (key != end)
		{
			*key = element;
			key++;
		}
	}
};
int getRand(int start, int end)
{
	if (start>end||start<0)
	{
		throw "cmp err.";
	}
	return rand() % (end - start + 1) + start;
}
void P316N03()
{
	const int size = 60000;
	srand(time(0));
	Sets exp(size);
	for (int i = 0; i < 4000; i++)
	{
		exp.simpleUnion(getRand(0, size),getRand(0,size));
	}
	for (int i = 0; i < 4000; i++)
	{
		exp.simpleFind(getRand(0, size));
	}
	Sets expa(size);
	for (int i = 0; i < 4000; i++)
	{
		expa.widgetUnion(getRand(0, size), getRand(0, size));
	}
	for (int i = 0; i < 4000; i++)
	{
		expa.collapsingFind(getRand(0, size));
	}
}