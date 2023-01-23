#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int N, M, K;
	int num[1000];
	int i,j;
	int big, big2, sum;
	int count;

	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num+N, greater<int>());



	big = num[0];
	big2 = num[1];
	
	count = (M / (K + 1)) * K + M % (K + 1);
	sum = count * big + (M - count) * big2;

	/*
	sum = 0;
	j = 0;

	for (i = 0; i < M; i++) {
		if (j / K == 0) {
			sum += big;
			j++;

		}
		else {
			sum += big2;
			j = 0;
		}
	}
	*/

	printf("%d", sum);	
}

/*
5 8 3 
2 4 5 4 6
*/