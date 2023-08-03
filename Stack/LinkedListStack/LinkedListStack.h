#pragma once
#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

typedef struct nodeRecord{
	int Data;
	struct nodeRecord* Next;
}Node;

typedef Node* Nptr;

class StackClass {
public:
	StackClass();
	~StackClass();
	void Push(int Item);
	void Pop();
	int GetTop();
	void Init();
	bool IsEmpty();
	void ShowStack();
private:
	Nptr Top; //stack top
};