#include "BinarySearchTree.h"

//����
Nptr Insert(Nptr T, int key) {
	if (T == NULL) {  //�� �̻� ���� ��尡 ���� ��� (�������)
		T = new node;  //������ �� ��带 ����� 
		T->Key = key;  //�� ����� Key������ �����Ϸ��� ���� �ִ´�
		T->LChild = NULL;  //������� �̹Ƿ� NULL�� �ִ´�
		T->RChild = NULL;  //������� �̹Ƿ� NULL�� �ִ´�
	}
	else if (T->Key > key)  //�����Ϸ��� ���� ���� ��� ������ ������
		T->LChild = Insert(T->LChild, key);  //�������� �̵�
	else   //�����Ϸ��� ���� ���� ��� ������ ũ�ų� ������
		T->RChild = Insert(T->RChild, key);  //���������� �̵�
	return T;
}

//������ȸ PreOrder
void PreOrder(Nptr T) {
	if (T != NULL) {
		cout << T->Key << ' ';  //key�� ���
		PreOrder(T->LChild);  //���� ���ȣ��
		PreOrder(T->RChild);  //������ ���ȣ��
	}
}

//������ȸ InOrder
void InOrder(Nptr T) {
	if (T != NULL) {
		InOrder(T->LChild);  //���� ���ȣ��
		cout << T->Key << ' ';  //key�� ���
		InOrder(T->RChild);  //������ ���ȣ��
	}
}

//������ȸ PostOrder
void PostOrder(Nptr T) {
	if (T != NULL) {
		PostOrder(T->LChild);  //���� ���ȣ��
		PostOrder(T->RChild);  //������ ���ȣ��
		cout << T->Key << ' ';  //key�� ���
	}
}

//���� 
void Delete(Nptr& T, int key) {
	if (T == NULL)  //�����Ϸ��� ���� ��ã������ 
		cout << "�����Ϸ��� �� " << key << "�� �����ϴ�" << endl;
	else if (T->Key > key)  //�����Ϸ��� ���� ���� ����� key������ ���� �� 
		Delete(T->LChild, key);
	else if (T->Key < key)  //�����Ϸ��� ���� ���� ����� key������ Ŭ ��
		Delete(T->RChild, key);
	else if (T->Key == key) {  //�����Ϸ��� ���� ���� ����� key���� ��ġ�� ��
		if ((T->LChild == NULL) && (T->RChild == NULL)) {//�����Ϸ��� ��忡 �ڽ��� �ϳ������� ���
			Nptr tmp = T;  //node ������ tmp�� �����Ϸ��� ��带 ����Ŵ
			T = NULL;  //T�� �׸� ����Ű�� ��
			delete tmp;  //��带 ����
		}
		else if (T->LChild == NULL) {//�����Ϸ��� ��忡 ������ �ڽĸ� �ִ� ���
			Nptr tmp = T;  //node ������ tmp�� �����Ϸ��� ��带 ����Ŵ
			T = T->RChild;  //�θ�(T)�� �ڽ��� ����Ŵ
			delete tmp;  //��带 ����
		}
		else if (T->RChild == NULL) {//�����Ϸ��� ��忡 ���� �ڽĸ� �ִ� ���
			Nptr tmp = T;  //node ������ tmp�� �����Ϸ��� ��带 ����Ŵ
			T = T->LChild;  //�θ�(T)�� �ڽ��� ����Ű�� ��
			delete tmp;  //��带 ����
		}
		else { //�����Ϸ��� ��忡 �ڽ��� ���� ���
			Nptr tmp = T;  //node ������ tmp�� �����Ϸ��� ��带 ����Ŵ
			tmp = tmp->RChild;  //�����ļ��ڸ� ã������ ���������� �ѹ� �̵�
			while (tmp->LChild != NULL) //LChild�� NULL�϶����� �������� �̵�
				tmp = tmp->LChild;
			int tmp_Key = 0; //�����ļ��� ��尡 ����Ű�� key���� ������ ����
			tmp_Key = tmp->Key;  //key���� ���� ����
			Delete(T, tmp->Key);  //�����ļ��� ��带 ����
			T->Key = tmp_Key;  //�����Ϸ��� ����� Key���� �����ļ��� ����� key������ ����
		}
	}
}
