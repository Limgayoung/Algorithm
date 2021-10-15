#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>

typedef struct Node {
	int data;
	Node* next, *prev;
}node;

struct Deque {
	Node* front;
	Node* back;
	int count;
};

void push_front(Deque* q, int x);
void push_back(Deque* q, int x);
void pop_front(Deque* q);
void pop_back(Deque* q);

void init(Deque* q) {
	q->front = NULL;
	q->back = NULL;
	q->count = 0;
}

int main() {
	int N,i,x;
	Deque q;
	char ins[11];

	scanf("%d", &N);

	init(&q);

	for (i = 0; i < N; i++) {
		scanf("%s", ins);

		if (strcmp(ins, "push_front") == 0) {
			scanf("%d", &x);
			push_front(&q, x);
			q.count++;
		}
		else if (strcmp(ins, "push_back") == 0) {
			scanf("%d", &x);
			push_back(&q, x);
			q.count++;
		}

		else if (strcmp(ins, "pop_front") == 0){
			if (q.count == 0) {
				printf("-1\n");
			}
			else {
				pop_front(&q);
				q.count--;
			}
		}

		else if (strcmp(ins, "pop_back") == 0) {
			if (q.count == 0) {
				printf("-1\n");
			}
			else {
				pop_back(&q);
				q.count--;
			}
		}

		else if (strcmp(ins, "size") == 0) {
			printf("%d\n", q.count);
		}

		else if (strcmp(ins, "empty") == 0) {
			if (q.count == 0) {
				printf("1\n");
			}
			else printf("0\n");
		}
		else if (strcmp(ins, "front") == 0) {
			if (q.count == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.front->data);
			}
		}
		else if (strcmp(ins, "back") == 0) {
			if (q.count == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q.back->data);
			}
		}
	}

	return 0;
}

void push_front(Deque* q, int x) {
	node* n;
	n = (node*)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;
	n->prev = NULL;

	if (q->count == 0) { //처음
		q->front = n;
		q->back = n;		
	}
	else {
		n->next = q->front;
		q->front->prev = n;
		q->front = n; 
	}
}

void push_back(Deque* q, int x) {
	node* n;
	n = (node*)malloc(sizeof(node));

	n->data = x;
	n->next = NULL;
	n->prev = NULL;

	if (q->count == 0) { //처음
		q->front = n;
		q->back = n;
	}
	else {
		n->prev = q->back;
		q->back->next = n;
		q->back = n;
	}
}

void pop_front(Deque* q) {
	node *n;
	printf("%d\n", q->front->data);
		n = q->front->next;
		q->front = NULL;
		q->front = n;
	
}

void pop_back(Deque* q) {
	node* n;
	printf("%d\n", q->back->data);
		n = q->back->prev;
		q->back = NULL;
		q->back = n;
	
}