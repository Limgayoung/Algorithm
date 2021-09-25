#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int N;
	int i, num=0, sum=0;
	stack<int> s;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	while (!s.empty()) {
		sum += s.top();

		s.pop();
	}

	printf("%d", sum);

	return 0;
}
