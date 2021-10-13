#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int N,K;
	queue<int> q;
	queue<int> ans;
	int i=1;
	

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++) {
		q.push(i);
	}

	i = 1;

	while (ans.size()<N) {
		if (i % K == 0) {
			ans.push(q.front());
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		i++;
	}

	printf("<");
	for (i = 0; i < N; i++) {
		if (i == N - 1) {
			printf("%d>", ans.front());
		}
		else {
			printf("%d, ", ans.front());
			ans.pop();
		}
	}

	return 0;
}

