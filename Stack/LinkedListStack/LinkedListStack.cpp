#include "LinkedListStack.h"
StackClass::StackClass() {
	Top = NULL;
	Count = 0;
}
StackClass::~StackClass() {
	while (!IsEmpty())
		Pop();
}
void StackClass::Push(int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	if (Count==0) { 
		NewNode->Next = NewNode;
		NewNode->Prev = NewNode;
	}
	else {
		NewNode->Next = Top;
		NewNode->Prev = Top->Prev;
		Top->Prev->Next = NewNode;
		Top->Prev = NewNode;
	}
	Top = NewNode;
	Count++;
}
void StackClass::Pop() {
	if (IsEmpty())
		cout << "Stack is Empty" << endl;
	else {
		Nptr DeleteNode = Top;
		Top->Next->Prev = Top->Prev;
		Top->Prev = Top->Next;
		Top = Top->Next;
		delete DeleteNode;
		Count--;
	}
}
int StackClass::GetTop() {
	return Top->Data;
}
void StackClass::Init() {
	while (!IsEmpty())
		Pop();
}
bool StackClass::IsEmpty() {
	return Count==0;
}
int StackClass::Size() {
	return Count;
}
void StackClass::ShowStack() {
	Nptr temp = Top;
	cout << "[ ";
	for (int i = 0; i < Count;i++) {
		temp = temp->Prev;
		cout << temp->Data << " ";
	}
	cout << "]" << endl;
}