#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int N, M; //추의 개수, 확인할 구슬 개수
int n[31]; //
bool dp[31][15001]; //추의 최대 무게 500, 최대 개수 30 -> 15000까지 잴 수 있음

void checkWeight(int i, int w) {
    if (dp[i][w] || i > N) return;

    dp[i][w] = true;
    checkWeight(i + 1, w + n[i]); //추만 올릴 때
    checkWeight(i + 1, abs(w-n[i])); //추 + 맞출 무게
    checkWeight(i + 1, w); //아무것도 안할 때

}

int main() {
   
    int i;
    int q;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    scanf("%d", &M);


    checkWeight(0, 0);

    for (i = 0; i < M; i++) {
        scanf("%d", &q);

        if (q > 15000) printf("N ");
        else if (dp[N][q]) printf("Y ");
        else printf("N ");

    }

    return 0;
}
