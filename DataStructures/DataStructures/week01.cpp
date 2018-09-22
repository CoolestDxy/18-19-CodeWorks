//week01.cpp
//Page:032 No:02
#include <iostream>
#include <string>

unsigned userInput{ 0 };
bool* list = new bool[userInput] {false};

void P032N02_R(const unsigned);
void P032N02_Print();
void P032N02()
{
	std::cin >> userInput;
	P032N02_R(userInput);
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
