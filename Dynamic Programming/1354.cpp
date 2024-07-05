#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/*
10초
0 ≤ N ≤ 10^13
2 ≤ P, Q ≤ 10^9
0 ≤ X, Y ≤ 10^9

배열 크기가 4 * 10^13  -> 메모리 초과가 나지 않을지...
-> Map 사용 -> logN 만큼의 메모리만 필요하다
dp를 하나씩 일일이 다 구하면 시간초과가 남 (최대10^13를 구해야 하니까)
-> 재귀로 풀기? -> logN
A[12] = A[5] + A[4] = 8
A[5] = A[1] + A[1] = 4
A[1] = A[0] + A[0] = 2
A[4] = A[1] + A[1] = 4
*/

long long N, P, Q, X, Y;
map<long long, long long> dp;

//A[n]을 구함
long long findDp(long long n) {
	if (n <= 0) return 1;
	if (dp.count(n) > 0) return dp[n];	
	
	//long long a = n / P - X;
	//if (a < 0) a = 0;
	//long long b = n / Q - Y;
	//if (b < 0) b = 0;

	dp.insert({ n, findDp(n/P-X) + findDp(n/Q-Y) });
	return dp[n];
}

int main()
{
	scanf("%lld %lld %lld %lld %lld", &N, &P, &Q, &X, &Y);
	dp.insert({ 0,1 });

	printf("%lld", findDp(N));
}

/*
10000000000000 2 2 0 0

10000000000000 2 2 0 0
A[10000000000000] = A[5000000000000] + A[5000000000000]
A[5000000000000] = A[2500000000000] + A[2500000000000]
*/
