#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int N, K;
	int i = 0;
	int x;
	
	scanf("%d %d", &N, &K);

	while (N > 1) {
		if (N % K == 0) {
			N /= K;
			i++;
		}
		else {
			x = N % K;
			N -= x;
			i += x;
		}
		//printf("N: %d\n", N);
		if (N == 0) i -= 1;
	}

	printf("%d", i);
	
	
}

/*
25 5
*/
