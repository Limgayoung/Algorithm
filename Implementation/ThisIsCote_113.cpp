#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int i, j, k;
	int cnt = 0;

	scanf("%d", &N);

	for (i = 0; i <= N; i++) {
		for (j = 0; j < 60; j++) {
			for (k = 0; k < 60; k++) {
				if (i == 3)
					cnt++;
				else if (j / 10 == 3 || j % 10 == 3)
					cnt++;
				else if (k / 10 == 3 || k % 10 == 3)
					cnt++;
			}
		}
	}

	printf("%d", cnt);
}

/*
5 
*/
