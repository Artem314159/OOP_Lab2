#ifndef LAB2_HEAD_H
#define LAB2_HEAD_H
#include <string>

class Container {
	protected:
		int size = 0;
	public:
		int getSize(){return size;}; // возвращает размер контейнера
		bool isEmpty() const{
			if(size == 0)
				return true;
			return false;
		};
		virtual const char* toString(){return "false";};
};

class PushPopContainer : public Container {
	public:
		virtual void push(int); // добавить элемент
		virtual int pop() {return 0;}; // забрать элемент
		virtual int peek() const {return 0;}; // узнать элемент
};

class Deque : public Container {
	virtual void pushFront(int); // добавить в начало
	virtual void pushBack(int); // добавить в конец
	virtual int popFront(){return 0;}; // забрать из начала
	virtual int popBack(){return 0;}; // забрать с конца
	virtual int peekFront() const{return 0;}; // узнать элемент в начале
	virtual int peekBack() const{return 0;}; // узнать элемент с конца
};

class IndexedContainer : public Container {
	virtual int get(unsigned int) const{return 0;}; // узнать элемент по индексу index
	virtual void set(int, unsigned int); // задать значение элементу
};

class InsertableContainer : public IndexedContainer {
	public:
		virtual void insertAt(int, unsigned int); // вставить элемент со сдвигом
		virtual int removeAt(unsigned int){return 0;}; // убрать элемент со сдвигом
};

class Stack : public PushPopContainer{
	private:
		struct Node{
			int value;
			Node *next;
		};
		Node *current = NULL;
	public:
		const char* toString(); // строка со всеми элементами
		void push(int); // добавить элемент
		int pop(); // забрать элемент
		int peek() const; // узнать элемент
};

class Queue : public PushPopContainer{
	private:
		struct Node{
			int value;                                    
 			Node *prev;
		};
		Node *head = NULL;
		Node *current = head;
	public:
		const char* toString(); // строка со всеми элементами
		void push(int); // добавить элемент
		int pop(); // забрать элемент
		int peek() const; // узнать элемент
};

class LinkedList : public PushPopContainer, public InsertableContainer{
	private:
		struct Node{
			int value;
			Node *next;
		};
		Node *current = NULL;
	public:
		const char* toString();
		void push(int); // добавить элемент
		int pop(); // забрать элемент
		int peek() const; // узнать элемент
		void insertAt(int, unsigned int); // вставить элемент со сдвигом
		int removeAt(unsigned int); // убрать элемент со сдвигом
		int get(unsigned int) const;//{return 0;}; // узнать элемент по индексу index
		void set(int, unsigned int); // задать значение элементу
};

class StaticArray : public IndexedContainer{
	private:
		unsigned int arrSize;
		struct Node{
			int value;
			Node *next;
		};
		Node *current = NULL;
	public:
		const char* toString();
		void setArrSize(int);
		int get(unsigned int) const;
		void set(int, unsigned int);
};

class StaticDeque : public Deque{
	private:
		unsigned int deqSize;
		struct Node{
			int value;
			Node *next;
		};
		Node *front = NULL, *back = front;
	public:
		const char* toString();
		void setDeqSize(int);
		void pushFront(int); // добавить в начало
		void pushBack(int); // добавить в конец
		int popFront(); // забрать из начала
		int popBack(); // забрать с конца
		int peekFront() const; // узнать элемент в начале
		int peekBack() const; // узнать элемент с конца
};

#endif
