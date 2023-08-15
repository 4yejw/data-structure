
#pragma once
#include <iostream> 
using namespace std;


typedef struct nodeRecord {
	int Key; 
	nodeRecord* LChild;  
	nodeRecord* RChild; 
}node;

typedef node* Nptr;  

//삽입
Nptr Insert(Nptr T, int key);
//전위순회
void PreOrder(Nptr T);
//중위순회 
void InOrder(Nptr T);
//후위순회
void PostOrder(Nptr T);
//삭제 
void Delete(Nptr& T, int key);