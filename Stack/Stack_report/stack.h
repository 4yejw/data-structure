//stack.h
#pragma once //�ߺ� ȣ�� ����
#include "list.h" //����Ʈ �������̽������� ����

class stackClass {
public:
	stackClass(); //������ �Լ�
	~stackClass(); //�Ҹ��� �Լ�
	void Push(char Item); //char ���� Item���� stack�� ����
	void Push(int Item); //Int���� Item���� stack�� ����
	void Pop(); //���� ž�� �����Ͱ��� ����
	char GetTop(); //���� ž�� ������ ���� ����
	bool IsEmpty(); //������ ����ִ��� Ȯ��
	void Showstack(); //���� ������ data�� ���(char)
	void Showintstack(); //���� ������ data�� ���(int)
	int Length();
	bool IsFull(); //������ �� ���ִ��� Ȯ��
private:
	listClass L; //����Ʈ ��ü L
};