#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1002][1002] = { 0 };
char A[1002];
char B[1002];

int main() {

    int i, j;
    int t;
    int alen, blen;

    scanf("%s %s", A+1,B+1);

    alen = strlen(A+1);
    blen = strlen(B+1);

    for (i = 1; i<=alen; i++) {
        for (j = 1; j<=blen; j++) { 
            t = 0;
            if (A[i] == B[j]) t = 1;
            
            dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i-1][j-1] + t });
            //printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
        }
    }
    
    printf("%d", dp[alen][blen]);
   

    return 0;
}
