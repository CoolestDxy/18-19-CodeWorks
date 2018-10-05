//week02.cpp
//Page:093
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

struct Term;

void P093N02();
int P093N02_Cal();
void P093N06();
long P093N06_Cal(std::vector<Term>, int);
void P093N09();


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

struct Term
{
	int power;
	int cow;
};
void P093N06()
{
	std::vector<Term> pol{ {0,1} ,{1,5},{2,6},{9,7} };
	int x = 2;
	std::cout << P093N06_Cal(pol, x);
}
long P093N06_Cal(std::vector<Term> pol, int x)
{
	long result{ 0 };
	for (int i = 0; i < pol.size(); i++)
	{
		result += pol[i].cow*pow(x, pol[i].power);
	}
	return result;
}
class Polynomials
{
private:
	static Term * termArray;
	static int capacity;
	static int free;
	int start, finish;
public:
	Polynomials()
	{
		std::vector<int> a{ 0,0 };
		input(a);
	}
	Polynomials(std::vector<int> inputArray)
	{
		input(inputArray);
	}
	Polynomials input(std::vector<int> input)
	{
		start = (free!=0)?++free:free;
		finish = start;
		for (int i = 0; i < input.size() / 2; i++)
		{
			termArray[start+i].power = input[2 * i];
			termArray[start+i].cow = input[2 * i + 1];
			(i==0)?finish:++finish;
			(i==0)?free:++free;
		}
		return *this;
	}
	std::string outPut()
	{
		using std::string;
		string temp = "";
		std::ostringstream oss;
		for (int i = start; i <= finish; i++)
		{
			oss << termArray[i].cow << "*x^" << termArray[i].power;
			(i==finish)?(oss<<""):(oss<<"+");
		}
		temp = oss.str();
		return temp;
	}
	long evaluate(int x)
	{
		long res{ 0 };
		for (int i = start; i <= finish; i++)
		{
			res += termArray[i].cow*pow(x, termArray[i].power);
		}
		return res;
	}
	Polynomials operator*(Polynomials pol)
	{
		Polynomials res;
		res.start = free + 1;
		res.finish = res.start;
		++free;
		termArray[res.start] = { 0,0 };
		for (int i = start; i <= finish; i++)
		{
			for (int j = pol.start; j <= pol.finish; j++)
			{
				termArray[finish];
				Term temp = { termArray[i].power + termArray[j].power , termArray[i].cow * termArray[j].cow };
				for (int k = res.start; k < res.finish; k++)
				{
					if (temp.power < termArray[k].power)
					{
						continue;
					}
					else if (temp.power == termArray[k].power)
					{
						termArray[k].cow += temp.cow;
						break;
					}
					else if (temp.power > termArray[k].power)
					{
						++finish;
						++res.finish;
						for (int l = k; l < finish; l++)
						{
							termArray[l + 1] = termArray[l];
						}
						termArray[k] = temp;
						break;
					}

				}
				++res.finish;
				++free;
			}
		}
		return res;
	};
	Polynomials operator+(Polynomials pol)
	{
		Polynomials res;
		int keyA = start;
		int keyB = pol.start;
		--res.finish;
		--free;
		while (keyA <= finish && keyB <= pol.finish)
		{
			++res.finish;
			++free;
			if (termArray[keyA].power == termArray[keyB].power)
			{
				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow + termArray[keyB].cow };
				++keyA; ++keyB;
				continue;
			}
			else if (termArray[keyA].power > termArray[keyB].power)
			{
				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow };
				++keyA;
				continue;
			}
			else if (termArray[keyA].power < termArray[keyB].power)
			{
				termArray[res.finish] = { termArray[keyB].power,termArray[keyB].cow };
				++keyB;
				continue;
			}
		}
		if (keyB > pol.finish)
		{
			while (keyA <= finish)
			{
				++res.finish;
				++free;
				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow };
				++keyA;
			}
		}
		else if (keyA > finish)
		{
			++res.finish;
			++free;
			termArray[res.finish] = { termArray[keyB].power,termArray[keyB].cow };
			++keyB;
		}
		else
		{
			return res;
		}
		return res;
	}
};
int Polynomials::capacity = 100;
Term * Polynomials::termArray = new Term[100];
int Polynomials::free = 0;

void P093N09()
{
	std::vector<int> vectorA = { 9,1,7,2,6,3 };
	std::vector<int> vectorB = { 5,5,4,1,3,9,2,10,1,5,0,6 };
	Polynomials sA= Polynomials(vectorA);
	Polynomials sB= Polynomials(vectorB);
	std::cout << sA.outPut()<<std::endl;
	std::cout << sB.outPut()<<std::endl;
	std::cout << sB.evaluate(3) << std::endl;
	std::cout << (sA + sB).outPut() << std::endl;
	//std::cout << (sA * sB).outPut() << std::endl;
}