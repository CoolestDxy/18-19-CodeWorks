
//week08.cpp


#include "public.h"
#include <stack>
//P267N04 ����������ĵ����� �鿴class inorderIterator
//P267N06 �޵ݹ��ǰ������� �鿴class Tree����	void preorder_noneRecursive()
//P273N01 �������е�Ҷ�ڵ㲢����ʱ�临�Ӷ�	�鿴class Tree���� countLeaf() ʱ�临�Ӷ�O(n)
//P273N04 ɾ�������������нڵ㲢����ʱ�临�Ӷ� �鿴class Tree���� 	void delTree(Node<T> *node) ʱ�临�Ӷ�O(n)
//P273N10 [ʵ����]���쿽���������ֱ�������
//week08_exp.cpp
#include"public.h"
#include<stack>
#include<queue>
template <typename T>
struct Node
{
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	T data;
};
template <typename T>
class Tree
{
public:
	Tree() { root = new Node<T>; }
	Tree(Tree * const target) {
		root = new Node<T>();
		root.data = target->root;
		copySubTree(this.root, target.root);
	}
	void copySubTree(Node<T>* to, const Node<T>* from)
	{
		if (from->left)
		{
			to->left = new Node<T>();
			to->left->data = from->left->data;
			copySubTree(to->left, from->left);
		}
		if (from->right)
		{
			to->right = new Node<T>();
			to->right->data = from->right->data;
			copySubTree(to->right, from->right);
		}
	}
	~Tree() {/*TODOɾ����*/ };
	void delTree(Node<T> *node)
	{
		if (node->left)
		{
			delTree(node->left);
		}
		if (node->right)
		{
			elTree(node->right);
		}
		delete[] node;
	};
	void inorder() { inorder(root); };
	void inorder(Node<T> *node)
	{
		if (node)
		{
			inorder(node->left);
			std::cout << node->data;
			inorder(node->right);
		}
	}
	void preorder() { inorder(root); };
	void preorder(Node<T> *node)
	{
		if (node)
		{
			std::cout << node->data;
			preorder(node->left);
			preorder(node->right);
		}
	}
	void preorder_noneRecursive()
	{
		Node<T> * currentNode = root;
		std::stack<Node<T> *> s;
		do
		{
			std::cout << currentNode.data;
			if (currentNode == nullptr)
			{
				currentNode = s.top()->right;
				s.pop();
			}
			else if (currentNode->left);
			{
				s.push(currentNode);
				currentNode = currentNode->left;
			}
		} while (!s.empty());
	}
	void postorder() { inorder(root); };
	void postorder(Node<T> *node)
	{
		if (node)
		{
			std::cout << node->data;
			postorder(node->left);
			postorder(node->right);
		}
	}
	long countLeaf()
	{
		return countLeaf(root);
	}
	long countLeaf(Node<T> * node)
	{
		if (node == nullptr) return 1;
		return countLeaf(node->left) + countLeaf(node->right);
	}
private:
	Node<T> root;
};
template <typename T>
class inorderIterator
{
public:
	inorderIterator(Tree<T> * tree)
	{
		currentNode = tree->root;
	};
	T *next()
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->left;
		}
		if (s.empty())
			return nullptr;
		currentNode = s.top();
		s.pop();
		T &temp = currentNode->data;
		currentNode = currentNode->right;
		return &temp;
	}

private:
	std::stack<Node<T> *> s;
	Node<T> *currentNode;
};
template <typename T>
class forwardIterator
{
public:
	forwardIterator(Tree<T>* tree) { currentNode = tree.root; };
	T *next()
	{
		T *temp = currentNode.data;
		if (currentNode == nullptr)
		{
			currentNode = s.top()->right;
			s.pop();
		}
		else if (currentNode->left)
		{
			s.push(currentNode);
			currentNode = currentNode->left;
		}
		if (s.empty())
		{
			return nullptr;
		}
		return &T;
	}

private:
	std::stack<Node<T> *> s;
	Node<T> *currentNode;
};
template <typename T>
class backwardIterator
{
public:
	backwardIterator(Tree<T>* tree)
	{
		s = new std::stack<Node<T>*>;
		currentNode = tree->root;
		while (currentNode->left || currentNode->right)
		{
			s.push(currentNode);
			if (currentNode->left)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}
	}
	T* next()
	{
		if (s.empty)return nullptr;
		T* temp = currentNode->data;
		if (currentNode == s.top()->left)
		{
			currentNode = s.top()->right;
			while (currentNode->left || currentNode->right)
			{
				s.push(currentNode);
				if (currentNode->left)
				{
					currentNode = currentNode->left;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
		else
		{
			currentNode = s.top();
			s.pop();
		}
		return temp;
	}
private:
	std::stack<Node<T>*> s;
	Node<T> *currentNode;
};
template <typename T>
class leavelIterator
{
	leavelIterator(Tree<T> *tree)
	{
		q.push(tree->root);
	}
	T* next()
	{
		T* temp = q.front()->data;
		if (q.front()->left)
		{
			q.push(q.front()->left);
		}
		if (q.front()->right)
		{
			q.push(q.front()->right);
		}
		q.pop();
	}
private:
	std::queue<Node<T>*> q;
};

Tree<int>;
void P267N04()
{
	//TODO..
	//�����ʾ����
}
//P277N01 ��������������ָ���ڵ�����Ӳ���һ��ָ���ڵ㲢����������Ϊ������ڵ�����Ӳ���
template<typename T>
struct ThreadNode
{
	bool leftNode;
	bool rightNode;
	ThreadNode<T> * leftChild;
	ThreadNode<T> * rightChild;
	T data;
};
template<typename T>
class ThreadNodeTree
{
public:
	ThreadNodeTree() { root = nullptr; }
	~ThreadNodeTree() { remove(root); }
	void remove(ThreadNode<T>* node)
	{
		if (node->leftChild != nullptr)remove(node->leftChild);
		if (node->rightChild != nullptr)remove(node->rightChild);
		if (node != nullptr)delete[] node;
	}
private:
	ThreadNode<T> * root;
};

