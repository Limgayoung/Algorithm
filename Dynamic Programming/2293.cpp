#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int n, k;
int coin[101];
int dp[10001] = { 0 };


int main() {
    int i,j;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    dp[0] = 1;

    for (i = 0; i < n; i++) {
        if (coin[i] > k) continue;

        for (j = coin[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]]; 
        }
    }

    printf("%d", dp[k]);

    return 0;
}
