#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {

    char s[21];
    int size;
    int num1,num2;
    long long answer = 0;
    int t=1;

    vector<int> v;

    scanf("%s", s);

    size = strlen(s);

    for (int i = 0; i < size; i++) {
        int num = s[i] - '0';

        if (num != 0) {
            v.push_back(num);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int num = v[i];         

        if (num == 1) {
            if (i + 1 < v.size()) { //다음 수가 있을 때
                v[i + 1] = v[i + 1]++;
                if (i == 0) {
                    answer = 1;
                }
            }
            else {
                answer += v[i];
            }
        }
        else {
            if (i == 0) { //맨 처음 수가 1이 아닌고 맨 앞일 때
                answer = 1;
            }
            answer *= v[i];
        }

        
    }

    printf("%lld", answer);
    
    return 0;
}