//stack.cpp
#include "stack.h" //���� �������̽� ������ ����

 //������ �Լ�
stackClass::stackClass() { //������ ���� ����
}

//�Ҹ��� �Լ�
stackClass::~stackClass() {
	while(!IsEmpty()) //stack�� ��������
		L.Delete(L.Length()); //������ ���� ����
}

//char���� Item���� stack�� ����
void stackClass::Push(char Item) {
	L.Insert(L.Length()+1, Item); //������ ������ Item�� ����
}

//Int���� Item���� stack�� ����
void stackClass::Push(int Item) {
	L.Insert(L.Length()+1, Item); //������ ������ Item�� ����
}
//���� ž�� �����Ͱ��� ����
void stackClass::Pop() {
	L.Delete(L.Length()); //������ ���� ����
}

//���� ž�� ������ ���� ����
char stackClass::GetTop() {
	char Item;
	L.Retrieve(L.Length(), Item); //������ ���� ����
	return Item;
}
 
//������ ����ִ��� Ȯ��
bool stackClass::IsEmpty() {
	return bool (L.IsEmpty());
}

//���� ������ data�� ���(char)
void stackClass::Showstack() {
	L.Showdata();
}

//���� ������ data�� ���(int)
void stackClass::Showintstack() {
	L.Showintdata();
}

int stackClass::Length() {
	return L.Length();
}

bool stackClass::IsFull() {
	return L.IsFull();
}