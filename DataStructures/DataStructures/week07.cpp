//week07.cpp
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
		ChainNode * second = new ChainNode(20, 0);
		first = new ChainNode(10, second);
	}
private:
	ChainNode * first;
};
//P183N01
//P183N02
