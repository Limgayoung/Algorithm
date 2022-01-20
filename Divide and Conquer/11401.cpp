#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

int p = 1000000007;

long long factorial(long long N) {
	if (N == 1) {
		return 1;
	}
	else return (factorial(N - 1) * N) % p;
}

long long square(int N, long long num) {
	long long value;
	if (N == 0) {
		return 1;
	}
	else {
		value = square(N / 2, num) %p;
		value = value * value % p;

		if (N % 2 == 1) { //홀수
			return value * num % p;
		}
		else return value%p;
	}
}

int main() {
	int N, K;
	int x;
	long long son=1, momk=1 , momnk=1 , mom =1;
	long long answer;
	int squarenum;
	int i;

	scanf("%d %d", &N, &K);

	x = N - K;
	squarenum = 1000000005;
	
	//분자 구하기
	for (i = 1; i <= N; i++) {
		son *= i;
		son %= p;
	}

	//momk 구하기
	for (i = 1; i <= K; i++) {
		mom *= i;
		mom %= p;
	}

	//momnk 구하기
	for (i = 1; i <= N-K; i++) {
		mom *= i;
		mom %= p;
	}

	mom = square(squarenum, mom);

	answer = son * mom;

	printf("%lld", answer%p);


	return 0;
}
