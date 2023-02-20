#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N;
int M;

int length[1000001];

int main() {
	scanf("%d %dd", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
	}

	sort(length, length + N);

	int left, right, mid;
	int maxLength = 0, sum = 0, diff;	
	left = 0;
	right = length[N - 1];

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			diff = length[i] - mid;
			if (diff > 0) sum += diff;
		}

		if (M < sum) { //더 큰 값으로 잘라줘야 함
			if (maxLength < mid) {
				maxLength = mid;
			}
			left = mid + 1;
		}
		else if (M > sum) {
			right = mid - 1;
		}
		else {
			maxLength = mid;
			break;
		}		
	}
	printf("%d", maxLength);
	
}

/*
4 6 
19 15 10 17
*/
