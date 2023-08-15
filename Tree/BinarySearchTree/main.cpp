#include "BinarySearchTree.h"

void main() {
	Nptr R = NULL;

	//값을 삽입하여 이진트리를 만든다
	R = Insert(R, 32);
	R = Insert(R, 94);
	R = Insert(R, 76);
	R = Insert(R, 24);
	R = Insert(R, 92);
	R = Insert(R, 17);
	R = Insert(R, 39);
	R = Insert(R, 62);
	R = Insert(R, 54);
	R = Insert(R, 81);
	R = Insert(R, 27);

	cout << "중위순회 : ";
	InOrder(R);  //중위 순회 
	cout << endl;

	cout << "전위순회 : ";
	PreOrder(R);  //전위 순회
	cout << endl;

	cout << "후위순회 : ";
	PostOrder(R);  //후위 순회 
	cout << endl << endl;

	cout << "92 와 81을 삭제합니다" << endl << endl;

	Delete(R, 92); //key값이 92인 노드를 삭제한다
	Delete(R, 81); //key값이 81인 노드를 삭제한다

	cout << "중위순회 : ";
	InOrder(R);  //중위 순회
	cout << endl;

	cout << "전위순회 : ";
	PreOrder(R);  //전위 순회 
	cout << endl;

	cout << "후위순회 : ";
	PostOrder(R);  //후위 순회 
	cout << endl;
}