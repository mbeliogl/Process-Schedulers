#include <iostream>
using namespace std;

template <class item_t>
LinkedList<item_t>::LinkedList()
{
	head = 0;
	tail = 0;
	size = 0;
}

template <class item_t>
LinkedList<item_t>::~LinkedList()
{
	LinkedListNode<item_t>* tempNode;
	for(int i = 0; i < size; i ++)
	{
		tempNode = head;
		delete head;
		head = (*tempNode).getNext();		
	}
	delete tail;

}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item)
{
	LinkedListNode<item_t>* currNode = head;
	LinkedListNode<item_t>* tempNode = new LinkedListNode<item_t>(0, item);
	if(size == 0)
	{
		head = tempNode;
		tempNode->setNext(0);
		size++;
	}
	else
	{
		while(currNode->getNext() != 0)
		{
			currNode = currNode->getNext();
		}
		currNode->setNext(tempNode);
		size++;
	}
}

template <class item_t>
void LinkedList<item_t>::popBack()
{
	LinkedListNode<item_t>* currNode = head;
	if(head == tail)
	{
		delete head;
		head = 0;
		tail = 0;
		return;
	}
	while(currNode->getNext() != tail)
	{
		currNode = currNode->getNext();
	}
	delete tail;
	tail = currNode;
	tail->setNext(0);
	size--;
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const
{
	return (*tail).getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item)
{
	LinkedListNode<item_t>* tempNode = new LinkedListNode<item_t>(head, item);
	head = tempNode;
	size ++;
}

template <class item_t>
void LinkedList<item_t>::popFront()
{
	if(size == 1)
	{
		delete head;
		head = 0;
		tail = 0;
		return;
	}
	LinkedListNode<item_t>* tempNode = head->getNext();
	delete head;
	head = tempNode;
	size--;
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const
{
	return (*head).getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const
{
	LinkedListNode<item_t>* tempNode = head;
	for(int i = 0; i < index; i ++)
	{
		tempNode = (*tempNode).getNext();
	}
	const item_t& result = (*tempNode).getItem();
	return result;
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item)
{
	LinkedListNode<item_t>* tempNode = head;
	for(int i = 0; i < index; i ++)
	{
		tempNode = (*tempNode).getNext();
	}
	(*tempNode).setItem(item);

}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item)
{
	LinkedListNode<item_t>* tempNode = new LinkedListNode<item_t>(0, item);
	LinkedListNode<item_t>* currNode = head;
	LinkedListNode<item_t>* prevNode = 0;
	int i = 0;
	tempNode->setNext(0);
	if(index == 0)
	{
		tempNode->setNext(head);
		head = tempNode;
		return;
	}
	while(i < index)
	{
		prevNode = currNode;
		currNode = currNode->getNext();
		if(currNode == 0)
			break;
		i++;
	}
	tempNode->setNext(currNode);
	prevNode->setNext(tempNode);

}

template <class item_t>
void LinkedList<item_t>::remove(int index)
{
	LinkedListNode<item_t>* currNode = head;
	LinkedListNode<item_t>* prevNode = 0;
	int idx = 0;
	if(index == 0)
	{
		popFront();
		return;
	}
	if(index == size-1)
	{
		popBack();
		return;
	}
	while(idx != index)
	{
		prevNode = currNode;
		currNode = currNode->getNext();
		idx ++;
	}
	prevNode->setNext(currNode->getNext());
	delete currNode;
}

template <class item_t>
int LinkedList<item_t>::getSize() const
{
	return size;
}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const
{
	if(size == 0 || (head == 0 && tail == 0))
		return true;
	else 
		return false;
}



