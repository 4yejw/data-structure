#include "Doubly_Linked_List.h"
//생성자
DLL::DLL() {
	Count = 0;
	Head = NULL;
}
//소멸자
DLL::~DLL() {
	while (!IsEmpty())
		Delete(1);
}
//마지막에 노드 추가
void DLL::Append(int Item) {
	Nptr NewNode = new Node; //새로운 노드
	NewNode->Data = Item;
	NewNode->Next = NULL;
	if (Head == NULL) { //노드가 하나도 없을 때
		Head = NewNode;
		NewNode->Prev = Head;
	}
	else {
		Nptr tmp = Head;
		while (tmp->Next != NULL) { //마지막 노드까지 이동하기
			tmp = tmp->Next;
		}
		tmp->Next = NewNode; //새로운 노드 이어 붙이기
		NewNode->Prev = tmp;
	}
	Count++;
}
//지정한 위치에 노드 삽입
void DLL::Insert(int Position, int Item) {
	Nptr NewNode = new Node; //새로운 노드
	NewNode->Data = Item;
	if (Position<1 || Position>Count+1) //옳지않은 위치에 접근할 때
		cout << "Out of Range" << endl;
	else {
		if (Position == 1) {//첫번째 위치에 삽입할 때
			NewNode->Next = Head;
			Head = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = Head;
		}
		else if (Position == Count + 1) {//마지막 위치에 삽입할 때
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//삽입할 위치 앞까지 이동
				tmp = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Prev = tmp;
			NewNode->Next = NULL;
		}
		else {
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)//삽입할 위치 앞까지 이동
				tmp = tmp->Next;
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = tmp;
		}
		Count++;
	}
}
//지정한 노드 삭제
void DLL::Delete(int Position) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count) //옳지않은 위치에 접근할 때
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		Nptr DeleteNode = Head;
		if (Position == 1) {//첫번째 노드를 삭제할 때
			Head = tmp->Next;
			tmp->Next->Prev = Head;
		}
		else if (Position == Count ) {//마지막 노드를 삭제할 때
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = NULL;
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
//검색후 반환
int DLL::int_Retrieve(int Position) {
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
void DLL::void_Retrieve(int Position, int* Itemptr) {
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
void DLL::Init() {
	Count = 0;
	Head = NULL;
}
//길이
int DLL::Length() {
	return Count;
}
//비어있는지 확인
bool DLL::IsEmpty() {
	return Count == 0;
}
//리스트 전체 출력
void DLL::Showlist() {
	cout << "[ ";
	Nptr tmp = Head;
	for (int i = 0; i < Count; i++) {
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << "]" << endl;
}