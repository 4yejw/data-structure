//BraceMatch.cpp
#pragma once //�ߺ� ȣ�� ����
#include "stack.h" //stack �������̽� ������ ����
#include <fstream> //���� ������Ҷ� �ʿ�
#include <string> //���ڿ� ����Ҷ� �ʿ�

int main() {
	string text; 

	ifstream file; //���� �Է� ��ü ����
	file.open("text.txt"); //"text.txt" ���� ����
	
	stackClass S; //stackClass ��ü S���� (char data stack)
	stackClass Int; //stackClass ��ü Int���� (int data stack)

	if (file.is_open()) { //������ �� �� ������ true�� ��ȯ
	
		int count = 1; //���ι�ȣ�� 1���� ����
		while (!file.eof()) { //������ �� ����
			getline(file, text); //������ file�� ���پ� string text�� ����
			cout << text << endl;

			int index = 0; //�迭 �ε����� ������ ����
			while (index < text.length()) { //text ��ü ���̵���
				if (text[index] == '{') { //text�� � ���ڰ� '{'�̸�
					S.Push('{'); //char data stack�� '{'�� Push
					Int.Push(count); //int data stack�� ���ι�ȣ�� Push
				}
				else if (text[index] == '}') { //text�� � ���ڰ� '}'�̰�
					if (!S.IsEmpty()) { //stack�� ������� ������
						S.Pop(); //char data stack�� Pop
						Int.Pop(); //int data stack�� Pop
					}
				}
				index++; //�ε��� ����
			}
			count++; //���ι�ȣ ����
		}
		file.close();
	}
	else { //������ �� �� ���� ��
		cout << "������ �� �� �����ϴ�\n"; //�����޼����� ����Ѵ�
		return 1;
	}
	cout << endl;
	S.Showstack(); //char data stack ��� (¦�̾��� �߰�ȣ)
	Int.Showintstack(); //int data stack ��� (¦�̾��� �߰�ȣ�� ���ι�ȣ)
}

