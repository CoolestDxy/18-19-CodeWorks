//week06.cpp
#include<iostream>
//P147N01:重写push pop函数
//P147N02:添加size和capacity函数
template <typename T>
class Quene
{
public:
	Quene(int queneCapacity = 10) :capacity(queneCapacity)
	{
		if (capacity < 1) throw "capacity invaild(<1)";
		quene = new T[capacity];
		front = rear = 0;
	}
	virtual ~Quene() { delete[] quene; }
	inline bool isEmpty() const { return front == rear; }
	inline T& Front() const { if (isEmpty()) throw "Quene empty, no front element."; return quene[(front + 1) % capacity]; }
	inline T& Rear() const { if (isEmpty()) throw "Quene empty, no front element."; return quene[rear]; }
	void Push(const T& item)
	{
		if ((rear + 1) % capacity == front)
		{
			T * temp = new T[capacity * 2];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = quene[i];
			}
			if (rear < front)
			{
				for (int i = front + 1; i < capacity; i++)
				{
					temp[i + capacity] = quene[i];
				}
				front += capacity;
			}
			capacity *= 2;
			delete[] quene;
			quene = temp;
		}
		rear = (rear + 1) % capacity;
		quene[rear] = item;
	}
	void Pop()
	{
		if (isEmpty()) throw "Quene empty.";
		front = (front + 1) % capacity;
		quene[front].~T();
	}
	unsigned size() { return (rear - front) < 0 ? (rear - front + capacity) : (rear - front); }
	unsigned Capacity() { return ((unsigned)capacity); }
	Quene* split()
	{
		if (front > rear)
		{
			Quene *temp = new Quene(capacity - front);
			temp->quene[0] = 0;
			for (int i = 1; i < capacity - front; i++)
			{
				temp->quene[i] = quene[front + i];
				temp->front = 0; temp->rear = capacity - 1;
			}
			front = capacity - 1;
			return temp;
		}
		return nullptr;
	}
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			std::cout << "a[" << i << "]=" << quene[i] << ",";
		}
		std::cout << std::endl;
	}
private:
	T *quene;
	int front, rear, capacity;
};

void P147N01()
{
	Quene<int> a;
	a.Push(33);
	a.Push(22);
	a.Push(33);
	a.Push(565);
	a.Push(565);
	a.Push(565);
	a.Push(565);
	for (int i = 0; i < 96; i++)
	{
		a.Push(i);
		a.Pop();
	}
	std::cout << a.size() << std::endl;
	//for (int i = 0; i < 100; i++)
	//{
	//	a.Pop();
	//}
	std::cout << a.size() << std::endl;
	std::cout << a.Capacity() << std::endl;
	Quene<int> * arr = a.split();
	a.print();
	arr->print();
	//std::cout << arr->Capacity();
}
//P157N01,P157N02
int maze[][15]=
{
	{0,1,0,0,0,1,1,0,0,0,1,1,1,1,1},
	{1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
	{0,1,1,0,0,0,0,1,1,1,1,0,0,1,1},
	{1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
	{1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
	{0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
	{0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
	{0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
	{0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
	{1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
	{0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
	{0,1,0,0,1,1,1,1,1,0,1,1,1,1,0}
};
struct offsets{int x, y;};
enum directions{N,NE,E,SE,S,SW,W,NW};
offsets move[8];