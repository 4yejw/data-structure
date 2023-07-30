#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct NodeRecord {
	int Data;
	struct NodeRecord* Next;
}Node;

typedef Node* Nptr;

class SLL{
public:
	SLL(); 
	~SLL(); 
	void Append(int Item);
	void Insert(int Position, int Item);
	void Delete(int Position);
	int int_Retrieve(int Position);
	void void_Retrieve(int Position, int* Itemptr);
	void Init();
	int Length();
	bool IsEmpty();
	void Showlist();
private:
	int Count;
	Nptr Head;
};
