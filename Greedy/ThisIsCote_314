#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int coin[1000001];

int main() {    
    
    int N;
    int i;
    int target;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    sort(coin, coin+N);

    target = 1;

    for (i = 0; i < N; i++) {
        if (coin[i] > target) {
            break;
        }
        else {
            target += coin[i];
        }
    }

    printf("%d", target);

    
}


/*
5 
3 2 1 1 9
*/
