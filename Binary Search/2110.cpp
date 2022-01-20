#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int n[200001];


int canInstall(int N, int C, int distance) {
    int i;
    int temp;
    int count = 1;

    temp = n[0];
    for (i = 1; i < N; i++) {
        if (n[i]-temp >= distance) {
            count++;
            temp = n[i];
        }
    }

    if (count >= C) return 1;
    else return 0;
}


int main() {

    int N, C;
    int i;
    int left = 1, right = 0, mid = 0;
    int temp;
    int distance;
    int answer;

    scanf("%d %d", &N, &C);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    sort(n, n + N);

    for (i = 0; i < N - 1; i++) {
        temp = n[i + 1] - n[i];
        if (temp < left) left = temp;
    }

    left = 0;
    right = n[N - 1] - n[0];
    answer = right;


    while (left <= right) {
        mid = (left + right) / 2;
        if (canInstall(N, C, mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%d", answer);

    return 0;
}
