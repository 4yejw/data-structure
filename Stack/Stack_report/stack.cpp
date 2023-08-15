//stack.cpp
#include "stack.h" //스택 인터페이스 파일을 포함

 //생성자 함수
stackClass::stackClass() { //실행할 일이 없음
}

//소멸자 함수
stackClass::~stackClass() {
	while(!IsEmpty()) //stack이 빌때까지
		L.Delete(L.Length()); //마지막 값을 삭제
}

//char형의 Item값을 stack에 삽입
void stackClass::Push(char Item) {
	L.Insert(L.Length()+1, Item); //마지막 값으로 Item을 삽입
}

//Int형의 Item값을 stack에 삽입
void stackClass::Push(int Item) {
	L.Insert(L.Length()+1, Item); //마지막 값으로 Item을 삽입
}
//스택 탑의 데이터값을 삭제
void stackClass::Pop() {
	L.Delete(L.Length()); //마지막 값을 삭제
}

//스택 탑의 데이터 값을 리턴
char stackClass::GetTop() {
	char Item;
	L.Retrieve(L.Length(), Item); //마지막 값을 리턴
	return Item;
}
 
//스택이 비어있는지 확인
bool stackClass::IsEmpty() {
	return bool (L.IsEmpty());
}

//현재 스택의 data를 출력(char)
void stackClass::Showstack() {
	L.Showdata();
}

//현재 스택의 data를 출력(int)
void stackClass::Showintstack() {
	L.Showintdata();
}

int stackClass::Length() {
	return L.Length();
}

bool stackClass::IsFull() {
	return L.IsFull();
}