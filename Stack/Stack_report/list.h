//list.h
#pragma once //중복 호출 방지
#include <iostream> //c++표준 입출력 헤더파일 
using namespace std; //std이름 공간에 선언된 모든 이름에 std::생략

const int MAX = 100; //배열의 크기를 MAX로 지정함

class listClass { //class선언
public:
	listClass(); //생성자(초기화Init의 역할)
	~listClass(); //소멸자
	void Insert(int Position, char Item); //char삽입
	void Insert(int Position, int Item); //int 삽입
	void Delete(int Position); //삭제
	int Length(); //리스트 길이 반환
	void Retrieve(int Position, char& Item); //검색 후 char data 저장
	void Retrieve(int Position, int& Item); //검색 후 int data 저장
	bool IsEmpty(); //비어있는지 확인
	bool IsFull(); //꽉 차있는지 확인
	void Showdata(); //Data 출력 (char data)
	void Showintdata(); //IntData 출력 (int data)
	
private:
	int Count = 0; //배열에서 유효한 값의 개수
	char Data[MAX]; //char data를 저장할 배열
	int IntData[MAX]; //int data를 저장할 배열
};