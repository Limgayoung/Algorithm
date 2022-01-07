#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int F[41] = { 0,1 };


int main() {
    int N;
    int i,x;

    scanf("%d", &N);

    //미리 숫자를 구해놓기
    for (i = 2; i < 41; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }


    for (i = 0; i < N; i++) {
        scanf("%d", &x);
        
        if (x == 0) {
            printf("1 0\n");
        }
        else {
            printf("%d %d\n", F[x - 1], F[x]);
        }
    }
    

    return 0;
}
