#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N[100002];
int dp[100002];

int main() {

    int i, j;
    int n;
    int maxdp;
   
    scanf("%d", &n);

    dp[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &N[i]);
        dp[i] = N[i];
    }
    maxdp = dp[1];

    for (i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + N[i]);
        //printf("dp[%d]: %d\n",i, dp[i]);
        if (maxdp < dp[i]) maxdp = dp[i];
    }

    printf("%d", maxdp);

    return 0;
}
