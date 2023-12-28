#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>


using namespace std;


int calMaxSum(vector<int> a, vector<int> b) { //더 짧은 것이 a
	int maxSum;
	int nowSum = 0;

	for (int i = 0; i <= b.size() - a.size(); i++) {
		nowSum = 0;
		for (int j = 0; j < a.size(); j++) {
			nowSum += (a[j] * b[i+j]);
		}
		if (i == 0) maxSum = nowSum;
		if (maxSum < nowSum) {
			maxSum = nowSum;
		}
		//printf("maxSum: %d nowSum: %d\n", maxSum, nowSum);
	}

	return maxSum;

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);

		vector<int> a(N);
		vector<int> b(M);

		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &b[i]);
		}

		int answer;
		if (N < M) {
			answer = calMaxSum(a, b);
		}
		else {
			answer = calMaxSum(b, a);
		}
		printf("#%d %d\n" , test_case, answer);
	}
	return 0;
}
