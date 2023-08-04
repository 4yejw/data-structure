#pragma once
#include <iostream>
#define MAX 8
using namespace std;

class CircularQueue {
public:
	CircularQueue();
	~CircularQueue();
	void Enqueue(int Item);
	void Dequeue();
	int GetFront();
	void Init();
	int GetSize();
	bool IsEmpty();
	bool IsFull();
	void ShowQueue();

	int Front, Rear;
	int Queue[MAX];
	int Count;
};