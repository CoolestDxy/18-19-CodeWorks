//week05.cpp
//P138N01
//Split a stack into two and merge them.
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
		if (pop==capacity-1)
		{
			T * temp = new T[2 * capacity];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = stack[i];
			}
			delete[] stack;
			stack = temp;
			capacity *= 2;
			stack[++pop] = item;
		}
	}
	void pop() { if (isEmpty())throw "stack is empty"; stack[top--].~T(); }
};
void P138N01()
{

}