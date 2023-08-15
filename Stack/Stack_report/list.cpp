//list.cpp
#include "list.h" //����Ʈ �������̽� ������ ����

//������
listClass::listClass() :Count(0) {} //Count �� 0���� �ʱ�ȭ

//�Ҹ���
listClass::~listClass() {} //�Ҹ��ڴ� �� ���� ����

//char Item ����
void listClass::Insert(int Position, char Item) {
	if (Count == MAX)//�迭�� �� á�� �� 
		cout << "������ �� �ִ� ������ �����ϴ�" << endl;
	else if (Position<1 || Position>(Count + 1)) //�߸��� ��ġ�� �����Ϸ��� �Ҷ�
		cout << "�ش� ��ġ�� ������ �� �����ϴ�" << endl;
	else {
		for (int i = Count; i > Position - 1; i--) //�ڿ������� ������ ��ġ������ �ϳ��� ���������� �̵�
			Data[i] = Data[i - 1];
		Data[Position - 1] = Item; //������ ��ġ�� ������ ����
		Count++; //���� +1
	}
}

//int Item ����
void listClass::Insert(int Position, int Item) {
	if (Count == MAX) //�迭�� �� á�� �� 
		cout << "������ �� �ִ� ������ �����ϴ�" << endl;
	else if (Position<1 || Position>(Count + 1)) //�߸��� ��ġ�� �����Ϸ��� �Ҷ�
		cout << "�ش� ��ġ�� ������ �� �����ϴ�" << endl;
	else {
		for (int i = Count; i > Position - 1; i--) //�ڿ������� ������ ��ġ������ �ϳ��� ���������� �̵�
			IntData[i] = IntData[i - 1];
		IntData[Position - 1] = Item; //������ ��ġ�� ������ ����
		Count++; //���� +1
	}
}

//���� 
void listClass::Delete(int Position) {
	if (Position < 1 || Position >= (Count + 1)) //�߸��� ��ġ�� �����Ϸ��� �Ҷ� 
		cout << "�ش� ��ġ�� ������ �� �����ϴ�" << endl;
	else {
		for (int i = Position - 1; i < Count - 1; i++) { //�����Ϸ��� �� �ں��� �ϳ��� �������� �̵�
			Data[i] = Data[i + 1];
			IntData[i] = IntData[i + 1];
		}
		Count--; //���� -1
	}
}

//����Ʈ ���� ���
int listClass::Length() {
	return Count;
}

//�˻� �� ������ ���� (char data)
void listClass::Retrieve(int Position, char& Item) {
	if (Position < 1 || Position >= (Count + 1)) //�߸��� ��ġ�� �����Ϸ��� �Ҷ�
		cout << "�ش� ��ġ�� ������ �� �����ϴ�" << endl;
	else {
		Item = Data[Position - 1]; //�˻��� �����͸� ����
	}
}

//�˻� �� ������ ���� (int data)
void listClass::Retrieve(int Position, int& Item) {
	if (Position < 1 || Position >= (Count + 1)) //�߸��� ��ġ�� �����Ϸ��� �Ҷ�
		cout << "�ش� ��ġ�� ������ �� �����ϴ�" << endl;
	else {
		Item = IntData[Position - 1]; //�˻��� �����͸� ����
	}
}

//����ִ��� Ȯ��
bool listClass::IsEmpty() {
	return (Count == 0); //Count�� 0�̸� true��ȯ
}

//�� ���ִ��� Ȯ��
bool listClass::IsFull() {
	return (Count == MAX); //Count �� MAX�̸� true��ȯ
}

//���� ����Ʈ ������ ��� (char data)
void listClass::Showdata() {
	cout << "stack = [ ";
	for (int i = 0; i < Count; i++) {
		cout << Data[i] << ' ';
	}
	cout << "]" << endl;
}

//���� ����Ʈ ������ ��� (int data)
void listClass::Showintdata() {
	cout << "¦�� ���� �߰�ȣ�� ��ġ�� ���ι�ȣ :";
	for (int i = 0; i < Count; i++) {
		cout << IntData[i] << "�� ";
	}
	cout << endl;
}
