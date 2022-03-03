#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long dp[101][10] = { 0 };

int main() {

    int N;
    int i,j;
    long long sum = 0;

    scanf("%d", &N);

    for (i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    
    for (i = 2; i <= N; i++) {
        for (j = 0; j <= 9; j++) {
            if (j == 0) { //뒤의 자리 수가 1만 됨
                dp[i][0] = dp[i - 1][j+1];
            }
            else if (j == 9) {
                dp[i][9] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
            dp[i][j] %= 1000000000;
            //printf("%d\n", dp[i][j]);
        }
    }

    for (i = 0; i < 10; i++) {
        sum = (sum + dp[N][i]) % 1000000000;
    }
    
    printf("%d", sum);

    return 0;
}
