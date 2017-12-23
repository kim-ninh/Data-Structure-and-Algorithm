#pragma once
template<class T>
struct ListNode
{
	T data;
	ListNode *next;
};


template <class T>
class LINKED_LIST {
private:
	int size;
	ListNode *head;
	void QSort(ListNode<T> *&head);
public:
	LINKED_LIST<T>();
	LINKED_LIST<T>(const LINKED_LIST &aList);
	~LINKED_LIST<T>();

	//operations
	bool isEmpty();
	int getLength();
	void reverse();
	bool insert(int index, T newItem);
	bool remove(int index);
	int findNode(T key);
	bool retrieve(int index, T &itemData);
};


