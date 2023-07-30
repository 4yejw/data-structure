#include "Singly_Linked_List.h"
//생성자
SLL::SLL() {
	Count = 0;
	Head = NULL;
}
//소멸자
SLL::~SLL() {
	while (!IsEmpty())
		Delete(1);
}
//마지막에 노드 추가
void SLL::Append(int Item) { 
	Nptr NewNode = new Node; //새로운 노드
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Head == NULL) //노드가 하나도 없을 때
		Head = NewNode;
	else {
		Nptr tmp = Head;
		while (tmp->Next != NULL) { //마지막 노드까지 이동하기
			tmp = tmp->Next;
		}
		tmp->Next = NewNode; //새로운 노드 이어 붙이기
	}
	Count++;
}
//지정한 위치에 노드 삽입
void SLL::Insert(int Position, int Item) { 
	Nptr NewNode = new Node; //새로운 노드
	NewNode->Data = Item;
	if (Position<1 || Position>Count + 1) //옳지않은 위치에 접근할 때
		cout << "Out of Range" << endl;
	else {
		if (Position == 1) {//첫번째 위치에 삽입할 때
			NewNode->Next = Head;
			Head = NewNode;
		}
		else { 
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//삽입할 위치 앞까지 이동
				tmp = tmp->Next;
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
		}
		Count++;
	}
}
//지정한 노드 삭제
void SLL::Delete(int Position) {
	if (IsEmpty()) 
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count ) //옳지않은 위치에 접근할 때
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		Nptr DeleteNode = Head;
		if (Position == 1) {//첫번째 노드를 삭제할 때
			Head = tmp->Next;
		}
		else {
			for (int i = 1; i < Position - 1; i++) 
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = DeleteNode->Next;
		}
		delete DeleteNode;
		Count--;
	}
}
//검색후 반환
int SLL::int_Retrieve(int Position) {
	if (IsEmpty()) {
		cout << "List is Empty" << endl;
		return 0;
	}
	else if (Position<1 || Position>Count) { //옳지않은 위치에 접근할 때
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
//검색 저장
void SLL::void_Retrieve(int Position, int* Itemptr) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count)  //옳지않은 위치에 접근할 때
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Position; i++)
			tmp = tmp->Next;
		*Itemptr = tmp->Data;
	}
}
//초기화
void SLL::Init() {
	Count = 0;
	Head = NULL;
}
//길이
int SLL::Length() {
	return Count;
}
//비어있는지 확인
bool SLL::IsEmpty() {
	return Count == 0;
}
//리스트 전체 출력
void SLL::Showlist() {
	cout << "[ ";
	Nptr tmp = Head;
	for (int i = 0; i < Count; i++) {
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << "]" << endl;
}
