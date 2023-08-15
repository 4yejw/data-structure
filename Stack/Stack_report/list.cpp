//list.cpp
#include "list.h" //리스트 인터페이스 파일을 포함

//생성자
listClass::listClass() :Count(0) {} //Count 를 0으로 초기화

//소멸자
listClass::~listClass() {} //소멸자는 할 일이 없음

//char Item 삽입
void listClass::Insert(int Position, char Item) {
	if (Count == MAX)//배열이 꽉 찼을 때 
		cout << "삽입할 수 있는 공간이 없습니다" << endl;
	else if (Position<1 || Position>(Count + 1)) //잘못된 위치에 접근하려고 할때
		cout << "해당 위치에 접근할 수 없습니다" << endl;
	else {
		for (int i = Count; i > Position - 1; i--) //뒤에서부터 삽입할 위치전까지 하나씩 오른쪽으로 이동
			Data[i] = Data[i - 1];
		Data[Position - 1] = Item; //삽입할 위치에 데이터 저장
		Count++; //개수 +1
	}
}

//int Item 삽입
void listClass::Insert(int Position, int Item) {
	if (Count == MAX) //배열이 꽉 찼을 때 
		cout << "삽입할 수 있는 공간이 없습니다" << endl;
	else if (Position<1 || Position>(Count + 1)) //잘못된 위치에 접근하려고 할때
		cout << "해당 위치에 접근할 수 없습니다" << endl;
	else {
		for (int i = Count; i > Position - 1; i--) //뒤에서부터 삽입할 위치전까지 하나씩 오른쪽으로 이동
			IntData[i] = IntData[i - 1];
		IntData[Position - 1] = Item; //삽입할 위치에 데이터 저장
		Count++; //개수 +1
	}
}

//삭제 
void listClass::Delete(int Position) {
	if (Position < 1 || Position >= (Count + 1)) //잘못된 위치에 접근하려고 할때 
		cout << "해당 위치에 접근할 수 없습니다" << endl;
	else {
		for (int i = Position - 1; i < Count - 1; i++) { //삭제하려는 값 뒤부터 하나씩 왼쪽으로 이동
			Data[i] = Data[i + 1];
			IntData[i] = IntData[i + 1];
		}
		Count--; //개수 -1
	}
}

//리스트 길이 출력
int listClass::Length() {
	return Count;
}

//검색 후 데이터 저장 (char data)
void listClass::Retrieve(int Position, char& Item) {
	if (Position < 1 || Position >= (Count + 1)) //잘못된 위치에 접근하려고 할때
		cout << "해당 위치에 접근할 수 없습니다" << endl;
	else {
		Item = Data[Position - 1]; //검색한 데이터를 저장
	}
}

//검색 후 데이터 저장 (int data)
void listClass::Retrieve(int Position, int& Item) {
	if (Position < 1 || Position >= (Count + 1)) //잘못된 위치에 접근하려고 할때
		cout << "해당 위치에 접근할 수 없습니다" << endl;
	else {
		Item = IntData[Position - 1]; //검색한 데이터를 저장
	}
}

//비어있는지 확인
bool listClass::IsEmpty() {
	return (Count == 0); //Count가 0이면 true반환
}

//꽉 차있는지 확인
bool listClass::IsFull() {
	return (Count == MAX); //Count 가 MAX이면 true반환
}

//현재 리스트 데이터 출력 (char data)
void listClass::Showdata() {
	cout << "stack = [ ";
	for (int i = 0; i < Count; i++) {
		cout << Data[i] << ' ';
	}
	cout << "]" << endl;
}

//현재 리스트 데이터 출력 (int data)
void listClass::Showintdata() {
	cout << "짝이 없는 중괄호가 위치한 라인번호 :";
	for (int i = 0; i < Count; i++) {
		cout << IntData[i] << "번 ";
	}
	cout << endl;
}
