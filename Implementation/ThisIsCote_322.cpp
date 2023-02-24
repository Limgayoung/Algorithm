#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>


using namespace std;



int main() {
	char S[10001];
	int arr[10001];
	int sum = 0;
	int i, j=0;

	scanf("%s", S);

	for (i = 0; i < strlen(S); i++) {
		if (S[i] >= '0' && S[i] <= '9') { //숫자
			sum += (S[i] - '0');
		}
		else { //알파벳
			arr[j] = S[i] - 'A';
			j++;
		}
	}

	sort(arr, arr + j);

	for (i = 0; i < j; i++) {
		printf("%c", arr[i] + 'A');
	}
	printf("%d", sum);
}



/*
K1KA5CB7
AJKDLSI412K4JSJ9D
*/
