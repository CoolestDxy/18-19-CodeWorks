//week08_exp.cpp
#include"public.h"
#include<stack>
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
	void copySubTree(Node<T>* to,const Node<T>* from)
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
	~Tree() {/*TODOÉ¾³ýÊ÷*/ };
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
		std::stack<Node<T> *> s;
		do
		{
			std::cout << currentNode.data;
			if (currentNode == nullptr)
			{
				currentNode = s.top()->right;
				s.pop();
			}
			else
				(currentNode->left)
			{
				s.push(currentNode);
				currentNode = currentNode->left;
			}
		} while (!s.empty())
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
	inorderIterator(Node<T> *node) { currentNode = node; };
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
	forwardIterator(Node<T> *node) { currentNode = node; };
	T *next()
	{
		T *temp = currentNode.data;
		if (currentNode == nullptr)
		{
			currentNode = s.top()->right;
			s.pop();
		}
		else
			(currentNode->left)
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
	backwardIterator()
	{
		s = new std::stack<Node<T>*>;
		currentNode = root;
		while (currentNode->left||currentNode->right)
		{
			s.push(currentNode);
			if(currentNode->left)
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
