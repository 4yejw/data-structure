//BraceMatch.cpp
#pragma once //중복 호출 방지
#include "stack.h" //stack 인터페이스 파일을 포함
#include <fstream> //파일 입출력할때 필요
#include <string> //문자열 사용할때 필요

int main() {
	string text; 

	ifstream file; //파일 입력 객체 생성
	file.open("text.txt"); //"text.txt" 파일 열기
	
	stackClass S; //stackClass 객체 S생성 (char data stack)
	stackClass Int; //stackClass 객체 Int생성 (int data stack)

	if (file.is_open()) { //파일을 열 수 있으면 true를 반환
	
		int count = 1; //라인번호는 1부터 시작
		while (!file.eof()) { //파일의 끝 까지
			getline(file, text); //열었던 file을 한줄씩 string text에 저장
			cout << text << endl;

			int index = 0; //배열 인덱스를 저장할 변수
			while (index < text.length()) { //text 전체 길이동안
				if (text[index] == '{') { //text의 어떤 문자가 '{'이면
					S.Push('{'); //char data stack에 '{'를 Push
					Int.Push(count); //int data stack에 라인번호를 Push
				}
				else if (text[index] == '}') { //text의 어떤 문자가 '}'이고
					if (!S.IsEmpty()) { //stack이 비어있지 않으면
						S.Pop(); //char data stack을 Pop
						Int.Pop(); //int data stack을 Pop
					}
				}
				index++; //인덱스 증가
			}
			count++; //라인번호 증가
		}
		file.close();
	}
	else { //파일을 열 수 없을 때
		cout << "파일을 열 수 없습니다\n"; //에러메세지를 출력한다
		return 1;
	}
	cout << endl;
	S.Showstack(); //char data stack 출력 (짝이없는 중괄호)
	Int.Showintstack(); //int data stack 출력 (짝이없는 중괄호의 라인번호)
}

