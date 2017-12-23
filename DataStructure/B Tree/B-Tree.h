#pragma once
#include<fstream>
#include<iostream>
using namespace std;
template<class T>
class BTreeNode
{
private:
	bool leaf;
	int keyTally;
	T *keys;				//[M-1]
	unsigned int *pointer;	//M
	char *unused;			//k
	unsigned short M;
	//friend BTreeNode<T, M>;
public:
	unsigned short size()
	{
		return sizeof(leaf) + sizeof(keyTally) + sizeof(T)*(M-1) + sizeof(pointer) * M + sizeof(unused) + sizeof(M);
	}
	BTreeNode() { }
	BTreeNode(unsigned short level)
	{
		if (level > 1)
			M = level;
		pointer = new unsigned int[M];
		keys = new T[M - 1];
		leaf = true;
		keyTally = 0;
		int k;
	}
	BTreeNode(const T&);
};

template<class T, int M>
BTreeNode<T,M>* BTreeSearch(T K, BTreeNode<T,M> *node)
{
	if (node != 0)
		for (int i = 1; i < node->keyTally && node->keys[i - 1] < K; i++)
			if (i > node->keyTally || node->keys[i - 1] > L)
				return BTreeSearch(K, node->pointer[i - 1]);
			else
				return node;
	else
		return 0;
}

template<class T>
class BTree 
{
private:
	int M;
	short k;
	BTreeNode<T> *root;
	fstream file;
public:
	BTree();
};

template<class T>
inline BTree<T>::BTree()
{
	M = (512 + sizeof(T) - 2) / (4 + sizeof(T));
	k = (512 + sizeof(T) - 2) % (4 + sizeof(T));
}

