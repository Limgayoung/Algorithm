#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

/*
1. 피자 조각 크기 구하기 (K 이하인 것만 구하면 됨) 최대 1000000 * 2
	이때 크기는 ++해주기 -> 개수 구할 수 있음
2. 0~K 까지 [왼쪽 피자 0, 오른쪽 피자 K] ... [왼쪽 k, 오른쪽 0] 개수 곱
3. 2번의 총합이 정답
*/

using namespace std;
vector<int> sumA, sumB;
int K, n, m;
int answer = 0;


int main() {

	vector<int> A, B;

	scanf("%d", &K);
	scanf("%d %d", &m, &n);

	A = vector<int>(m);
	B = vector<int>(n);
	sumA = vector<int>(2000001, 0);
	sumB = vector<int>(2000001, 0);
	//initMap();

	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
		//mapA[A[i]]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		//mapB[B[i]]++;
	}

	//1. 피자 조각 크기 구하기
	for (int i = 1; i <= m; i++) {
		//처음 윈도우 구하기
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += A[j];
		}
		//printf("sum: %d\n", sum);
		sumA[sum]++;
		if (i == m) break;
		for (int j = 1; j < m; j++) {
			//j-1이 이전꺼, j+i가 이번꺼
			sum -= A[j - 1];
			sum += A[(j + i - 1) % m];
			//printf("sum: %d\n", sum);
			sumA[sum]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		//처음 윈도우 구하기
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += B[j];
		}
		sumB[sum]++;
		if (i == n) break;
		for (int j = 1; j < n; j++) {
			//j-1이 이전꺼, j+i가 이번꺼
			sum -= B[(j - 1) % n];
			sum += B[(j + i - 1) % n];
			sumB[sum]++;
		}
	}

	//2. 0~K 까지[왼쪽 피자 0, 오른쪽 피자 K] ...[왼쪽 k, 오른쪽 0] 개수 곱
	
	for (int i = 1; i < K; i++) {
		//printf("%d  a: %d b: %d\n", i, mapA[i], mapB[i]);
		answer += sumA[i] * sumB[K - i];
	}
	answer += sumA[K];
	answer += sumB[K];
	printf("%d", answer);
	return 0;
}

/*
6
3 3
1 1 1 1 1 1
*/
