#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int findMax(int a, int b) {

    if (a < b) return b;
    else return a;
}

int T[501][501];
int dp[501][501] = { 0 };


int main() {

    int N;
    int i,j;
    int max;
    
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= i; j++) {
            scanf("%d", &T[i][j]);
        }
    }

    dp[1][1] = T[1][1];

    for (i = 2; i <= N; i++) { //층수
        for (j = 1; j <= i; j++) {            
            dp[i][j] = T[i][j] + (findMax(dp[i - 1][j - 1], dp[i - 1][j]));           
        }
    }

    max = 0;
    for (i = 1; i <= N; i++) {
        if (max < dp[N][i]) max = dp[N][i];
    }
    printf("%d", max);

    return 0;
}
