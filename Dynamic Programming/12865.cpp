#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[102][100002]; //물건, 무게 / 무게마다의 dp를 가지고 있음
int W[102];
int V[102];

int main() {

    int i, j;
    
    int N, K;
    int maxdp=0;

    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - W[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]); //j-w[i] : 그전 dp는 더할 무게를 뺀 값이어서
            }
            if (maxdp < dp[i][j]) maxdp = dp[i][j];
        }
    }
    printf("%d", maxdp);
    return 0;
}
