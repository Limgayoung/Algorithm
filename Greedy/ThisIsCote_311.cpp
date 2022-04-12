#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int n[100001];

int main() {

    int N;
    int i, j;
    int answer = 0;
    int count = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    j = 0;
    for (i = 0; i < N-1; i++) {
        j++;
        if (count < n[i]) { //처음, 세는 중간에 더 큰 수가 들어오는 경우
            count = n[i];
        }       
        if (j == count) {
            answer++;
            count = n[i+1];
            j = 0;
        }        
    }

    if (j+1 == count && n[i] <= count) {
        answer++;
    }
   
    printf("%d", answer);
    
    return 0;
}