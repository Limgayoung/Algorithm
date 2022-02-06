#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long n[101] = { 1,1,1};

int main() {

    int T;
    int N;
    int i;
    
    scanf("%d" , &T);

    for (i = 3; i < 100; i++) {
        n[i] = n[i - 3] + n[i - 2];
    }

    for (i = 0; i < T; i++) {
        scanf("%d", &N);

        printf("%lld\n", n[N-1]);
    }

    return 0;
}
