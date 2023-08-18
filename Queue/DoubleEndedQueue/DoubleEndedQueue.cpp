#include "DoubleEndedQueue.h"

DoubleEndedQueue::DoubleEndedQueue() {
	Head = NULL;
	Tail = NULL;
	Count = 0;
}
DoubleEndedQueue::~DoubleEndedQueue() {
	while (Count != 0) 
		RemoveFirst();
}
void DoubleEndedQueue::AddLast(element Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Prev = NULL;
	}
	else {
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = NewNode;
	}
	Count++;
}
void DoubleEndedQueue::AddFirst(element Item) {
	Nptr NewNode = new node;
	NewNode->Data = Item;
	NewNode->Prev = NULL;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Next = NULL;
	}
	else {
		Head->Prev = NewNode;
		NewNode->Next = Head;
		Head = NewNode;
	}
	Count++;
}
element DoubleEndedQueue::RemoveLast() {
	if (Count == 0)
		return -1;
	else if (Count == 1) {
		int value = Tail->Data;
		Nptr RemoveNode = Tail;
		Tail = NULL;
		Head = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
	else {
		int value = Tail->Data;
		Nptr RemoveNode = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
}
element DoubleEndedQueue::RemoveFirst() {
	if (Count == 0)
		return -1;
	else if (Count == 1) {
		int value = Head->Data;
		Nptr RemoveNode = Head;
		Tail = NULL;
		Head = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
	else {
		int value = Head->Data;
		Nptr RemoveNode = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		delete RemoveNode;
		Count--;
		return value;
	}
}
bool DoubleEndedQueue::IsEmpty() {
	return Count == 0;
}
element DoubleEndedQueue::GetFront() {
	if (Count == 0)
		return -1;
	else
		return Head->Data;
}
element DoubleEndedQueue::GetRear() {
	if (Count == 0)
		return -1;
	else
		return Tail->Data;
}
element DoubleEndedQueue::GetSize() {
	return Count;
}
void DoubleEndedQueue::Show() {
	cout << "DEQUE = [ ";
	Nptr temp = Head;
	while (temp != NULL) {
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "]";
}