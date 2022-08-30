#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

void get_Node(Node** returnNode, int d) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;

	*returnNode = node;
}

void printList(Node* head) {
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void freeList(Node* node) {
	if (node) {
		freeList(node->next);
		free(node);
	}
}

int main() {
	Node* head=NULL, * node;
	int n, d;

	scanf("%d", &n);

	scanf("%d", &d);

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->data = d;

	n--;

	while (n--) {
		scanf("%d", &d);	

		get_Node(&node, d);
		node->next = head;
		head = node;

	}

	printList(head);
	
	freeList(head);
	return 0;
}