#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int canCutting(long long length, long long N, long long M, vector<long long> n) {
	int i;
	long long count = 0;

	for (i = 0; i < N; i++) {
		if (n[i] > length) {
			count += (n[i] - length);
		}
	}

	if (count >= M) return 1;
	else return 0;
}

int main() {

	long long N, M;
	int i;
	long long left=1, right=0, mid;
	long long answer=0;

	scanf("%lld %lld", &N, &M);
	vector<long long> n(N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &n[i]);
		if (right <= n[i]) right = n[i];
	}

	
	while (left <= right) {
		mid = (left + right) / 2;

		if (canCutting(mid, N, M, n)) {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%lld", answer);


	return 0;
}

