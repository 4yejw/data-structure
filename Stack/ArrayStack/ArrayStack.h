#pragma once
#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

class StackClass {
public:
	StackClass();
	~StackClass();
	void Push(int Item);
	void Pop();
	int GetTop();
	void Init();
	bool IsEmpty();
	bool IsFull();
	void ShowStack();
private:
	int Top; //stack top index
	int Stack[MAX];
};