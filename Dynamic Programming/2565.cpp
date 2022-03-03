#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dp[1001];
//int A[1001][2];


int main() {

    int N;
    int i,j;
    int maxDP = 0;
    int a, b;

    scanf("%d", &N);

    vector<pair<int,int>> A;

    for (i = 0; i < N; i++) {
        scanf("%d %d" , &a,&b);
        A.push_back(make_pair(a, b));
        dp[i] = 1;
    }

    //앞을 기준으로 정렬
    sort(A.begin(), A.end(), greater<>());

    for (i = 0; i < N; i++) {
        for (j = 0; j <i ; j++) {
            if (A[i].second < A[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxDP = max(maxDP, dp[i]);
    }

    printf("%d", N - maxDP);




    return 0;
}
