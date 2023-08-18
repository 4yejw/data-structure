#include "LinkedQueue.h"
LinkedQueue::LinkedQueue() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
LinkedQueue::~LinkedQueue() {
	Init();
}
void LinkedQueue::Enqueue(int Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (IsEmpty()) 
		Front = NewNode;
	else 
		Rear->Next = NewNode;
	Rear = NewNode;
	Count++;
}
void LinkedQueue::Dequeue() {
	if (IsEmpty())
		cout << "Queue is Empty" << endl;
	else {
		Nptr DequeueNode = Front;
		Front = Front->Next;
		delete DequeueNode;
		Count--;
	}
}
int LinkedQueue::GetFront() {
	if(IsEmpty()){
		cout << "Queue is Empty" << endl;
		return 0;
	}
	else 
		return Front->Data;
}
int LinkedQueue::GetSize() {
	return Count;
}
bool LinkedQueue::IsEmpty() {
	return Count == 0;
}
void LinkedQueue::Init() {
	while (!IsEmpty())
		Dequeue();
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
void LinkedQueue::ShowQueue() {
	cout << "[ ";
	Nptr temp = Front;
	while (temp != NULL) {
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "]" << endl;
}
