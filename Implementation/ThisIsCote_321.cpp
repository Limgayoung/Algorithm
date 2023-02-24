#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>


using namespace std;



int main() {
	char N[9];
	int half;
	int left = 0, right = 0;

	scanf("%s", N);
	half = strlen(N) / 2;

	for (int i = 0; i < strlen(N)/2; i++) {
		left +=( N[i] - '0');
	}

	for (int i = half; i < strlen(N); i++) {
		right += (N[i] - '0');
	}

	if (left == right) {
		printf("LUCKY");
	}
	else printf("READY");


}



/*
123402
7755
*/
