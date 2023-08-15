#include "BinarySearchTree.h"

//삽입
Nptr Insert(Nptr T, int key) {
	if (T == NULL) {  //더 이상 따라갈 노드가 없는 경우 (리프노드)
		T = new node;  //삽입할 새 노드를 만든다 
		T->Key = key;  //새 노드의 Key공간에 삽입하려는 값을 넣는다
		T->LChild = NULL;  //리프노드 이므로 NULL을 넣는다
		T->RChild = NULL;  //리프노드 이므로 NULL을 넣는다
	}
	else if (T->Key > key)  //삽입하려는 값이 현재 노드 값보다 작으면
		T->LChild = Insert(T->LChild, key);  //왼쪽으로 이동
	else   //삽입하려는 값이 현재 노드 값보다 크거나 같으면
		T->RChild = Insert(T->RChild, key);  //오른쪽으로 이동
	return T;
}

//전위순회 PreOrder
void PreOrder(Nptr T) {
	if (T != NULL) {
		cout << T->Key << ' ';  //key값 출력
		PreOrder(T->LChild);  //왼쪽 재귀호출
		PreOrder(T->RChild);  //오른쪽 재귀호출
	}
}

//중위순회 InOrder
void InOrder(Nptr T) {
	if (T != NULL) {
		InOrder(T->LChild);  //왼쪽 재귀호출
		cout << T->Key << ' ';  //key값 출력
		InOrder(T->RChild);  //오른쪽 재귀호출
	}
}

//후위순회 PostOrder
void PostOrder(Nptr T) {
	if (T != NULL) {
		PostOrder(T->LChild);  //왼쪽 재귀호출
		PostOrder(T->RChild);  //오른쪽 재귀호출
		cout << T->Key << ' ';  //key값 출력
	}
}

//삭제 
void Delete(Nptr& T, int key) {
	if (T == NULL)  //삭제하려는 값을 못찾았을때 
		cout << "삭제하려는 값 " << key << "가 없습니다" << endl;
	else if (T->Key > key)  //삭제하려는 값이 현재 노드의 key값보다 작을 때 
		Delete(T->LChild, key);
	else if (T->Key < key)  //삭제하려는 값이 현재 노드의 key값보다 클 때
		Delete(T->RChild, key);
	else if (T->Key == key) {  //삭제하려는 값이 현재 노드의 key값과 일치할 때
		if ((T->LChild == NULL) && (T->RChild == NULL)) {//삭제하려는 노드에 자식이 하나도없는 경우
			Nptr tmp = T;  //node 포인터 tmp로 삭제하려는 노드를 가리킴
			T = NULL;  //T가 그만 가리키게 함
			delete tmp;  //노드를 삭제
		}
		else if (T->LChild == NULL) {//삭제하려는 노드에 오른쪽 자식만 있는 경우
			Nptr tmp = T;  //node 포인터 tmp로 삭제하려는 노드를 가리킴
			T = T->RChild;  //부모(T)가 자식을 가리킴
			delete tmp;  //노드를 삭제
		}
		else if (T->RChild == NULL) {//삭제하려는 노드에 왼쪽 자식만 있는 경우
			Nptr tmp = T;  //node 포인터 tmp로 삭제하려는 노드를 가리킴
			T = T->LChild;  //부모(T)가 자식을 가리키게 함
			delete tmp;  //노드를 삭제
		}
		else { //삭제하려는 노드에 자식이 둘인 경우
			Nptr tmp = T;  //node 포인터 tmp로 삭제하려는 노드를 가리킴
			tmp = tmp->RChild;  //중위후속자를 찾기위해 오른쪽으로 한번 이동
			while (tmp->LChild != NULL) //LChild가 NULL일때까지 왼쪽으로 이동
				tmp = tmp->LChild;
			int tmp_Key = 0; //중위후속자 노드가 가리키는 key값을 저장할 변수
			tmp_Key = tmp->Key;  //key값을 따로 저장
			Delete(T, tmp->Key);  //중위후속자 노드를 삭제
			T->Key = tmp_Key;  //삭제하려는 노드의 Key값을 중위후속자 노드의 key값으로 복사
		}
	}
}
