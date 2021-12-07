#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int cutting(int length, int K, int N, vector<long long> k) {
	int i;
	int count=0;

	for (i = 0; i < K; i++) {
		count += (k[i] / length);
	}
	if (count >= N) return 1;
	else return 0;

}

int main() {
	int K, N;
	int i, j;
	long long left=1, right=0, mid;
	long long answer=0;

	scanf("%d %d", &K, &N);
	vector<long long> k(K);
	for (i = 0; i < K; i++) {
		scanf("%lld", &k[i]);
		if (right < k[i]) right = k[i];
	}

	while (left <= right) {
		mid = (left + right) / 2; 
		if (cutting(mid, K, N, k)) { //되면 mid 값을 늘려서 해봐야 함
			if (answer < mid) { //결과가 중간값보다 작을 때
				answer = mid;
			}
			left = mid + 1;
		}
		else { //안되면 mid 값을 줄여서 해봐야 함
			right = mid - 1;
		}
	}

	printf("%lld", answer);

	return 0;
}

