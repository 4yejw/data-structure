#include "BinarySearchTree.h"

void main() {
	Nptr R = NULL;

	//���� �����Ͽ� ����Ʈ���� �����
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

	cout << "������ȸ : ";
	InOrder(R);  //���� ��ȸ 
	cout << endl;

	cout << "������ȸ : ";
	PreOrder(R);  //���� ��ȸ
	cout << endl;

	cout << "������ȸ : ";
	PostOrder(R);  //���� ��ȸ 
	cout << endl << endl;

	cout << "92 �� 81�� �����մϴ�" << endl << endl;

	Delete(R, 92); //key���� 92�� ��带 �����Ѵ�
	Delete(R, 81); //key���� 81�� ��带 �����Ѵ�

	cout << "������ȸ : ";
	InOrder(R);  //���� ��ȸ
	cout << endl;

	cout << "������ȸ : ";
	PreOrder(R);  //���� ��ȸ 
	cout << endl;

	cout << "������ȸ : ";
	PostOrder(R);  //���� ��ȸ 
	cout << endl;
}