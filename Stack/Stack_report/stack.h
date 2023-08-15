//stack.h
#pragma once //중복 호출 방지
#include "list.h" //리스트 인터페이스파일을 포함

class stackClass {
public:
	stackClass(); //생성자 함수
	~stackClass(); //소멸자 함수
	void Push(char Item); //char 형의 Item값을 stack에 삽입
	void Push(int Item); //Int형의 Item값을 stack에 삽입
	void Pop(); //스택 탑의 데이터값을 삭제
	char GetTop(); //스택 탑의 데이터 값을 리턴
	bool IsEmpty(); //스택이 비어있는지 확인
	void Showstack(); //현재 스택의 data를 출력(char)
	void Showintstack(); //현재 스택의 data를 출력(int)
	int Length();
	bool IsFull(); //스택이 꽉 차있는지 확인
private:
	listClass L; //리스트 객체 L
};