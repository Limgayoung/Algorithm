#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int N,M;
int m[101];
int c[101];
int dp[101][10001] = { 0 };

int main() {
    int i,j;
    int sum=0;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i++) {
        scanf("%d", &m[i]);
    }

    for (i = 1; i <= N; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }

    for(i=1;i<=N;i++){
        for (j = 0; j <= sum; j++) {
            if (j - c[i] >= 0) { //주어진 cost(j)로 비활성화 가능
                dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + m[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            //중간에 출력 후 종료하면 틀리는 이유
            //cost 순서대로 확인한 것이 아님!!
        }
    }

    for (i = 0; i <= sum; i++) {
        if (dp[N][i] >= M) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}
