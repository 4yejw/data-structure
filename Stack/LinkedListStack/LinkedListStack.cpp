#include "LinkedListStack.h"
StackClass::StackClass() {
	Top = NULL;
}
StackClass::~StackClass() {
	while (!IsEmpty())
		Pop();
}
void StackClass::Push(int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	NewNode->Next = Top;
	Top = NewNode;
}
void StackClass::Pop() {
	if (IsEmpty())
		cout << "Stack is Empty" << endl;
	else {
		Nptr DeleteNode = Top;
		Top = Top->Next;
		delete DeleteNode;
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
	return Top == NULL;
}
void StackClass::ShowStack() {
	Nptr temp = Top;
	cout << "[ ";
	while(temp !=NULL){
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "]" << endl;
}