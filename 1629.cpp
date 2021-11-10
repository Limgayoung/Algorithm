#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

long long repeat(int A, int B, int C) {
	if (B == 0) return 1;
	else {
		if (B % 2 == 1) {
			return (repeat(A, B / 2, C) * repeat(A, B / 2, C) % C) * A % C;

		}
		else {
			return repeat(A, B / 2, C) * repeat(A, B / 2, C) % C;
		}
	}
}

int main() {
	int A, B, C;
	int i, j;

	scanf("%d %d %d", &A, &B, &C);

	printf("%lld", repeat(A, B, C) % C);

	return 0;
}
