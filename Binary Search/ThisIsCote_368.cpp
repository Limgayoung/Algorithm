#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[1000001];

int main() {

	int N;
	int i;
	int left, right, mid;
	int result = -1;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	left = 0;
	right = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] < mid) { //값 < 인덱스 -> 오른쪽
			left = mid + 1;
		}
		else if (arr[mid] > mid) { //값 > 인덱스 -> 왼쪽
			right = mid - 1;
		}
		else {
			result = mid;
			break;
		}
	}
	printf("%d", result);
}


/*
5 
-15 -6 1 3 7

7 
-15 -4 2 8 9 13 15

7 
-15 -4 3 8 9 13 15
*/
