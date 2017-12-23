//#include"../BST/BINARY_SEARCH_TREE.cpp"
#include<iostream>

using namespace std;

template <class T>
class AVLNode
{
public:
	T key;
	char balance;
	AVLNode *left;
	AVLNode *right;
	AVLNode(){}
	AVLNode(T data)
	{
		key = data;
		balance = 0;
		this->left = this->right = nullptr;
	}
};

template<class T>
class AVL_TREE
{
private:
	AVLNode<T> *root;
	void LeftRotate(AVLNode<T> *&p);
	void RightRotate(AVLNode<T> *&p);
	void LeftBalance(AVLNode<T> *&p);
	void RightBalance(AVLNode<T> *&p);
	bool InsertNode(AVLNode<T> *&p, T data, bool &isHigher);
	void SearchStandFor(AVLNode<T> *&p, AVLNode<T> *&subRoot);
	bool DeleteNode(AVLNode<T> *&p, T data, bool &isShorter);
	void removeTree(AVLNode<T> *&p);
	void printTree(AVLNode<T> *p);
public:
	AVL_TREE();
	~AVL_TREE();

	bool InsertNode(T data);
	bool DeleteNode(T data);
	void printTree();


};

template<class T>
void AVL_TREE<T>::LeftRotate(AVLNode<T>*& p)
{
	AVLNode<T> *q;
	q = p->right;
	p->right = q->left;
	q->left = p;
	p = q;
}

template<class T>
void AVL_TREE<T>::RightRotate(AVLNode<T>*& p)
{
	AVLNode<T> *q;
	q = p->left;
	p->left = q->right;
	q->right = p;
	p = q;
}

template<class T>
void AVL_TREE<T>::LeftBalance(AVLNode<T>*& p)
{
	switch (p->left->balance)
	{
	case -1:
		this->RightRotate(p);
		p->balance = 0;
		p->right->balance = 0;
		break;
	case 1:
		this->LeftRotate(p->left);
		this->RightRotate(p);
		switch (p->balance)
		{
		case -1:
			p->left->balance = 0;
			p->right->balance = 1;
			break;
		case 0:
			p->left->balance = 0;
			p->right->balance = 0;
			break;
		case 1:
			p->left->balance = -1;
			p->right->balance = 0;
			break;
		}
		p->balance = 0;
		break;
	}
}

template<class T>
void AVL_TREE<T>::RightBalance(AVLNode<T>*& p)
{
	switch (p->right->balance)
	{
	case -1:
		this->RightRotate(p->right);
		this->LeftRotate(p);
		switch (p->balance)
		{
		case -1:
			p->left->balance = -1;
			p->right->balance = 0;
			break;
		case 0:
			p->left->balance = 0;
			p->right->balance = 0;
			break;
		case 1:
			p->left->balance = 0;
			p->right->balance = 1;
			break;
		}
		p->balance = 0;
		break;
	case 1:
		this->LeftRotate(p);
		p->balance = 0;
		p->left->balance = 0;
		break;
	}
}

template<class T>
bool AVL_TREE<T>::InsertNode(AVLNode<T>*& p, T data, bool & isHigher)
{
	bool result;
	if (p == nullptr)
	{
		p = new AVLNode<T>(data);
		if (p == nullptr)
		{
			isHigher = false;
			return false;
		}
		isHigher = true;
		return true;
	}

	if (p->key > data)
	{
		result = InsertNode(p->left, data, isHigher);
		if (isHigher == false)
			return result;

		switch (p->balance)
		{
		case -1:
			LeftBalance(p);
			isHigher = false;
			return result;
		case 0:
			p->balance = -1;
			isHigher = true;
			return result;
		case 1:
			p->balance = 0;
			isHigher = false;
			return result;
		}
		//return result;
	}
	else if (p->key < data)
	{
		result = InsertNode(p->right, data, isHigher);
		if (isHigher == false)
			return result;

		switch (p->balance)
		{
		case -1:
			p->balance = 0;
			isHigher = false;
			return result;
		case 0:
			p->balance = 1;
			isHigher = true;
			return result;
		case 1:
			RightBalance(p);
			isHigher = false;
			return result;
		}
		//return result;
	}
	else
		return false;
	return result;
}

template<class T>
void SearchStandFor(AVLNode<T> *&p, AVLNode<T> *&subRoot)
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
bool AVL_TREE<T>::DeleteNode(AVLNode<T>*& p, T data, bool & isShorter)
{
	bool result;
	if (p == nullptr)
		return false;

	if (p->key > data)
	{
		result = DeleteNode(p->left, data, isShorter);
		if (isShorter == false)
			return result;

		switch (p->balance)
		{
		case -1:
			p->balance = 0;
			isShorter = false;
			return result;
		case 0:
			p->balance = 1;
			isShorter = true;
			return result;
		case 1:
			RightBalance(p);
			isShorter = false;
			return result;
		}
		//return result;
	}
	else if (p->key < data)
	{
		result = DeleteNode(p->right, data, isShorter);
		if (isShorter == false)
			return result;

		switch (p->balance)
		{
		case -1:
			LeftRotate(p);
			isShorter = false;
			return result;
		case 0:
			p->balance = -1;
			isShorter = true;
			return result;
		case 1:
			p->balance = 0;
			isShorter = false;
			return result;
		}
		//return result;
	}
	else	
	{
		AVLNode<T> *q;
		q = p;
		if (p->left == nullptr)
			p = p->right;
		else if (p->right == nullptr)
			p = p->left;
		else
			searchStandFor(q, p->left);
		delete q;

		isShorter = true;
		return true;
	}
	return result;
}

template<class T>
void AVL_TREE<T>::removeTree(AVLNode<T>*& p)
{
	if (p == nullptr)
		return;
	removeTree(p->left);
	removeTree(p->right);
	delete p;
	p = nullptr;
}

template<class T>
void AVL_TREE<T>::printTree(AVLNode<T>* p)
{
	if (p == nullptr)
		return;
	printTree(p->left);
	cout << p->key << ' ';
	printTree(p->right);
}

template<class T>
AVL_TREE<T>::AVL_TREE()
{
	root = nullptr;
}

template<class T>
AVL_TREE<T>::~AVL_TREE()
{
	removeTree(root);
}

template<class T>
bool AVL_TREE<T>::InsertNode(T data)
{
	bool isHigher;
	return InsertNode(root, data, isHigher);
}

template<class T>
bool AVL_TREE<T>::DeleteNode(T data)
{
	bool isShorter;
	return DeleteNode(root, data, isShorter);
}

template<class T>
void AVL_TREE<T>::printTree()
{
	printTree(root);
}
