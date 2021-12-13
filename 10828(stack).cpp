#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>


typedef struct Node {
	Node *next; //다음 노드 주소 저장할 포인터
	int data;
} node;

typedef struct Stack {
	node* top;
	int count=0;
}stack;

void push(int x, stack* s);
int pop(stack* s);
int empty(stack s);
int top(stack s);
void initStack(stack* s);

int main() {

	stack s;
	int N, i,x;
	char ins[6];

	scanf("%d", &N);

	initStack(&s);

	for (i = 0; i < N; i++) {
		scanf("%s", ins);
		getchar();

		if (strcmp(ins, "push") == 0) {
			scanf("%d", &x);
			push(x, &s);
		}
		else if (strcmp(ins, "pop") == 0) {
			printf("%d\n",pop(&s));
		}
		else if (strcmp(ins, "size") == 0) {
			printf("%d\n", s.count);
		}
		else if (strcmp(ins, "empty") == 0) {
			printf("%d\n", empty(s));
		}
		else if (strcmp(ins, "top") == 0) {
			printf("%d\n", top(s));
		}
	}

	return 0;
}

void push(int x, stack* s) {
	node* n;

	n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = s->top;
	s->top = n;
	s->count++;
}

int pop(stack* s) {
	if (s->top == NULL) {
		return -1;
	}
	else {
		node* n;
		int num;
		n = s->top;

		s->top = s->top->next;
		num = n->data;
		n = NULL;
		s->count--;
		return num;
	}
}

int empty(stack s) {
	if (s.top == NULL) {
		return 1;
	}
	else return 0;
}

int top(stack s) {
	if (s.top == NULL) {
		return -1;
	}
	else {
		return s.top->data;
	}
}

void initStack(stack* s) {
	s->top = NULL;
}