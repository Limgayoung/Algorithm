#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int N, K;
    int i, j;
    long long count = 0;
    int left, right, mid;
    int answer=0;

    scanf("%d", &N);
    scanf("%d", &K);

    left = 1;
    right = K;
    mid = (left + right) / 2;

    while (left <= right) {
        mid = (left + right) / 2;
        count = 0;
        for (i = 1; i <= N; i++) {
            count += min(N, mid / i);
        }

        if (count < K) {
            left = mid + 1;
        }
        else {
            answer = mid;
            right = mid - 1;
        }
        
    }

    printf("%d", answer);



    return 0;
}
