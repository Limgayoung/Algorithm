#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

typedef struct Node {
	struct Node* next;
	struct Node *prev;
	char data;
}Node;

typedef struct List {
	struct Node* header;
	struct Node* trailer;
}List;

void getNode(Node** node, char data) { //노드 초기화
	Node* n;

	n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	n->prev = NULL;
	n->data = data;

	*node = n;
}

Node* findRank(Node* head, int rank) { //순위 찾기
	while (rank--) {
		if (head == NULL) {
			return NULL;
		}
		head = head->next;
	}
	return head;
}

void printList(List list) { //리스트 출력
	Node* point = list.header->next;

	while (point->next != NULL) {
		printf("%c", point->data);
		point = point->next;

	}
	printf("\n");
}

void add(List* list, int r, char e) { //순위 r에 원소 e 추가
	Node* front, * back;
	Node* newNode;
	front = findRank(list->header, r-1);

	getNode(&newNode, e);

	if (list->header->next == list->trailer->prev && r == 1 ) { //빈 리스트
		newNode->prev = list->header;
		newNode->next = list->trailer;
		list->header->next = newNode;		
		list->trailer->prev = newNode;		
	}

	else if (front == NULL) { //없는 순위를 줌
		printf("invalid position\n");
		return;
	}

	else { //빈 리스트도 아니고 순위도 제대로 줌
		back = front->next;
		newNode->prev = front;		
		newNode->next = back;
		back->prev = newNode;
		front->next = newNode;				
	}
}

void getElement(List list, int r) {
	Node* node;

	node = findRank(list.header, r);

	if (node->next == NULL) {
		printf("invalid position\n");
		return;
	}
	else {
		printf("%c\n", node->data);
	}
}

void deleteElement(List* list, int rank) {
	Node* node;
	Node* front, * back;
	node = findRank(list->header, rank);

	if (node == NULL) {
		printf("invalid position\n");
		return;
	}
	else {
		front = node->prev;
		back = node->next;
		front->next = back;
		back->prev = front;

		free(node);
	}
}

void freeNode(Node* node) {
	if (node != NULL) {
		freeNode(node->next);
		free(node);
	}
	
}


int main() {
	int N;
	List list;

	char oper, data;
	int rank;

	list.header = (Node*)malloc(sizeof(Node));
	list.trailer = (Node*)malloc(sizeof(Node));
		
	list.header->next = list.trailer;
	list.header->prev = NULL;
	list.trailer->next = NULL;
	list.trailer->prev = list.trailer;	

	scanf("%d", &N);

	while (N--) {
		getchar();

		scanf("%c", &oper);		

		if (oper == 'A') { //add
			scanf("%d", &rank);
			getchar();
			scanf("%c", &data);
			add(&list, rank, data);
		}
		else if (oper == 'D') { //delete
			scanf("%d", &rank);
			deleteElement(&list, rank);
		}
		else if (oper == 'G') { //get
			scanf("%d", &rank);
			getElement(list, rank);
		}
		else if (oper == 'P') { //print
			printList(list);
		}	
	}
	freeNode(list.header);
	return 0;
}