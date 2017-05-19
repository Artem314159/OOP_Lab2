#ifndef LAB2_HEAD_H
#define LAB2_HEAD_H
#include <string>

class Container {
	protected:
		int size = 0;
	public:
		int getSize(){return size;}; // ���������� ������ ����������
		bool isEmpty() const{
			if(size == 0)
				return true;
			return false;
		};
		virtual const char* toString(){return "false";};
};

class PushPopContainer : public Container {
	public:
		virtual void push(int); // �������� �������
		virtual int pop() {return 0;}; // ������� �������
		virtual int peek() const {return 0;}; // ������ �������
};

class Deque : public Container {
	virtual void pushFront(int); // �������� � ������
	virtual void pushBack(int); // �������� � �����
	virtual int popFront(){return 0;}; // ������� �� ������
	virtual int popBack(){return 0;}; // ������� � �����
	virtual int peekFront() const{return 0;}; // ������ ������� � ������
	virtual int peekBack() const{return 0;}; // ������ ������� � �����
};

class IndexedContainer : public Container {
	virtual int get(unsigned int) const{return 0;}; // ������ ������� �� ������� index
	virtual void set(int, unsigned int); // ������ �������� ��������
};

class InsertableContainer : public IndexedContainer {
	public:
		virtual void insertAt(int, unsigned int); // �������� ������� �� �������
		virtual int removeAt(unsigned int){return 0;}; // ������ ������� �� �������
};

class Stack : public PushPopContainer{
	private:
		struct Node{
			int value;
			Node *next;
		};
		Node *current = NULL;
	public:
		const char* toString(); // ������ �� ����� ����������
		void push(int); // �������� �������
		int pop(); // ������� �������
		int peek() const; // ������ �������
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
		const char* toString(); // ������ �� ����� ����������
		void push(int); // �������� �������
		int pop(); // ������� �������
		int peek() const; // ������ �������
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
		void push(int); // �������� �������
		int pop(); // ������� �������
		int peek() const; // ������ �������
		void insertAt(int, unsigned int); // �������� ������� �� �������
		int removeAt(unsigned int); // ������ ������� �� �������
		int get(unsigned int) const;//{return 0;}; // ������ ������� �� ������� index
		void set(int, unsigned int); // ������ �������� ��������
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
		void pushFront(int); // �������� � ������
		void pushBack(int); // �������� � �����
		int popFront(); // ������� �� ������
		int popBack(); // ������� � �����
		int peekFront() const; // ������ ������� � ������
		int peekBack() const; // ������ ������� � �����
};

#endif
