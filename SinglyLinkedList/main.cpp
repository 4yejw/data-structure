#include "Singly_Linked_List.h"
int ShowOption() {
	int SelectedOption = 0;
	cout << "===================" << endl;
	cout << "1.Append" << endl;
	cout << "2.Insert" << endl;
	cout << "3.Delete" << endl;
	cout << "4.Retrieve" << endl;
	cout << "5.IsEmpty" << endl;
	cout << "6.Length" << endl;
	cout << "7.Init" << endl;
	cout << "8.ShowList" << endl;
	cout << "9.exit" << endl;
	cout << "===================" << endl;
	cout << "Choose Option:";
	cin >> SelectedOption;
	return SelectedOption;
}
int main() {
	bool KeepRunning = true;
	SLL L;
	while (KeepRunning) {
		int AppendValue = 0;
		int InsertPosition = 0;
		int InsertValue = 0;
		int DeletePosition = 0;
		int RetrievePosition = 0;

		switch (ShowOption()) {
		case 1:
			cout << "Append Value:";
			cin >> AppendValue;
			L.Append(AppendValue);
			cout << "Append Complete:: list = ";
			L.Showlist();
			break;
		case 2:
			cout << "Insert Position:";
			cin >> InsertPosition;
			cout << "Insert Value:";
			cin >> InsertValue;
			L.Insert(InsertPosition, InsertValue);
			cout << "Insert Complete:: list = ";
			L.Showlist();
			break;
		case 3:
			cout << "Delete Position:";
			cin >> DeletePosition;
			L.Delete(DeletePosition);
			cout << "Delete Complete:: list = ";
			L.Showlist();
			break;
		case 4:
			cout << "Retrieve Position:";
			cin >> RetrievePosition;
			cout << RetrievePosition << "th Value = " << L.int_Retrieve(RetrievePosition) << endl;
			break;
		case 5:
			if (L.IsEmpty())
				cout << "List is Empty" << endl;
			else
				cout << "List is not Empty" << endl;
			break;
		case 6:
			cout << "List Length = " << L.Length() << endl;
			break;
		case 7:
			L.Init();
			cout << "Init Complete :: list = ";
			L.Showlist();
			break;
		case 8:
			cout << "list = ";
			L.Showlist();
			break;
		case 9:
			KeepRunning = false;
			break;
		default:
			cout << "Option is out of range" << endl;
		}
	}
}