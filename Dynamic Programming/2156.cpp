#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[10001];
int g[10001];


int main() {

    int N;
    int i,j;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d" , &g[i]);
    }

    dp[0] = g[0];
    dp[1] = g[0] + g[1];
    dp[2] = max(g[0] + g[2], g[1] + g[2]);
    dp[2] = max(g[0] + g[1], dp[2]);
    //dp[3] = max(g[0] + g[1] + g[3], g[1] + g[2]);
    //dp[3] = max(dp[3], dp[1] + g[3]);

    for (i = 3; i < N; i++) {
        dp[i] = max(g[i] + g[i - 1] + dp[i - 3], g[i] + dp[i - 2]);
        dp[i] = max(dp[i], dp[i - 1]); //안마시는 경우

        //printf("%d: %d\n",i, dp[i]);

        //dp[i] = max(dp[i], g[i - 1] + g[i-2]+dp[i-4]);
        //printf("%d\n", dp[i]);
    }

    printf("%d", dp[N - 1]);
    

    return 0;
}
