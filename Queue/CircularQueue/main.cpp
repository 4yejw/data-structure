#include "CircularQueue.h"
int ShowOption() {
	int SelectedOption = 0;
	cout << "===================" << endl;
	cout << "1.Enqueue" << endl;
	cout << "2.Dequeue" << endl;
	cout << "3.GetFront" << endl;
	cout << "4.Init" << endl;
	cout << "5.GetSize" << endl;
	cout << "6.IsEmpty" << endl;
	cout << "7.IsFull" << endl;
	cout << "8.ShowQueue" << endl;
	cout << "9.exit" << endl;
	cout << "===================" << endl;
	cout << "Choose Option:";
	cin >> SelectedOption;
	return SelectedOption;
}
int main() {
	bool KeepRunning = true;
	CircularQueue Q;
	while (KeepRunning) {
		int EnqueueValue = 0;
		int FrontValue = 0;

		switch (ShowOption()) {
		case 1://EnQueue
			cout << "Enqueue Value:";
			cin >> EnqueueValue;
			Q.Enqueue(EnqueueValue);
			cout << "Enqueue Complete:: Queue = ";
			Q.ShowQueue();
			break;
		case 2://Dequeue
			Q.Dequeue();
			cout << "Dequeue Complete:: Queue = ";
			Q.ShowQueue();
			break;
		case 3://GetFront
			cout << "Front Value = " << Q.GetFront() << endl;
			break;
		case 4://Init
			Q.Init();
			cout << "Init Complete:: Queue = ";
			Q.ShowQueue();
			break;
		case 5: //GetSize
			cout << "Size = " << Q.GetSize() << endl;
			break;
		case 6://IsEmpty
			if (Q.IsEmpty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is not Empty" << endl;
			break;
		case 7://IsFull
			if (Q.IsFull())
				cout << "Queue is Full" << endl;
			else
				cout << "Queue is not Full" << endl;
			break;
		case 8://ShowQueue
			cout << "Queue = ";
			Q.ShowQueue();
			break;
		case 9://exit
			KeepRunning = false;
			Q.Init();
			break;
		default:
			cout << "Option is out of range" << endl;
		}
	}
}