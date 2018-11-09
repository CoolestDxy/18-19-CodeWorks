//week07.cpp
#include"public.h"
//P183N01 函数见	int Chain::length() 时间复杂度O（n）。
//P183N02 函数见	int Chain::remove() 时间复杂度O（n）。
//P184N06 见Chain::move()。
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
	friend void P183N01();
public:
	Chain(ChainNode * firstNode = nullptr) { first = firstNode; }
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
	ChainNode * traverse(ChainNode * flag = nullptr)
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
		return first;
	}
	ChainNode * traverseLR(int flag)
	{
		if (first != nullptr)
		{
			int a = 0;
			ChainNode * left = 0;
			ChainNode * key = first;
			ChainNode * right = first;
			while (key != nullptr&&a < flag)
			{
				right = key->link;
				key->link = left;
				left = key;
				key = right;
				++a;
			}
			first = left;
		}
		return first;
	}
	void move(int n, ChainNode* &A, ChainNode * &D)
	{
		Chain *temp = new Chain(D);
		int count = 0;
		while (count < n&&D != nullptr)
		{
			ChainNode * oldR = D;
			D = D->link;
			oldR->link = A;
			A = oldR;
			++count;
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
	Chain B;
	B.Chain2();
	A.move(2, A.first, B.first);//friend function;
}

//P194N03 见 P194N03()。
//P194N04 见 sum(std::list<int> a)。
int sum(std::list<int> a)
{
	std::list<int>::iterator n = a.begin();
	std::list<int>::iterator np5 = a.begin();
	for (int i = 0; i < 5; i++)
	{
		np5++;
	}
	int sum = 0;
	for (int i = 0; i < a.size() - 5; i++)
	{
		sum += *n * *np5;
		++n;
		++np5;
	}
	return sum;
}
void P194N03()
{
	const int size = 10;
	std::list<int> lstExample;
	for (int i = 0; i < size; i++)
	{
		lstExample.push_back(i * 10);
	}
	int intExample[size];
	int i = 0;
	for (std::list<int>::iterator iter = lstExample.begin(); iter != lstExample.end(); iter++, i++)
	{
		intExample[i] = *iter;
	}
	for (int j = 0; j < size; j++)
	{
		std::cout << intExample[j] << std::endl;
	}
	std::cout << sum(lstExample) << std::endl;
}
//P201N01
//P201N02
template <class T>
class Stack
{
public:
	void clear();
	bool push(const T item);
	bool pop(T& item);
	bool top(T& item); bool isEmpty();
};
template <class T>
class arrStack : public Stack <T>
{
private:
	int mSize;
	int htop;
	T* st;
public:
	arrStack(int size = 10) :mSize(size), htop(-1)
	{
		st = new T[mSize];
	}
	~arrStack() { delete[] st; }
	void clear() { htop = -1; }
	bool push(const T item)
	{
		if (htop == mSize - 1)
		{
			T *newSt = new T[mSize * 2];
			for (int i = 0; i <= htop; i++) newSt[i] = st[i];
			delete[] st;
			st = newSt; mSize *= 2;
		}
		st[++htop] = item;
		return true;
	}
	bool pop(T& item)
	{
		if (htop == -1)
		{
			std::cout << "The stack is empty" << std::endl;
			return false;
		}
		else
		{
			item = st[htop--];
			return true;
		}
	}
	bool top(T& item)
	{
		if (htop == -1)
		{
			std::cout << "The stack is empty" << std::endl;
			return false;
		}
		else
		{
			item = st[htop];
			return true;
		}
	}
	bool isEmpty()
	{
		if (htop == -1)
		{
			return true;
		}
		else { return false; }
	}
};
template <class T>
class Link
{
public:
	T data;
	Link<T> *next;
	Link(const T info, Link<T>* nextValue = NULL)
	{
		data = info; next = nextValue;
	}
	Link() :next(NULL) {}
};
template <class T>
class LnkStack : public Stack <T> {
private:
	Link<T>* htop;
	int size;
public:
	LnkStack() :htop(NULL), size(0) {}
	~LnkStack()
	{
		clear();
	}
	void clear()
	{
		while (htop != NULL)
		{
			Link<T>* tmp = htop;
			htop = htop->next;
			delete tmp;
		} size = 0;
	}
	bool push(const T item)
	{
		Link<T>* tmp = new Link<T>(item, htop); htop = tmp; size++; return true;
	}
	bool pop(T& item)
	{
		Link<T>* tmp; if (size == 0)
		{
			std::cout << "The stack is empty" << std::endl;
			return false;
		}
		item = htop->data;
		tmp = htop->next;
		delete htop; htop = tmp;
		size--; return true;
	}
	bool top(T& item)
	{
		if (size == 0)
		{
			std::cout << "The stack is empty" << std::endl;
			return false;
		}
		item = htop->data;
		return true;
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
template<class T>
struct Node
{
	T info;
	Node<T> *next;
};
template<class T>
class LnkList
{
public:
	LnkList()
	{
		start = current = NULL;
	}
	LnkList(const LnkList<T> &aplist)
	{
		deepCopy(aplist);
	}
	~LnkList()
	{
		makeEmpty();
	}
	LnkList<T>& operator=(const LnkList<T> &rlist)
	{
		if (this == &rlist)
			return this;
		makeEmpty();
		deepCopy(rlist);
		return this;
	}
	void insert(const T &element)
	{
		current = NULL;
		Node<T> *NNode = new Node<T>;
		NNode->info = element;
		NNode->next = start;
		start = NNode;
	}
	void push(const T &element)
	{
		current = NULL;
		Node<T> *NNode = new Node<T>;
		NNode->info = element;
		NNode->next = NULL;
		Node<T> *temp;
		//T item;
		if (start == NULL)
		{
			start = NNode;
			temp = start;
			return;
		}
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NNode;
	}
	bool first(T &listEl)
	{
		if (start == NULL)
			return false;
		current = start;
		listEl = start->info;
		return true;
	}
	inline bool next_(T &listEl)
	{
		if (current == NULL)
			return false;
		if (current->next == NULL)
		{
			current = NULL;
			return false;
		}
		listEl = current->next->info;
		current = current->next;
		return true;
	}
	bool find(const T &element)
	{
		T item;
		if (!first(item))
			return false;
		do {
			if (item == element)
				return true;
		} while (next(item));
		return false;
	}
	bool retrieve(T &element)
	{
		if (!find(element))
			return false;
		element = current->info;
		return true;
	}
	bool replace(const T &newElement)
	{
		if (current == NULL)
			return false;
		current->info = newElement;
		return true;
	}
	bool remove(T &element)
	{
		current = NULL;
		if (start == NULL)
			return false;
		Node<T> *ptr = start;
		if (start->info == element)
		{
			element = start->info;
			start = ptr->next;
			delete ptr;
			return true;
		}
		while (ptr->next != NULL) {
			if (ptr->next->info == element)
			{
				Node<T> *tempptr = ptr->next;
				element = tempptr->info;
				ptr->next = tempptr->next;
				delete tempptr;
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}
	bool isEmpty() const
	{
		return start == NULL;
	}
	void makeEmpty()
	{
		while (start != NULL)
		{
			current = start;
			start = start->next;
			delete current;
		}
		current = NULL;
	}
private:
	Node<T> *start;
	Node<T> *current;
	inline void deepCopy(const LnkList<T> &original)
	{
		start = current = NULL;
		if (original.start == NULL)
			return;
		Node<T> *copyptr = start = new Node<T>;
		Node<T> *originalptr = original.start;
		copyptr->info = originalptr->info;
		if (originalptr == original.current)
			current = copyptr;
		while (originalptr->next != NULL)
		{
			copyptr->next = new Node<T>;
			originalptr = originalptr->next;
			copyptr = copyptr->next;
			copyptr->info = originalptr->info;
			if (originalptr == original.current)
				current = copyptr;
		}
		copyptr->next = NULL;
	}
};

void P201N01()
{
	LnkStack<int> lnks;
	LnkList<int> lnkl;
	for (int i = 1; i <= 10; i++)
	{
		lnks.push(i * 10);
		lnkl.push(i * 10);
	}
	int topNum;
	int temp;
	lnkl.first(temp);
	while (!lnks.isEmpty())
	{
		lnks.top(topNum);
		std::cout << temp << ' ';
		std::cout << topNum << ' ';
		lnks.pop(topNum);
		lnkl.next_(temp);
	}
	std::cout << std::endl;
}
//P209N05
//template <typename T>
//class FreeList
//{
//private:
//	static FreeList<T> *freelist;
//public:
//	T element;
//	FreeList *next;
//	FreeList(const T& T, FreeList* next = NULL)
//	{
//		this->element = T;
//		this->next = next;
//	}
//	FreeList(FreeList* next = NULL);
//	{
//		this->next = next;
//	}
//	void* operator new(size_t)
//	{
//		if (freelist == NULL)
//			return ::new FreeList;
//		FreeList<T>* temp = freelist;
//		freelist = freelist->next; return temp;
//	}
//	void operator delete(void*)
//	{
//		((FreeList<T>*)ptr)->next = freelist; freelist = (FreeList<T>*)ptr;
//	}
////};
//struct Term
//{
//	int power;
//	int cow;
//};
//class Polynomials
//{
//private:
//	static Term * termArray;
//	static int capacity;
//	static int free;
//	int start, finish;
//public:
//	Polynomials()
//	{
//		std::vector<int> a{ 0,0 };
//		input(a);
//	}
//	Polynomials(std::vector<int> inputArray)
//	{
//		input(inputArray);
//	}
//	Polynomials input(std::vector<int> input)
//	{
//		start = (free != 0) ? ++free : free;
//		finish = start;
//		for (int i = 0; i < input.size() / 2; i++)
//		{
//			termArray[start + i].power = input[2 * i];
//			termArray[start + i].cow = input[2 * i + 1];
//			(i == 0) ? finish : ++finish;
//			(i == 0) ? free : ++free;
//		}
//		return *this;
//	}
//	std::string outPut()
//	{
//		using std::string;
//		string temp = "";
//		std::ostringstream oss;
//		for (int i = start; i <= finish; i++)
//		{
//			oss << termArray[i].cow << "*x^" << termArray[i].power;
//			(i == finish) ? (oss << "") : (oss << "+");
//		}
//		temp = oss.str();
//		return temp;
//	}
//	long evaluate(int x)
//	{
//		long res{ 0 };
//		for (int i = start; i <= finish; i++)
//		{
//			res += termArray[i].cow*pow(x, termArray[i].power);
//		}
//		return res;
//	}
//	Polynomials operator*(Polynomials pol)
//	{
//		Polynomials res;
//		res.start = free + 1;
//		res.finish = res.start;
//		termArray[res.start] = { 0,0 };
//		for (int i = start; i <= finish; i++)
//		{
//			for (int j = pol.start; j <= pol.finish; j++)
//			{
//				Term temp = { termArray[i].power + termArray[j].power , termArray[i].cow * termArray[j].cow };
//				for (int k = res.start; k <= res.finish; k++)
//				{
//					if (temp.power < termArray[k].power)
//					{
//						continue;
//					}
//					else if (temp.power == termArray[k].power)
//					{
//						termArray[k].cow += temp.cow;
//						break;
//					}
//					else if (temp.power > termArray[k].power)
//					{
//						(free < res.finish) ? NULL : ++res.finish;
//						++free;
//						for (int l = k; l < finish; l++)
//						{
//							termArray[l + 1] = termArray[l];
//						}
//						termArray[k] = temp;
//						break;
//					}
//				}
//				(free < res.finish) ? NULL : ++res.finish;
//				++free;
//				termArray[res.finish] = temp;
//			}
//		}
//		return res;
//	};
//	Polynomials operator+(Polynomials pol)
//	{
//		Polynomials res;
//		int keyA = start;
//		int keyB = pol.start;
//		--res.finish;
//		--free;
//		while (keyA <= finish && keyB <= pol.finish)
//		{
//			++res.finish;
//			++free;
//			if (termArray[keyA].power == termArray[keyB].power)
//			{
//				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow + termArray[keyB].cow };
//				++keyA; ++keyB;
//				continue;
//			}
//			else if (termArray[keyA].power > termArray[keyB].power)
//			{
//				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow };
//				++keyA;
//				continue;
//			}
//			else if (termArray[keyA].power < termArray[keyB].power)
//			{
//				termArray[res.finish] = { termArray[keyB].power,termArray[keyB].cow };
//				++keyB;
//				continue;
//			}
//		}
//		if (keyB > pol.finish)
//		{
//			while (keyA <= finish)
//			{
//				++res.finish;
//				++free;
//				termArray[res.finish] = { termArray[keyA].power,termArray[keyA].cow };
//				++keyA;
//			}
//		}
//		else if (keyA > finish)
//		{
//			while (keyB <= pol.finish)
//			{
//				++res.finish;
//				++free;
//				termArray[res.finish] = { termArray[keyB].power,termArray[keyB].cow };
//				++keyB;
//			}
//		}
//		else
//		{
//			return res;
//		}
//		return res;
//	}
//};
//int Polynomials::capacity = 100;
//Term * Polynomials::termArray = new Term[100];
//int Polynomials::free = 0;
//template<class T>
//class CircularList
//{
//
//};
//struct CirData
//{
//	int coef;
//	int exp;
//	CirData * link;
//};
//class CirLink
//{
//public:
//	CirLink()
//	{
//		head=nullptr;
//	}
//	void insert(int coef, int exp)
//	{
//		if (head==nullptr)
//		{
//			head = new CirData;
//			head->coef = coef;
//			head->exp = exp;
//			head->link = head;
//		}
//		CirData * key = head;
//		while (key->exp>exp)
//		{
//			key = key->link;
//		}
//		if (key->exp==exp)
//		{
//			key->coef += coef;
//		}
//		else
//		{
//			CirData * temp = new CirData;
//			temp->coef = coef;
//			temp->exp = exp;
//			temp->link = key->link;
//			key->link = temp;
//		}
//	}
//	std::ostream& operator<<(std::ostream & os)
//	{
//		CirData * key = head;
//		os << key->coef << "x^" << key->exp;
//		while (key->link!=head)
//		{
//			key = key->link;
//			os << "+"<<key->coef << "x^" << key->exp;
//		}
//	}
//	std::istream& operator>> (std::istream &is )
//	{
//		while (is)
//		{
//			int tempCoef, tempExp;
//			is >> tempCoef;
//			if (tempExp)
//			{
//				is >> tempExp;
//			}
//			else
//			{
//				return;
//			}
//
//			//insert();
//		}
//	}
//private:
//	CirData * head;
//};
//void P209N05()
//{
//}
//P225N02
class DblListNode {
	friend class DblList;
public:
	DblListNode(int element = 0)
	{
		data = element;
	}
private:
	int data;
	DblListNode*left;
	DblListNode*right;
};
class DblList
{
public:
	DblList()
	{
		first = 0;
	}
	bool isEmpty()
	{
		return !first;
	}
	void Delete(DblListNode*x)
	{
		if (x == first)throw "Deletion of header node not permitted";
		else
		{
			x->left->right = x->right;
			x->right->left = x->left;
			delete x;
		}
	}
	void insert(int element)
	{
		DblListNode *temp = new DblListNode(element);
		if (isEmpty())
		{
			first = temp;
			first->left = first;
			first->right = first;
		}
		else {
			temp->left = first->left;
			temp->right = first;
			first->left->right = temp;
			first->left = temp;
		}
	}
	void insert(DblListNode* Left, DblListNode*Right, int element)
	{
		DblListNode x(element);
		x.left = Left;
		x.right = Right;
		Left->right = &x;
		Right->left = &x;
	}
	void Concatenate(DblList &m)
	{
		DblListNode*temp;
		temp = first->left;
		temp->right = m.first;
		(m.first)->left->right = first;
		first->left = (m.first)->left;
		(m.first)->left = temp;
		m.first = 0;
	}
	void output()
	{
		DblListNode* temp = first;
		do
		{
			std::cout << temp->data << " ";
			temp = temp->right;
		} while (temp != (first->left));
		std::cout << temp->data << std::endl;
	}
private:
	DblListNode*first;
};

void P225N02()
{
	DblList lstExp;
	for (int i = 0; i < 10; i++)
	{
		lstExp.insert(i * 10);
	}
	lstExp.output();
	DblList lstExpN;
	for (int i = 11; i < 20; i++)
	{
		lstExpN.insert(i * 10);
	}
	lstExpN.output();
	lstExp.Concatenate(lstExpN);
	lstExp.output();
}