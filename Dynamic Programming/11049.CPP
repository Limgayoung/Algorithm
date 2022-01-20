#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int dp[501][501] = { 0 };

int main() {

    int N;
    int m[501][2];
    int i, j,k;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) { //1부터 시작해야 함
        scanf("%d %d", &m[i][0], &m[i][1]);
    }

    for (i = 1; i < N; i++) {//구간 범위       
        for (j = 1; i+j <= N; j++) {//시작 지점
            dp[j][i + j] = INT_MAX;

            for (k = j; k <= i+j; k++) { //구간 나누는 기준점
                //dp 값 구하기
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (m[j][0] * m[k][1] * m[i + j][1])); //NMK
            }
        }
    }

    printf("%d", dp[1][N]);

    return 0;
}
