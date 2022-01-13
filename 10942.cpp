#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int N, M;
int n[2001];
bool dp[2001][2001] = { false };

void palindrome() {
    int i,j;

    for (i = 1; i <= N; i++) { //길이가 1일 때, 길이가 2일 때 같은 값이면 true
        dp[i][i] = true;
        if (n[i] == n[i + 1]) dp[i][i + 1] = true;
    }

    for (i = 2; i < N; i++) { //길이가 3 이상일 때 //i: 더해줄 길이
        for (j = 1; j <= N-i; j++) { //
            //맨 앞, 뒤가 같아야 함, 그 사이가 true여야 함
            if (n[j] == n[j+i] && dp[j+1][j+i-1])
                dp[j][j + i] = true;
        }
    }
}

int main() {


    int i, j;
    int s, e;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &n[i]);

    }

    scanf("%d", &M);

    palindrome();

    while (M--) { //질문 시작
        scanf("%d %d", &s, &e);

        printf("%d\n", dp[s][e]);
    }

    return 0;
}
