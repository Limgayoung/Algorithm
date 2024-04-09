#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*
1000 * 1000 -> 1000000 -> 0.01초
dp를 사용? 흠냐리...
dp[i][j] : A i개, B j개 비교했을 때 lcs 길이
dp[0][0] ~ dp[N-1][M-1] 구하기, dp[N-1][M-1]이 최장길이
ACAYKP
CAPCAK


*/
string A, B;
int lengthA, lengthB;
vector<vector<int>> dp;

void printDP() {
	printf("  ");
	for (int i = 0; i < lengthB; i++) {
		printf("%c ", B[i]);
	}
	printf("\n");
	for (int i = 0; i < lengthA; i++) {
		printf("%c ", A[i]);
		for (int j = 0; j < lengthB; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int leftLength(int x, int y) {
	y--;
	if (x < 0 || x >= lengthA || y < 0 || y >= lengthB) return -1;
	return dp[x][y];
}

int upLength(int x, int y) {
	x--;
	if (x < 0 || x >= lengthA || y < 0 || y >= lengthB) return -1;
	return dp[x][y];
}

int main() {

	//dp에서 A가 행, B가 열


	cin >> A;
	cin >> B;

	lengthA = A.length();
	lengthB = B.length();

	dp = vector<vector<int>>(lengthA, vector<int>(lengthB, 0));

	//테두리 dp 초기화
	if (A[0] == B[0]) dp[0][0] = 1;
	if (lengthA > 1) {
		for (int i = 1; i < lengthA; i++) {
			if (A[i] == B[0]) dp[i][0] = 1;
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		}
	}
	if (lengthB > 1) {
		for (int i = 1; i < lengthB; i++) {
			if (A[0] == B[i]) dp[0][i] = 1;
			dp[0][i] = max(dp[0][i], dp[0][i - 1]);
		}
	}
	
	//나머지 dp 계산
	for (int i = 1; i < lengthA; i++) {
		for (int j = 1; j < lengthB; j++) {
			//max 값 만들기		
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (A[i] == B[j]) { //맨 끝 글자와 같다면 +1
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}

	//printDP();

	//LCS 문자열 찾기
	//위, 왼쪽으로 가면서 현재 length 마지막 위치 찾기
	//왼쪽 방향이면 왼쪽 먼저 검사, 위쪽 방향이면 위쪽 먼저 검사 필요
	//bool isUp = false;
	

	//if (lengthA>1 && lengthB>1 && dp[lengthA - 2][lengthB - 1] >= dp[lengthA - 1][lengthB - 2]) isUp = true;

	string str = "";
	int nowLength = dp[lengthA - 1][lengthB - 1];
	int x = lengthA - 1;
	int y = lengthB - 1;
	while (true) {
		//printf("dp[%d][%d]: %d\n", x, y, dp[x][y]);		
		if (upLength(x, y) == nowLength) {
			x -= 1; 
			if (leftLength(x, y) == nowLength) {
				y -= 1;
			}
		}
		else if (leftLength(x, y) == nowLength) {
			y -= 1;
			if (upLength(x, y) == nowLength) {
				x -= 1;
			}
		}
		else { //왼쪽, 위 모두 다름 -> 여기에서 바뀜
			//printf("------------change!!----------\n");
			if (x == 0 && y == 0 && dp[0][0] == 0) break;
			str = A[x] + str;
			nowLength--;
			if (x == 0 && y == 0) break;
		}	
	}

	printf("%d\n", dp[lengthA-1][lengthB-1]);
	if(dp[lengthA - 1][lengthB - 1] != 0) 
		cout << str << endl;

	return 0;
}

/*

CAPCAK
ACAYKP

ABCDE
ABCDE

AABBCCDD
AABBCCDD

AABBCCDD
BBCCDD

A
A

ABCDEF
BEFDEFACDFABZ

ABCDEF
BEFDEF
ABCDEF
*/
