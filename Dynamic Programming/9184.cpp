#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int W[21][21][21];

int wFunc(int a, int b, int c) {

    //조건 1
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    //조건 2
    if (a > 20 || b > 20 || c > 20) {
        return wFunc(20,20,20);
    }
    if (W[a][b][c]!=NULL) return W[a][b][c];
    if (a < b && b < c) {
        W[a][b][c] = wFunc(a, b, c - 1) + wFunc(a, b - 1, c - 1) - wFunc(a, b - 1, c);
        return W[a][b][c];
    }
    else {
        W[a][b][c] = wFunc(a - 1, b, c) + wFunc(a - 1, b - 1, c) + wFunc(a - 1, b, c - 1) - wFunc(a - 1, b - 1, c - 1);
        return W[a][b][c];
    }

}


int main() {
    int i,x;
    int a, b, c;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == -1 && b == -1 && c == -1) break; //종료조건
        printf("w(%d, %d, %d) = %d\n", a, b, c, wFunc(a, b, c));
    }
    

    return 0;
}
