#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1001];
int A[1001];


int main() {

    int N;
    int i,j;
    //int max = 0;
    int maxDP = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d" , &A[i]);
        dp[i] = 1;
    }

   // dp[0] = 1;
    maxDP = dp[0];

    for (i = 1; i < N; i++) {
        //dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (A[i] > A[j]) { //비교 후 dp 값 업데이트
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxDP = max(maxDP, dp[i]);

    }

    printf("%d", maxDP);

    return 0;
}
