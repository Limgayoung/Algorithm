#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	//int n[500000], m[500000][2];
	int i, j;
	int left, right; //상한, 하한

	scanf("%d", &N);
	vector<int> n(N);
	for (i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}

	//n 정렬
	sort(n.begin(), n.end());
	 
	scanf("%d", &M);
	vector<int> m(M);
	for (i = 0; i < M; i++) {
		scanf("%d", &m[i]);
	}

	for (i = 0; i < M; i++) {
		left = lower_bound(n.begin(), n.end(), m[i])-n.begin();
		right = upper_bound(n.begin(), n.end(), m[i])-n.begin();
		printf("%d ", right - left);
	}


	return 0;
}

