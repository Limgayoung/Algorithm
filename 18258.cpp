#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
}node;

typedef struct Queue {
	int count;
	node* front;
	node* back;
}queue;

void push(Queue* q, int x);
int pop(Queue* q);
int isEmpty(Queue* q);
int front(Queue* q);
int back(Queue* q);

void initQueue(Queue* q) {
	q->front = NULL;
	q->back = NULL;
	q->count = 0;
}

int main() {
	int N;
	int i,x;
	Queue q;
	char ins[6];

	initQueue(&q);

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", ins);

		if (strcmp(ins, "push") == 0) {
			scanf("%d", &x);
			push(&q, x);
		}
		else if (strcmp(ins, "pop") == 0) {
			printf("%d\n",pop(&q));
		}
		else if (strcmp(ins, "size") == 0) {
			printf("%d\n", q.count);
		}
		else if (strcmp(ins, "empty") == 0) {
			if (q.count == 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(ins, "front") == 0) {
			if (q.count == 0) printf("-1\n");
			else printf("%d\n",q.front->data);
		}
		else if (strcmp(ins, "back") == 0) {
			if (q.count == 0) printf("-1\n");
			else printf("%d\n", q.back->data);
		}
	}


	return 0;
}

void push(Queue* q, int x) {
	node* n;
	n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;

	if (q->count == 0) { //비어있을 때
		q->front = n;
		q->back = n;
		q->count++;
	}
	else {	//연결
		q->back->next = n;
		q->back = n;
		q->count++;

	}

}

int pop(Queue* q) {
	node* n;
	int num;
	
	if (q->count == 0) {
		return -1;
	}
	else {
		n = q->front->next;
		num = q->front->data;
		q->front = NULL;
		q->front = n;
		q->count--;
		return num;
	}
}



int front(Queue* q) {
	return 0;

}

int back(Queue* q) {
	return 0;

}
