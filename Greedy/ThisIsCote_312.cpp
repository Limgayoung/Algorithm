#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>


using namespace std;



int main() {
	char S[21];
	int i;
	int sum = 0;
	int num;

	scanf("%s", S);

	sum = S[0]-'0';

	for (i = 0; i < strlen(S)-1;  i++) {
		num = S[i+1] - '0';
		//printf("sum: %d  num: %d\n", sum, num);
		if (sum == 0 || sum == 1) { //초기에 sum이 0,1이면 +
			sum += num;
		}

		else if (num == 0 || num == 1) { //num이 0,1 이면 +
			sum += num;
		}
		else {
			sum *= num;
		}
	}

	printf("%d", sum);

}



/*
02984

567
*/
