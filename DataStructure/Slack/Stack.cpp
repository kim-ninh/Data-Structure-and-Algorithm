template <class T>
class STACK
{
private:
	struct StackNode {
		T data;
		StackNode *next;
	};
	StackNode *top;
public:
	STACK();
	STACK(const STACK &aStack);
	~STACK();

	bool isEmpty();
	bool push(T newItem);
	bool pop(T &item);
	bool topValue(T &item);
};

template<class T>
 STACK<T>::STACK()
{
	top = nullptr;
}

template<class T>
 STACK<T>::STACK(const STACK & aStack)
{
	 StackNode *current = aStack->top;
	 while (current != nullptr)
	 {
		 this->push(current->data); // need to reverse
		 current = current->next;
	 }

	 //Reverse stack
	 StackNode *previous = nullptr;
	 StackNode *current = top;
	 StackNode *next;
	 while (current != nullptr)
	 {
		 next = current->next;
		 current->next = previous;
		 previous = current;
		 current = next;
	 }
	 top = previous;
}

template<class T>
 STACK<T>::~STACK()
{
	 T tmp;
	 while (top != nullptr)
		 pop(tmp);
}

template<class T>
 bool STACK<T>::isEmpty()
{
	if (top == nullptr)
		return true;
	return false;
}

template<class T>
 bool STACK<T>::push(T newItem)
{
	 StackNode *newNode = new StackNode;
	 if (newNode == nullptr)
		 return false;
	 newNode->data = newItem;
	 newNode->next = nullptr;

	 newNode->next = top;
	 top = newNode;
	 return true;
}

template<class T>
 bool STACK<T>::pop(T & item)
{
	 if (top == nullptr)
		 return false;

	 item = top->data;
	 StackNode *hold = top;
	 top = top->next;
	 delete hold;
	 return true;
}

template<class T>
 bool STACK<T>::topValue(T & item)
{
	 if (top == nullptr)
		 return false;
	 item = top->data;
	 return true;
}