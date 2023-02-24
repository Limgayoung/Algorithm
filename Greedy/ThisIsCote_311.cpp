#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>


using namespace std;

int arr[100001];

int main() {
	int N;
	int i;
	int max = 0, count = 0, result = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++) {
		if (max < arr[i]) { //공포도 조정
			max = arr[i];
		}
		count++;

		if (max == count) { //만족함 -> 초기화
			result++;
			max = 0;
			count = 0;
		}
	}

	printf("%d", result);

}



/*
5 
2 3 1 2 2
*/
