#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int findMin(int a, int b) {

    if (a < b) return a;
    else return b;
}

int findMin(int r, int g, int b) {

    r = findMin(r, g);
    return findMin(r, b);

}

int main() {

    int N;
    int i;


    
    scanf("%d", &N);

    vector<vector<int>> cost(N, vector<int>(3));
    vector<vector<int>> rgb(N, vector<int>(3));


    for (i = 0; i < N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    rgb[0][0] = cost[0][0]; rgb[0][1] = cost[0][1]; rgb[0][2] = cost[0][2];

    for (i = 1; i < N; i++) {
        rgb[i][0] = cost[i][0] + min(rgb[i - 1][1], rgb[i - 1][2]);
        rgb[i][1] = cost[i][1] + min(rgb[i - 1][0], rgb[i - 1][2]);
        rgb[i][2] = cost[i][2] + min(rgb[i - 1][0], rgb[i - 1][1]);
    }
    
    printf("%d", findMin(rgb[N - 1][0], rgb[N - 1][1], rgb[N - 1][2]));

    return 0;
}
