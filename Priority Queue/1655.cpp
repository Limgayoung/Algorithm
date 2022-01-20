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
    int i, x, minN, maxN;

    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int, vector<int>> maxq;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &x);

        if (minq.size() == maxq.size()) { //maxq에 넣어야 함
            maxq.push(x);
        }
        else { //minq에 넣어야 함
            minq.push(x);
        }

        if (!minq.empty()&&maxq.top() > minq.top()) { //두 숫자 바꾸기
            minN = minq.top();
            maxN = maxq.top();
            minq.pop();
            maxq.pop();

            minq.push(maxN);
            maxq.push(minN);
        }
        printf("%d\n", maxq.top());
    }


    return 0;
}
