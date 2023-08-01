#include "CircularDoublyLinkedList.h"
//������
CDLL::CDLL() {
	Count = 0;
	Head = NULL;
}
//�Ҹ���
CDLL::~CDLL() {
	while (!IsEmpty())
		Delete(1);
}
//�������� ��� �߰�
void CDLL::Append(int Item) {
	Nptr NewNode = new Node; //���ο� ���
	NewNode->Data = Item;

	if (Head == NULL) { //��尡 �ϳ��� ���� ��
		Head = NewNode;
		NewNode->Prev = NewNode;
		NewNode->Next = NewNode;
	}
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Count; i++)
			tmp = tmp->Next;
		NewNode->Next = tmp->Next;
		tmp->Next = NewNode; //���ο� ��� �̾� ���̱�
		NewNode->Prev = tmp;
		Head->Prev = NewNode;
	}
	Count++;
}
//������ ��ġ�� ��� ����
void CDLL::Insert(int Position, int Item) {
	Nptr NewNode = new Node; //���ο� ���
	NewNode->Data = Item;
	if (Position<1 || Position>Count + 1) //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
	else {
		if (Position == 1) {//ù��° ��ġ�� ������ ��
			NewNode->Next = Head;
			Head = NewNode;
			NewNode->Prev = NewNode->Next->Prev;
			NewNode->Next->Prev = NewNode;
		}
		else if (Position == Count + 1) {//������ ��ġ�� ������ ��
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//������ ��ġ �ձ��� �̵�
				tmp = tmp->Next;
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Prev = tmp;
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
void CDLL::Delete(int Position) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count) //�������� ��ġ�� ������ ��
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		Nptr DeleteNode = Head;
		if (Position == 1) {//ù��° ��带 ������ ��
			Head = tmp->Next;
			tmp->Next->Prev = tmp->Prev;
			tmp->Prev->Next = tmp->Next;
		}
		else if (Position == Count) {//������ ��带 ������ ��
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = DeleteNode->Next;
			Head->Prev = tmp;
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
int CDLL::int_Retrieve(int Position) {
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
void CDLL::void_Retrieve(int Position, int* Itemptr) {
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
void CDLL::Init() {
	Count = 0;
	Head = NULL;
}
//����
int CDLL::Length() {
	return Count;
}
//����ִ��� Ȯ��
bool CDLL::IsEmpty() {
	return Count == 0;
}
//����Ʈ ��ü ���
void CDLL::Showlist() {
	cout << "[ ";
	Nptr tmp = Head;
	for (int i = 0; i < Count; i++) {
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << "]" << endl;
}
