//Josephus 

#include "CircularQueue.h"
int main() {
	CircularQueue Q;

	int people = 0;
	while (1) {
		cout << "�������� ���� �Է��Ͻÿ�(�ִ� 100��):";
		cin >> people;
		if (people>0 && people<=MAX)
			break;
		cout << "��Ȯ�� �ο����� �Է��Ͻÿ�" << endl;
	}

	int range = 0;
	cout << "������ ������ �Է��Ͻÿ�:";
	cin >> range;

	for (int i = 1; i <= people; i++) 
		Q.Enqueue(i);
	

	for(int i=1;;i++) {
		if (i % range == 0)
			Q.Dequeue();
		else {
			int FrontValue = Q.GetFront();
			Q.Dequeue();
			Q.Enqueue(FrontValue);
		}
		if (Q.GetSize() < range)
			break;
	}

	if (Q.GetSize() == 0) 
		cout << "�����ڰ� �����ϴ�" << endl;
	else {
		cout << "������ = ";
		while (!Q.IsEmpty()) {
			cout << Q.GetFront()<<" ";
			Q.Dequeue();
		}
	}
}
