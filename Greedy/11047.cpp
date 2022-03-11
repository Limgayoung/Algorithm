#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int coin[11];

int main() {

    int N, K;
    int i, t;
    int sum = 0;

    scanf("%d %d", &N, &K);

    for (i = 0; i < N; i++) {
        scanf("%d", &coin[i]); //오름차순으로 들어옴
    }

    for (i = N - 1; i >= 0; i--) {
        if (K == 0) break;

        sum += K / coin[i];
        K = K % coin[i];
    }

    printf("%d", sum);


    return 0;
}
