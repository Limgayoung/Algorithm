#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int narr[1000001];
int marr[100001];

int main() {
	
	int N, M;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &narr[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &marr[i]);
	}

	sort(narr, narr + N);

	int findNum, left, right, mid;

	for (int i = 0; i < M; i++) {
		findNum = marr[i];

		left = 0;
		right = N - 1;
		while (left<=right) {
			mid = (left + right) / 2;
			if (narr[mid] > findNum) {				
				right = mid-1;
			}
			else if (narr[mid] < findNum) {				
				left = mid + 1;				

			}
			else {
				printf("yes ");
				break;
			}						
		}
		if (left > right) printf("no ");
	}
}

/*
5 
8 3 7 9 2 
3 
5 7 9
*/
