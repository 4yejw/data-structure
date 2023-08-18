#pragma once
#include <iostream>
using namespace std;

typedef int element;

typedef struct nodeRecord {
	element Data;
	struct nodeRecord* Next;
	struct nodeRecord* Prev;
}node;

typedef node* Nptr;

class DoubleEndedQueue {
public:
	DoubleEndedQueue();
	~DoubleEndedQueue();
	void AddLast(element Item);//stack
	void AddFirst(element Item);//Queue 
	element RemoveLast();//Queue
	element RemoveFirst();//stack
	bool IsEmpty();
	element GetFront();
	element GetRear();
	element GetSize();
	void Show();
private:
	Nptr Head;
	Nptr Tail;
	int Count;
};