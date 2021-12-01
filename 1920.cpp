#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void binary(long long value, long long* n, int N) {

	int left = 0, right = N - 1;
	int m;
	int f = 0;

	while (left <= right) {
		m = (left + right) / 2;
		if (value < n[m]) {
			right = m - 1;
		}
		else if (value > n[m]) {
			left = m + 1;
		}
		else {
			printf("1\n");
			return;
		}
	}

	if (f == 0) printf("0\n");
}

int main() {
	long long N,M;
	long long n[100000], m;
	int i, j, t;
	long long left, right, mid, value;
	int f;

	scanf("%lld", &N);
	//n = (long long*)malloc(sizeof(long long) * N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &n[i]);
	}	

	//배열 n 정렬
	sort(n, n + N);

	scanf("%lld", &M);

	//이분탐색으로 찾기
	for (i = 0; i < M; i++) {
		scanf("%lld", &m);
		binary(m, n, N);
	}

	return 0;
}

