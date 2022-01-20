#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int N,M,i,x,j;
	deque<int> q;
	queue<int> num;
	int count = 0;
	int index=0;

	int left, right;

	scanf("%d %d", &N, &M);
	
	for (i = 1; i <= N; i++) {
		q.push_back(i);
	}

	for (i = 0; i < M; i++) {
		scanf("%d", &x);
		num.push(x);
	}

	for (i = 0; i < M; i++) {
		
		for (j = 0; j < q.size(); j++) {
			if (q[j] == num.front()) {
				index = j;
				break;
			}
		}
		right = index;
		left = q.size() - index+1;

		if (left <= right) {
			while (q.front() != num.front()) {
				q.push_front(q.back());
				q.pop_back();
				count++;
			}
			num.pop();
			q.pop_front();
		}
		else {
			while (q.front() != num.front()) {
				q.push_back(q.front());
				q.pop_front();
				count++;
			}
			num.pop();
			q.pop_front();
		}
	}

	printf("%d", count);

	return 0;
}
