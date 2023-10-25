#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include<stdio.h>

using namespace std;
int A[1000001];

int calSupervisionNum(int A, int B, int C) {

	if ((A - B) <= 0) return 1;
	else {
		if ((A - B) % C == 0) {
			return 1 + (A - B) / C;
		}
		else {
			return 2 + (A - B) / C;
		}
		
	}
}

int main() {
	int N;
	int B, C;
	long long cnt = 0;
	
	scanf("%d" , &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		cnt += calSupervisionNum(A[i], B, C);
	}
	printf("%lld", cnt);
	return 0;
}

/*
3
3 4 5
9 9

*/
