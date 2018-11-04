//week07.cpp
#include"public.h"
class ChainNode
{
	friend class Chain;
public:
	ChainNode(int element = 0, ChainNode * next = 0) { data = element; link = next; }
private:
	int data;
	ChainNode * link;
};
class Chain
{
public:
	void Chain2()
	{
		ChainNode * pr = new ChainNode(50, 0);
		pr = new ChainNode(40, pr);
		pr = new ChainNode(30, pr);
		pr = new ChainNode(20, pr);
		first = new ChainNode(10, pr);
	}
	int length()
	{
		if (this->first != nullptr)
		{
			ChainNode * key = first;
			int count = 1;
			while (key->link != 0)
			{
				++count;
				key = key->link;
			}
			return count;
		}
		return 0;
	}
	int remove(ChainNode* target)
	{
		if (first != nullptr)
		{
			ChainNode * key = first;
			while (key->data != target->data&&key != nullptr)
			{
				key = key->link;
			}
			if (key == 0)
			{
				return 2;//未找到
			}
			if (key == first)
			{
				first = first->link;
			}
			delete[]key;
			return 1;//删除成功
		}
		return 0;//空链表
	}
	void traverse(ChainNode * flag = nullptr)
	{
		if (first != nullptr)
		{
			ChainNode * left = 0;
			ChainNode * key = first;
			ChainNode * right = first;
			while (key != flag && key != nullptr)
			{
				right = key->link;
				key->link = left;
				left = key;
				key = right;
			}
			first = left;
		}
	}
private:
	ChainNode * first;
};
void P183N01()
{
	Chain A;
	A.Chain2();
	std::cout << A.length() << std::endl;
	std::cout << A.remove(new ChainNode(10, 0)) << std::endl;
	A.traverse();
}
//P183N01 函数见	int Chain::length() 时间复杂度O（n）。
//P183N02 函数见	int Chain::remove() 时间复杂度O（n）。
