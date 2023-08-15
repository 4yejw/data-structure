
#pragma once
#include <iostream> 
using namespace std;


typedef struct nodeRecord {
	int Key; 
	nodeRecord* LChild;  
	nodeRecord* RChild; 
}node;

typedef node* Nptr;  

//����
Nptr Insert(Nptr T, int key);
//������ȸ
void PreOrder(Nptr T);
//������ȸ 
void InOrder(Nptr T);
//������ȸ
void PostOrder(Nptr T);
//���� 
void Delete(Nptr& T, int key);