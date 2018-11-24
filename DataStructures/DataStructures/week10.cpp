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
		i = simpleFind(i);
		j = simpleFind(j);
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
		i = collapsingFind(i);
		j = collapsingFind(j);
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j])
		{
			parent[i] = j;
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
				i = s;
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
	return rand() % (end - start) + start;
}
void P316N03()
{
	//for (int i = 0; i < 1000000; i++)
	//{
	//	int j = getRand(0, 10);
	//	if (j<0||j>=10)
	//	{
	//		throw "error";
	//	}
	//	std::cout << j;
	//}

	const int size = 100;
	const int rp = 60;
	srand(time(0));
	long a = clock();
	Sets exp(size);
	for (int i = 0; i < rp; i++)
	{
		int a = getRand(0, size);
		int b = getRand(0, size);
		while (a == b|| exp.simpleFind(a)==exp.simpleFind(b))
		{
			a = getRand(0, size);
			b = getRand(0, size);
		}
		exp.simpleUnion(a,b);
	}
	for (int i = 0; i < rp; i++)
	{
		exp.simpleFind(getRand(0, size));
	}
	long b = clock();
	std::cout << b - a<<std::endl;
	a = clock();
	Sets expa(size);
	for (int i = 0; i < rp; i++)
	{
		int a = getRand(0, size);
		int b = getRand(0, size);
		while (a == b||expa.collapsingFind(a)==expa.collapsingFind(b))
		{
			a = getRand(0, size);
			b = getRand(0, size);
		}
		expa.widgetUnion(a,b);
	}
	for (int i = 0; i < rp; i++)
	{
		expa.collapsingFind(getRand(0, size));
	}
	b = clock();
	std::cout << b - a << std::endl;

}