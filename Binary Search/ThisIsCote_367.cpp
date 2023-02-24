#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[1000001];
int N, x;


int search_start() { //시작점 찾기
	int left, right, mid;

	left = 0;
	right = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] < x) {
			left = mid + 1;
		}
		else if (arr[mid] > x) {
			right = mid - 1;
		}
		else {
			if (mid == 0 || arr[mid - 1] < x) { //가장 왼쪽인 경우
				return mid;
			}
			else {
				right = mid - 1;
			}
		}
	}

	return -1;
}

int search_end() { //끝점 찾기
	int left, right, mid;

	left = 0;
	right = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] < x) {
			left = mid + 1;
		}
		else if (arr[mid] > x) {
			right = mid - 1;
		}
		else { 
			if (mid == N - 1 || arr[mid + 1] > x) { //가장 오른쪽인 경우
				return mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return -1;
}

int main() {
	int i;
	int left, right;

	scanf("%d %d", &N, &x);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	left = search_start();
	right = search_end();

	if (left != -1 && right != -1) {
		printf("%d", right - left+1);
	}
	else printf("-1");

}


/*
7 2 
1 1 2 2 2 2 3

7 4 
1 1 2 2 2 2 3
*/
