#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int N;
	int i, lastNum=0, num;
	queue<int> q;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) { //q에 카드 넣기
		q.push(i);
	}

	while (q.size()>1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	printf("%d", q.front());

	return 0;
}

