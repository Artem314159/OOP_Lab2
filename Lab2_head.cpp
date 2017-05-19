#include <iostream>
#include <string>
#include <sstream>
#include "Lab2_head.h"
using namespace std;

void PushPopContainer::push(int elem){}
void IndexedContainer::set(int elem, unsigned int pos){}
void InsertableContainer::insertAt(int elem, unsigned int pos){}
void Deque::pushFront(int elem){}
void Deque::pushBack(int elem){}


const char* Stack::toString(){
	Node *sNode = current;
	string s = "";
	while(sNode)
	{
	    stringstream stream;
	    stream << sNode->value;
		s += stream.str() + ", ";
		sNode = sNode->next;
	}
	return s.c_str();
}

void Stack::push(int elem){
	Node *pushNode = new Node;
	pushNode->value = elem;
	pushNode->next = current;
	current = pushNode;
	size++;
}

int Stack::pop(){
	if (current != NULL)
	{
		int value = current->value;
		Node *popNode = current;
		current = current->next;
		delete popNode;
		return value;
		size--;
	}
	else return NULL;
}

int Stack::peek() const{
	return current->value;
}

const char* Queue::toString(){
	Node *sNode = head;
	string s = "";
	while(sNode)
	{
	    stringstream stream;
	    stream << sNode->value;
		s += stream.str() + ", ";
		sNode = sNode->prev;
	}
	return s.c_str();
}

void Queue::push(int elem){
	Node *pushNode = new Node;
	pushNode->value = elem;
	if (head != NULL)
	{
		current->prev = pushNode;
		current = current->prev;
		current->prev = NULL;
	}
	else
	{
		head = pushNode;
		current = pushNode;
		current->prev = NULL;
	}
	size++;
}

int Queue::pop(){
	if (head != NULL)
	{
		int value = head->value;
		Node *popNode = head;
		head = head->prev;
		if(head == NULL)
		{ 
			current = head;
		}
		delete popNode;
		size--;
		return value;
	}
	return NULL;
}

int Queue::peek() const{
	return head->value;
}

void LinkedList::push(int elem){
	Node *pushNode = new Node;
	pushNode->value = elem;
	pushNode->next = current;
	current = pushNode;
	InsertableContainer::size++;
}

int LinkedList::pop(){
	if (current != NULL)
	{
		int value = current->value;
		Node *popNode = current;
		current = current->next;
		delete popNode;
		InsertableContainer::size--;
		return value;
	}
	else return NULL;
}

int LinkedList::peek() const{
	return current->value;
}

void LinkedList::insertAt(int elem, unsigned int pos){
	if(pos < InsertableContainer::size)
	{ 
		Node *newNode = current;
		for(int i = 0; i < InsertableContainer::size - pos - 1; i++)
		{ newNode = newNode->next; }
		Node *insNode = new Node;
		insNode->value = elem;
		insNode->next = newNode->next;
		newNode->next = insNode;
		InsertableContainer::size++;
	}
	else push(elem);
}

int LinkedList::removeAt(unsigned int pos){
	int res = 0;
	if(pos < InsertableContainer::size - 1)
	{
		Node *newNode = current;
		for(int i = 0; i < InsertableContainer::size - pos - 2; i++)
		{ newNode = newNode->next; }
		res = newNode->next->value;
		newNode->next = newNode->next->next;
		InsertableContainer::size--;
	}
	else if(pos == InsertableContainer::size - 1)
		res = pop();
	return res;
}

int LinkedList::get(unsigned int pos) const{
	int res = 0;
	if(pos < InsertableContainer::size)
	{
		Node *getNode = current;
		for(int i = 0; i < InsertableContainer::size - pos - 1; i++)
			getNode = getNode->next;
		res = getNode->value;
	}
	return res;
}

void LinkedList::set(int elem, unsigned int pos){
	if(pos < InsertableContainer::size)
	{
		Node *getNode = current;
		for(int i = 0; i < InsertableContainer::size - pos - 1; i++)
			getNode = getNode->next;
		getNode->value = elem;
	}
	else push(elem);
}

const char* LinkedList::toString(){
	Node *sNode = current;
	string s = "";
	while(sNode)
	{
	    stringstream stream;
	    stream << sNode->value;
		s += stream.str() + ", ";
		sNode = sNode->next;
	}
	return s.c_str();
}

int StaticArray::get(unsigned int pos) const{
	int res = 0;
	if(pos < size)
	{
		Node *getNode = current;
		for(int i = 0; i < size - pos - 1; i++)
			getNode = getNode->next;
		res = getNode->value;
	}
	return res;
}

void StaticArray::set(int elem, unsigned int pos){
	if(pos < size)
	{
		Node *getNode = current;
		for(int i = 0; i < size - pos - 1; i++)
			getNode = getNode->next;
		getNode->value = elem;
	}
	else
	{
		if(pos < arrSize)
		{
			Node *pushNode = new Node;
			pushNode->value = elem;
			pushNode->next = current;
			current = pushNode;
			size++;
		}
	}
}

void StaticArray::setArrSize(int Size)
{ arrSize = Size; }

const char* StaticArray::toString(){
	Node *sNode = current;
	string s = "";
	while(sNode)
	{
	    stringstream stream;
	    stream << sNode->value;
		s += stream.str() + ", ";
		sNode = sNode->next;
	}
	return s.c_str();
}

void StaticDeque::setDeqSize(int Size)
{ deqSize = Size; }

void StaticDeque::pushFront(int elem){
	if(front != NULL)
	{
		if(size < deqSize)
		{
			Node *newNode = new Node;
			newNode->value = elem;
			newNode->next = front;
			front = newNode;
			size++;
		}
	}
	else
	{
		Node *newNode = new Node;
		newNode->value = elem;
		front = newNode;
		back = newNode;
	}
}

void StaticDeque::pushBack(int elem){
	if(back != NULL)
	{
		if(size < deqSize)
		{
			Node *newNode = new Node;
			newNode->value = elem;
			back->next = newNode;
			back = newNode;
			size++;
		}
	}
	else
	{
		Node *newNode = new Node;
		newNode->value = elem;
		front = newNode;
		back = newNode;
	}
}

int StaticDeque::popFront(){
	if (front != NULL)
	{
		int value = front->value;
		Node *popNode = front;
		front = front->next;
		delete popNode;
		return value;
		size--;
	}
	else return NULL;
}

int StaticDeque::popBack(){
	if (back != NULL)
	{
		int value = back->value;
		Node *popNode = front;
		for(int i = 0; i < size - 1; i++)
			popNode = popNode->next;
		popNode->next = NULL;
		back = popNode;
		return value;
		size--;
	}
	else return NULL;
}

int StaticDeque::peekFront() const {
	if(front != NULL)
		return front->value;
	return 0;
}

int StaticDeque::peekBack() const {
	if(front != NULL)
		return back->value;
	return 0;
}

const char* StaticDeque::toString(){
	Node *sNode = front;
	string s = "";
	while(sNode != back)
	{
		stringstream stream;
		stream << sNode->value;
		s += stream.str() + ", ";
		sNode = sNode->next;
	}
	if(back != NULL)
	{
	    stringstream stream;
	    stream << back->value;
		s += stream.str() + ", ";
	}
	return s.c_str();
}

