#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int s[301];
int dp[301];

int findMax(int a, int b) {

    if (a < b) return b;
    else return a;
}

int main() {

    int N;
    int i,j;
    int max;
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }

    dp[0] = s[0];
    dp[1] = s[0] + s[1];
    dp[2] = findMax(s[2] + s[0], s[1] + s[2]);
    
    for (i = 3; i < N; i++) {
        dp[i] = findMax(s[i] + dp[i - 2], s[i] + s[i - 1] + dp[i - 3]);
    }

    printf("%d", dp[N-1]);

    return 0;
}
