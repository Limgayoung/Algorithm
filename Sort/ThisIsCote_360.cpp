#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int house[200001];

int N;

int main() {
	int i;
	int loc;
	int sum = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &house[i]);
	}

	sort(house, house + N);

	printf("%d", house[(N-1)/2]);
}


/*
4 4 2 1 
1 2 
1 3 
2 3 
2 4
*/
