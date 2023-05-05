//put your implementation of LinkedList class here
#include "list.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;	
}

bool LinkedList::addAtBeginning(int val)
{
	Node * newNode = new Node;
	if(newNode == NULL)
		return false;
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return true;
}

bool LinkedList::remove(int val)
{
	Node * currentNode = head;
	Node * previousNode;
	Node * nextNode;

	if(!head)
		return false;

	bool firstNode = true;
	
	while(currentNode)
	{
		if(currentNode->data == val)
			break;
		currentNode = currentNode->next;
		firstNode = false;
	}
	if(!currentNode)
		return false;

	if(!currentNode->next)
	{
		previousNode = currentNode->prev;
		previousNode->next = NULL;
		tail = previousNode;
	}
	else if(!firstNode)
	{
		nextNode = currentNode->next;
		previousNode = currentNode->prev;
		previousNode->next = nextNode;
		nextNode->prev = previousNode;
	}	
	else 
	{
		head = currentNode->next;
	}
	delete currentNode;
	return true;

}	

void LinkedList::printForward() const
{
	cout << "here are the values in forward order " << endl << endl; 
	Node* currentNode = head;

	while(currentNode->next)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

void LinkedList::printBackward() const
{
	cout << "here are the values in Backward order " << endl << endl;
	Node* currentNode = tail;
	
	while(currentNode->prev)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->prev;
	}
}
