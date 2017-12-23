#include<iostream>
#include<queue>
using namespace std;

template <class T>
class BSTNode
{
public:
	T key;
	BSTNode<T> *left;
	BSTNode<T> *right;

	BSTNode() {}
	BSTNode(T data)
	{
		this->key = data;
		this->left = this->right = nullptr;
	}
};

template<class T>
class BINARY_SEARCH_TREE
{
private:
	BSTNode<T> *root;
	bool insertNode(BSTNode<T> *&p, T newData);
	bool removeNode(BSTNode<T> *&p, T data);
	BSTNode<T>* findNode(BSTNode<T> *p, T akey);
	int countNode(BSTNode<T> *p);
	int height(BSTNode<T> *p);
	void searchStandFor(BSTNode<T> *&p, BSTNode<T> *&subRoot);
	void print(BSTNode<T> *p);
	void deleteTree(BSTNode<T> *&p);
	//void LNR(BSTNode<T> *p);
	//void NLR(BSTNode<T> *p);
	//void LRN(BSTNode<T> *p);
public:
	BINARY_SEARCH_TREE();
	//BINARY_SEARCH_TREE(const BINARY_SEARCH_TREE &Tree);
	~BINARY_SEARCH_TREE();

	void print();
	bool insert(T newData);
	bool remove(T data);
	BSTNode<T>* findNode(T data);
	bool isEmpty();
	int countNode();
	int height();
	void deleteTree();
	bool isAVL(BSTNode<T> *p);
	//void preoder();
	//void inorder();
	//void postoder();
};



template<class T>
bool BINARY_SEARCH_TREE<T>::insertNode(BSTNode<T>*& p, T newData)
{
	if (p == nullptr)
	{
		p = new BSTNode<T>(newData);
		if (p == nullptr)
			return false;
		return true;
	}

	if (p->key > newData)
		return insertNode(p->left, newData);
	else if (p->key < newData)
		return insertNode(p->right, newData);
	else
		return false;
}

template<class T>
bool BINARY_SEARCH_TREE<T>::removeNode(BSTNode<T>*& p, T data)
{
	if (p == nullptr)
		return false;

	if (p->key > data)
		return removeNode(p->left, data);
	else if (p->key < data)
		return removeNode(p->right, data);
	else
	{
		BSTNode<T> *current;
		current = p;
		if (p->left == nullptr)
			p = p->right;
		else if (p->right == nullptr)
			p = p->left;
		else
			searchStandFor(current, p->left);
		delete current;
	}
	return true;
}

template<class T>
void BINARY_SEARCH_TREE<T>::searchStandFor(BSTNode<T> *&p, BSTNode<T> *&subRoot)
{
	if (subRoot->right != nullptr)
		searchStandFor(p, subRoot->right);
	else
	{
		p->key = subRoot->key;
		p = subRoot;
		subRoot = subRoot->left;
	}
}

template<class T>
BSTNode<T>* BINARY_SEARCH_TREE<T>::findNode(BSTNode<T>* p, T akey)
{
	if (p != nullptr)
	{
		if (p->data > aKey)
			return findNode(p->left, aKey);
		else if (p->data < aKey)
			return findNode(p->right, aKey);
		else
			return p;
	}
	return nullptr;
}

template<class T>
int BINARY_SEARCH_TREE<T>::countNode(BSTNode<T>* p)
{
	if (p == nullptr)
		return 0;
	return 1 + countNode(p->left) + countNode(p->right);
}

template<class T>
int BINARY_SEARCH_TREE<T>::height(BSTNode<T>* p)
{
	if (p == nullptr)
		return 0;
	int heightLeft = height(p->left);
	int heightRight = height(p->right);
	if (heightLeft > heightRight)
		return 1 + heightLeft;
	else
		return 1 + heightRight;
}



template<class T>
void BINARY_SEARCH_TREE<T>::print(BSTNode<T>* p)
{
	if (p == nullptr)
		return;
	print(p->left);
	cout << p->key << ' ';
	print(p->right);
}

template<class T>
void BINARY_SEARCH_TREE<T>::deleteTree(BSTNode<T>*& p)
{
	if (p == nullptr)
		return;
	deleteTree(p->left);
	deleteTree(p->right);
	delete p;
	p = nullptr;
}

template<class T>
BINARY_SEARCH_TREE<T>::BINARY_SEARCH_TREE()
{
	root = nullptr;
}

template<class T>
BINARY_SEARCH_TREE<T>::~BINARY_SEARCH_TREE()
{
	deleteTree(root);
}

template<class T>
void BINARY_SEARCH_TREE<T>::print()
{
	this->print(root);
}

template<class T>
bool BINARY_SEARCH_TREE<T>::insert(T newData)
{
	return insertNode(root, newData);
}

template<class T>
bool BINARY_SEARCH_TREE<T>::remove(T data)
{
	return removeNode(root, data);
}

template<class T>
BSTNode<T>* BINARY_SEARCH_TREE<T>::findNode(T data)
{
	return findNode(root, data);
}

template<class T>
bool BINARY_SEARCH_TREE<T>::isEmpty()
{
	if (root == nullptr)
		return true;
	return false;
}

template<class T>
int BINARY_SEARCH_TREE<T>::countNode()
{
	return countNode(root);
}

template<class T>
int BINARY_SEARCH_TREE<T>::height()
{
	return height(root);
}

template<class T>
void BINARY_SEARCH_TREE<T>::deleteTree()
{
	deleteTree(root);
}

template<class T>
bool BINARY_SEARCH_TREE<T>::isAVL(BSTNode<T> *p)
{
	queue< BSTNode<T> > q;
	q.push(p);
	while (!q.empty())
	{
		BSTNode<T> *tmp;
		tmp = q.pop();
		if (abs(height(tmp->left) - height(tmp->right)) > 1)
			return false;
		if (tmp->left != nullptr)
			q.push(tmp->left);
		if (tmp->right != nullptr)
			q.push(tmp->right);
	}
	return true;
}
