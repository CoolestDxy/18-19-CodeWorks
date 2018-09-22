//week01.cpp
//Page:032 No:02
#include <iostream>
#include <string>
#include <list>

unsigned userInput{ 0 };
bool* list = new bool[userInput] {false};
std::list<std::string> sets = { "a","b","c","d","e","f" };

void P032N02_R(const unsigned);
void P032N14_R(const unsigned);
void P032N02_Print();
void P032N14_Print();
void P032N02()
{
	std::cout << "Please input the size of the list(for Page032 Question02):";
	std::cin >> userInput;
	P032N02_R(userInput);
	std::cout << "{ ";
	P032N14_R(sets.size());
	std::cout << " }";

}
void P032N02_R(const unsigned n)
{
	if (n==1)
	{
		list[n-1] = true;
		P032N02_Print();
		list[n-1] = false;
		P032N02_Print();
	}
	else
	{
		list[n-1] = true;
		P032N02_R(n - 1);
		list[n-1] = false;
		P032N02_R(n - 1);
	}
}

void P032N02_Print()
{
	for (int i = 0; i < userInput; i++)
	{
		if (list[i])
		{
			std::cout << "true";
		}
		else
		{
			std::cout << "false";
		}
		if (i!=userInput-1)
		{
			std::cout << ", ";
		}
		else
		{
			std::cout << " ;\n";
		}
	}
}

void P032N14_R(const unsigned n)
{
	if (n == 1)
	{
		list[n - 1] = true;
		P032N14_Print();
		list[n - 1] = false;
		P032N14_Print();
	}
	else
	{
		list[n - 1] = true;
		P032N14_R(n - 1);
		list[n - 1] = false;
		P032N14_R(n - 1);
	}
}
void P032N14_Print()
{
	std::cout << "( ";
	int n = 0;
	for (std::list<std::string>::iterator i = sets.begin(); i != sets.end(); i++)
	{
		if (list[n])
		{
			std::cout << *i;

		}
		++n;
	}
	std::cout << " )";
}