//Josephus 

#include "CircularQueue.h"
int main() {
	CircularQueue Q;

	int people = 0;
	while (1) {
		cout << "유대인의 수를 입력하시오(최대 100명):";
		cin >> people;
		if (people>0 && people<=MAX)
			break;
		cout << "정확한 인원수를 입력하시오" << endl;
	}

	int range = 0;
	cout << "제거할 단위를 입력하시오:";
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
		cout << "생존자가 없습니다" << endl;
	else {
		cout << "생존자 = ";
		while (!Q.IsEmpty()) {
			cout << Q.GetFront()<<" ";
			Q.Dequeue();
		}
	}
}
