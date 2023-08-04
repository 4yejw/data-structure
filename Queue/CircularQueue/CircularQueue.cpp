#include "CircularQueue.h"

CircularQueue::CircularQueue() {
	Front = 0;
	Rear = -1;
	Count = 0;
}
CircularQueue::~CircularQueue() {
}
void CircularQueue::Enqueue(int Item) {
	if (IsFull()) {
		cout << "Queue is Full" << endl;
	}
	else {
		Rear = (Rear + 1) % MAX;
		Queue[Rear] = Item;
		Count++;
	}
}
void CircularQueue::Dequeue() {
	if (IsEmpty())
		cout << "Queue is Empty" << endl;
	else {
		Front = (Front + 1) % MAX;
		Count--;
	}
}
int CircularQueue::GetFront() {
	return Queue[Front];
}
void CircularQueue::Init() {
	Front = 0;
	Rear = -1;
	Count = 0;
}
int CircularQueue::GetSize() {
	return Count;
}
bool CircularQueue::IsEmpty() {
	return Count == 0;
}
bool CircularQueue::IsFull() {
	return Count == MAX;
}
void CircularQueue::ShowQueue() {
	cout<<"[ ";
	if (Count==0) { 
		cout << " ";
	}
	else if((Front<=Rear)&&!(Count == 0)){
		for (int i = Front; i <= Rear; i++) 
			cout << Queue[i] << " ";
	}
	else if ((Front > Rear) && !(Count == 0)) {
		for (int i = Front; i < MAX; i++)
			cout << Queue[i] << " ";
		for (int i = 0; i <= Rear; i++)
			cout << Queue[i] << " ";
	}
	cout << "]" << " Front = " << Front << " Rear = " << Rear << " Count = " << Count << endl;
}