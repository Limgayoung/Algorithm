#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int compair(int a, int b) {
	return a > b;
}

int main() {
	int N;
	int i;
	int num[501];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N, compair);

	for (i = 0; i < N; i++) {
		printf("%d ", num[i]);
	}

}

/*
3 
15 
27 
12
*/
