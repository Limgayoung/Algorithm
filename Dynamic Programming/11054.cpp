#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int indp[1001];
int dedp[1001];
int dp[1001];
int A[1001];


int main() {

    int N;
    int i,j;
    int maxDP = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d" , &A[i]);
        indp[i] = 1;
        dedp[i] = 1;
    }

    for (i = 1; i < N; i++) {
        for (j = 0; j <= i; j++) {
            if (A[i] > A[j]) { //increase++;
                indp[i] = max(indp[i], indp[j]+1);
            }
        }
       
    }

    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= i; j--) {
            if (A[i] > A[j]) {
                dedp[i] = max(dedp[i], dedp[j] + 1);
            }
        }
    }

    for (i = 0; i < N; i++) {
        dp[i] = indp[i] + dedp[i]-1;
        //printf("%d: %d %d %d\n", A[i], dp[i], indp[i], dedp[i]);

        maxDP = max(maxDP, dp[i]);

    }

    printf("%d", maxDP);

    return 0;
}
