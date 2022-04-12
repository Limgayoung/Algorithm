#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n[100001];

int main() {

    int N;
    int i, j;
    int answer = 0;
    int count = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    sort(n, n + N);

    j = 0;
    for (i = 0; i < N; i++) {
        count++;

        if (count >= n[i]) {
            answer++;
            count = 0;
        }

    }

    printf("%d", answer);
    
    return 0;
}