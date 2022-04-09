#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n[1001];

int main() {

    int N;
    int i;
    int sum=0;
    int answer = 0;

    scanf("%d" , &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    sort(n, n + N);

    for (i = 1; i < N; i++) {
        //sum = sum + n[i - 1] + n[i];

        n[i] = n[i - 1] + n[i];
        //printf("%d ", n[i]);
    }

    for (i = 0; i < N; i++) {
        sum += n[i];
    }

    printf("%d", sum);
    return 0;
}
