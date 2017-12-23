#include"SingleLinkedList.h"

template<class T>
LINKED_LIST<T>::LINKED_LIST()
{
	head = nullptr;
	size = 0;
}

template<class T>
LINKED_LIST<T>::LINKED_LIST(const LINKED_LIST & aList)
{
	size = 0;
	head = nullptr;
	ListNode<T> *current = aList->head;
	while (current != nullptr)
	{
		this->insert(size, current->data);
		current = current->next;
	}
}

template<class T>
LINKED_LIST<T>::~LINKED_LIST()
{
	while (size != 0)
		remove(0);
}

template<class T>
void LINKED_LIST<T>::QSort(ListNode<T> *& head)
{
	ListNode<T> *current, *privot;
	LINKED_LIST<T> l1, l2;
	
}

template<class T>
bool LINKED_LIST<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template<class T>
int LINKED_LIST<T>::getLength()
{
	return size;
}

template<class T>
void LINKED_LIST<T>::reverse()
{
	ListNode<T> *previous = nullptr;
	ListNode<T> *current = head;
	ListNode<T> *next;
	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

template<class T>
bool LINKED_LIST<T>::insert(int index, T newItem)
{
	ListNode<T> *newNode = new ListNode;
	if (newNode == nullptr)
		return false;

	newNode->data = newItem;

	if (index == 0)		//insert at head
	{
		newNode->next = head;
		head = newNode;
	}else
	{
		if (index < 0 || index >= size)
			return false;
		ListNode<T> *current = head;
		int currentIndex = 0;
		while (currentIndex != index - 1)	//Stop before node index
		{
			current = current->next;		//Linear searching
			currentIndex++;
		}

		newNode->next = current->next;		//modify node
		current->next = newNode;
	}
	size++;
	return true;
}

template<class T>
bool LINKED_LIST<T>::remove(int index)
{
	if (index < 0 || index >= size)
		return false;

	if (index == 0 && size != 1)
	{
		ListNode<T> *current = head;
		head = head->next;
		delete current;
	}
	else if (index == 0 && size == 1)
	{
		delete head;
		head = NULL;
	}
	else if (index != 0 && size != 1)
	{
		int currentIndex = 0;
		ListNode<T> *current = head;
		while (currentIndex != index - 1)
		{
			currentIndex++;
			current = current->next;
		}

		ListNode<T> *holdOn = current->next;
		current->next = current->next->next;
		delete holdOn;
	}
	size--;
	return true;
}

template<class T>
int LINKED_LIST<T>::findNode(T key)
{
	int currentIndex = 0;
	ListNode<T> *current = head;
	while (current != nullptr)
	{
		if (current->data == key)
			return currentIndex;
		current = current->next;
		currentIndex++;
	}
	return -1;
}

template<class T>
bool LINKED_LIST<T>::retrieve(int index, T & itemData)
{
	if (index < 0 || index >= size)
		return false;

	int currentIndex = 0;
	ListNode<T> *current = head;
	while (currentIndex != index)
	{
		currentIndex++;
		current = current->next;
	}
	itemData = current->data;
	return true;
}