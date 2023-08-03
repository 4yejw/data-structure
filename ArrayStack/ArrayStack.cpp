#include "ArrayStack.h"
StackClass::StackClass() {
	Top = -1;
}
StackClass::~StackClass() {
}
void StackClass::Push(int Item) {
	if (IsFull())
		cout << "Stack is full" << endl;
	else {
		Top++;
		Stack[Top] = Item;
	}
}
void StackClass::Pop() {
	if (IsEmpty())
		cout << "Stack is Empty" << endl;
	else
		Top--;
}
int StackClass::GetTop() {
	return Stack[Top];
}
void StackClass::Init() {
	Top = -1;
}
bool StackClass::IsEmpty() {
	return Top == -1;
}
bool StackClass::IsFull() {
	return Top == MAX - 1;
}
void StackClass::ShowStack() {
	cout << "[ ";
	for (int i = 0; i <= Top; i++) 
		cout << Stack[i] << " ";
	cout << "]" << endl;
}