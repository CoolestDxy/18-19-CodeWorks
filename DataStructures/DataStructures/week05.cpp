//week05.cpp
//P138N01
//Split a stack into two and merge them.
#include<iostream>
template <class T>
class Stack
{
public:
	T * stack;
	int top;
	int capacity;
	Stack(int stackCapacity = 10) :capacity(stackCapacity) { if (capacity < 1)throw"Stack capacity must be > 0\n"; stack = new T[capacity]; top = -1; }
	inline bool isEmpty() const { return top == -1; }
	T& Ttop()const { if (isEmpty()) throw "Stack is empty:"; return stack[pop]; }
	void push(const T& item)
	{
		if (top == capacity - 1)
		{
			T * temp = new T[2 * capacity];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = stack[i];
			}
			delete[] stack;
			stack = temp;
			capacity *= 2;
		}
		stack[++top] = item;
	}
	void pop() { if (isEmpty())throw "stack is empty"; stack[top--].~T(); }
	Stack* split()
	{
		Stack * tempStk = new Stack(top - top / 2);
		//T* temp = new T[top-top / 2];
		for (int i = top / 2 + 1; i <= top; i++)
		{
			tempStk->stack[i - top / 2 - 1] = stack[i];
			stack[i].~T();
			++tempStk->top;
		}
		top -= (1 + tempStk->top);
		return tempStk;
	}
	void merge(Stack<T>* stk)
	{
		int newCap = capacity + stk->capacity;
		if (newCap > capacity)
		{
			T * temp = new T[newCap];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = stack[i];
			}
			delete[] stack;
			stack = temp;
			capacity = newCap;
		}
		for (int i = top; i <= capacity; i++)
		{
			stack[i + 1] = stk->stack[i - top];
		}
		top += stk->top + 1;
	}
	void print()
	{
		for (int i = 0; i <= top; i++)
		{
			std::cout << stack[i] << " ";
		}
		std::cout << std::endl;
	}
};
void P138N01()
{
	Stack<int> exp(30);
	for (int i = 0; i < 30; i++)
	{
		exp.push(i);
	}
	exp.print();
	Stack<int> * expS = exp.split();
	exp.print();
	expS->print();
	exp.merge(expS);
	exp.print();
}
//P138N02
/*
倒车调度问题：
	1.全排列
	2.可以实现所有组合	
*/