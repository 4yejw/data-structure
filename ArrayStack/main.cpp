#include "ArrayStack.h"
int ShowOption() {
	int SelectedOption = 0;
	cout << "===================" << endl;
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.GetTop" << endl;
	cout << "4.Init" << endl;
	cout << "5.IsEmpty" << endl;
	cout << "6.IsFull" << endl;
	cout << "7.ShowStack" << endl;
	cout << "8.exit" << endl;
	cout << "===================" << endl;
	cout << "Choose Option:";
	cin >> SelectedOption;
	return SelectedOption;
}
int main() {
	bool KeepRunning = true;
	StackClass S;
	while (KeepRunning) {
		int PushValue = 0;
		int TopValue = 0;

		switch (ShowOption()) {
		case 1://Push
			cout << "Push Value:";
			cin >> PushValue;
			S.Push(PushValue);
			cout << "Push Complete:: Stack = ";
			S.ShowStack();
			break;
		case 2://Pop
			S.Pop();
			cout << "Pop Complete:: Stack = ";
			S.ShowStack();
			break;
		case 3://GetTop
			cout << "Top Value = "<<S.GetTop()<<endl;
			break;
		case 4://Init
			S.Init();
			cout << "Init Complete:: Stack = ";
			S.ShowStack();
			break;
		case 5://IsEmpty
			if (S.IsEmpty())
				cout << "Stack is Empty" << endl;
			else
				cout << "Stack is not Empty" << endl;
			break;
		case 6://IsFull
			if (S.IsFull())
				cout << "Stack is Full" << endl;
			else
				cout << "Stack is not Full" << endl;
			break;
		case 7://ShowStack
			cout << "Stack = ";
			S.ShowStack();
			break;
		case 8://exit
			KeepRunning = false;
			break;
		default:
			cout << "Option is out of range" << endl;
		}
	}
}