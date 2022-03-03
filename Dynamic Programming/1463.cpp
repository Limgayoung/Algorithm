#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1000000];

int findMax(int a, int b) {

    if (a < b) return b;
    else return a;
}

int main() {

    int N;
    int i;
    
    scanf("%d", &N);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(i=2;i<=N;i++){
        
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }

    }

    printf("%d", dp[N]);

    return 0;
}
