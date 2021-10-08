#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> a;
	stack<int> s;
	
	int i,num;

	scanf("%d", &N);

	vector<int> answer(N,-1); //vector를 -1로 초기화

	for (i = 0; i < N; i ++ ) {
		scanf("%d", &num);
		a.push_back(num);
		while (!s.empty() && a[s.top()] < a[i]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i); //s에 a 위치 저장
	}

	for (i = 0; i < N; i++) {
		printf("%d ",answer[i]);
	}

	return 0;
}
