#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int absoluteNum(int x) {
    if (x > 0) return x;
    else return -x;
}

int main() {
    int N;
    int i, x;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //오름차순 정렬

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &x);

        if (x == 0) { //pop
            if (pq.empty()) {
                printf("0\n");
            }
            else { 
                printf("%d\n", pq.top().second);
                pq.pop();
            }
        }
        else {//push
            pq.push(make_pair(absoluteNum(x), x));
        }
    }



    return 0;
}
