#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <set>

using namespace std;

int A[100001];

int main() {
    int N;
    int i;

    //vector<int> a;
    int num;
    int lowNum;

    scanf("%d", &N);

    vector<int> a;

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    a.push_back(A[0]);

    for (i = 1; i < N; i++) {
        num = A[i];

        if (num > a.back()) { //뒤에 넣기
            a.push_back(num);

        }
        else { //lower_bound로 위치 바꾸기
            auto x = lower_bound(a.begin(), a.end(), num);
            *x = num;
        }
    }

    printf("%d", N-a.size());

    return 0;
}


/*
5
1000 1 1
1001 2 1
19998 78 2
2667 37 3
2042 55 3
8
recommend 1 1
recommend 1 -1
recommend2 1
recommend2 -1
recommend3 1 50
recommend3 -1 50
recommend3 1 37
recommend3 -1 78
*/
