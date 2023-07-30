#include "Doubly_Linked_List.h"
//������
DLL::DLL() {
	Count = 0;
	Head = NULL;
}
//�Ҹ���
DLL::~DLL() {
	while (!IsEmpty())
		Delete(1);
}
//�������� ��� �߰�
void DLL::Append(int Item) {
	Nptr NewNode = new Node; //���ο� ���
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Head == NULL) { //��尡 �ϳ��� ���� ��
		Head = NewNode;
		NewNode->Prev = Head;
	}
	else {
		Nptr tmp = Head;
		while (tmp->Next != NULL) { //������ ������ �̵��ϱ�
			tmp = tmp->Next;
		}
		tmp->Next = NewNode; //���ο� ��� �̾� ���̱�
		NewNode->Prev = tmp;
	}
	Count++;
}
//������ ��ġ�� ��� ����
void DLL::Insert(int Position, int Item) {
	Nptr NewNode = new Node; //���ο� ���
	NewNode->Data = Item;
	if (Position<1 || Position>Count+1) //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
	else {
		if (Position == 1) {//ù��° ��ġ�� ������ ��
			NewNode->Next = Head;
			Head = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = Head;
		}
		else if (Position == Count + 1) {//������ ��ġ�� ������ ��
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//������ ��ġ �ձ��� �̵�
				tmp = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Prev = tmp;
			NewNode->Next = NULL;
		}
		else {
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//������ ��ġ �ձ��� �̵�
				tmp = tmp->Next;
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = tmp;
		}
		Count++;
	}
}
//������ ��� ����
void DLL::Delete(int Position) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count) //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		Nptr DeleteNode = Head;
		if (Position == 1) {//ù��° ��带 ������ ��
			Head = tmp->Next;
			tmp->Next->Prev = Head;
		}
		else if (Position == Count ) {//������ ��带 ������ ��
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = NULL;
		}
		else {
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = DeleteNode->Next;
			DeleteNode->Next->Prev = tmp;
		}
		delete DeleteNode;
		Count--;
	}
}
//�˻��� ��ȯ
int DLL::int_Retrieve(int Position) {
	if (IsEmpty()) {
		cout << "List is Empty" << endl;
		return 0;
	}
	else if (Position<1 || Position>Count) { //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
		return 0;
	}
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Position; i++)
			tmp = tmp->Next;
		return tmp->Data;
	}
}
//�˻� ����
void DLL::void_Retrieve(int Position, int* Itemptr) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count)  //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Position; i++)
			tmp = tmp->Next;
		*Itemptr = tmp->Data;
	}
}
//�ʱ�ȭ
void DLL::Init() {
	Count = 0;
	Head = NULL;
}
//����
int DLL::Length() {
	return Count;
}
//����ִ��� Ȯ��
bool DLL::IsEmpty() {
	return Count == 0;
}
//����Ʈ ��ü ���
void DLL::Showlist() {
	cout << "[ ";
	Nptr tmp = Head;
	for (int i = 0; i < Count; i++) {
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << "]" << endl;
}