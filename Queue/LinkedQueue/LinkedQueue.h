#pragma once
#include <iostream>
using namespace std;

typedef struct nodeRecord {
	int Data;
	struct nodeRecord* Next;
}node;

typedef node* Nptr;

class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	void Enqueue(int Item);
	void Dequeue();
	int GetFront();
	int GetSize();
	bool IsEmpty();
	void Init();
	void ShowQueue();
private:
	Nptr Front;
	Nptr Rear;
	int Count;
};