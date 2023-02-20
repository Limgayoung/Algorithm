#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int a[100001], b[100001];

int compair(int a, int b) {
	return a > b;
}


int main() {
	int N, K; 
	int t;
	long long sum=0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, a + N);
	sort(b, b + N, compair);

	for (int i = 0; i < K; i++) { //K 번의 바꿔치기
		if (a[i] < b[i]) {
			t = a[i];
			a[i] = b[i];
			b[i] = t;
		}
		else break;
	}

	for (int i = 0; i < N; i++) {		
		//printf("%d ", a[i]);
		sum +=a[i];		
	}

	printf("%.0lld", sum);
}

/*
5 3 
1 2 5 4 3 
5 5 6 6 5
*/
