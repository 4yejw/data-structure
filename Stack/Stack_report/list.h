//list.h
#pragma once //�ߺ� ȣ�� ����
#include <iostream> //c++ǥ�� ����� ������� 
using namespace std; //std�̸� ������ ����� ��� �̸��� std::����

const int MAX = 100; //�迭�� ũ�⸦ MAX�� ������

class listClass { //class����
public:
	listClass(); //������(�ʱ�ȭInit�� ����)
	~listClass(); //�Ҹ���
	void Insert(int Position, char Item); //char����
	void Insert(int Position, int Item); //int ����
	void Delete(int Position); //����
	int Length(); //����Ʈ ���� ��ȯ
	void Retrieve(int Position, char& Item); //�˻� �� char data ����
	void Retrieve(int Position, int& Item); //�˻� �� int data ����
	bool IsEmpty(); //����ִ��� Ȯ��
	bool IsFull(); //�� ���ִ��� Ȯ��
	void Showdata(); //Data ��� (char data)
	void Showintdata(); //IntData ��� (int data)
	
private:
	int Count = 0; //�迭���� ��ȿ�� ���� ����
	char Data[MAX]; //char data�� ������ �迭
	int IntData[MAX]; //int data�� ������ �迭
};