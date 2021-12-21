#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int A[1000001];

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

    printf("%d", a.size());

    return 0;
}
