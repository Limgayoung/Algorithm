#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;



int main() {

    int N;
    int i;
    int a, b;
    int answer = 0;
    int firstTime=0;

    scanf("%d", &N);

    vector<pair<int, int>> v(N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &a, &b); 

        //끝난 시간을 기준으로 정렬할 거라서 끝난 시간을 pair에 먼저 넣음
        v[i].first = b;
        v[i].second = a;
        
    }

    sort(v.begin(), v.end());

    for (i = 0; i < N; i++) {
        if (firstTime <= v[i].second) { //사용 가능
            //printf("firstTime: %d second : %d first : %d\n", firstTime, v[i].second, v[i].first);
            firstTime = v[i].first;
            answer++;
        }
    }

    printf("%d", answer);

    return 0;
}
