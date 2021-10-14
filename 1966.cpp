#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Custom {
	int weight;
	int order;
};

struct cmp {
	bool operator()(Custom a, Custom b) {
		return a.weight > b.weight;
	}
};

int printer() {
	int N, M;
	int i, x;
	int Mnum, count=1;
	Custom inputQ;

	queue<Custom> q;
	
	priority_queue<int> max;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) { //queue에 입력
		scanf("%d", &x);
		inputQ.weight = x;
		inputQ.order = i;
		q.push(inputQ);
		max.push(x);
	}

	while (!max.empty()) {
		if (max.top() <= q.front().weight) {
			if (q.front().order == M) {
				break;
			}
			q.pop();
			max.pop();
			count++;
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}

	return count;
}

int main() {
	int test;
	int i;

	scanf("%d", &test);

	for (i = 0; i < test; i++) {
		printf("%d\n", printer());
	}


	return 0;
}

