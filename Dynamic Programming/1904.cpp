#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long n[1000001] = { 1,2 };


int main() {

    int N;
    int i;

    scanf("%d", &N);

    for (i = 2; i < N; i++) {
        n[i] = (n[i - 1] + n[i - 2])%15746;
    }

    printf("%d", n[N - 1] % 15746);


    return 0;
}
