#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//900000 6 42 123456 일 때 안됨

//0~9까지 led 등
int num[10][7] = { {1,1,1,0,1,1,1}, {0,0,1,0,0,1,0}, {1,0,1,1,1,0,1},
{1,0,1,1,0,1,1}, {0,1,1,1,0,1,0}, {1,1,0,1,0,1,1},
{1,1,0,1,1,1,1}, {1,0,1,0,0,1,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1} };

//i -> j 바꾸는데 필요한 반전 횟수
int changeCost[10][10];
int N, K, P, X;
string numStr;
int answer = 0;
set<int> numSet;

int calCost(int a, int b) { //a를 b로 바꾸는 데 필요한 반전 횟수 계산
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (num[a][i] != num[b][i]) cnt++;
    }
    return cnt;
}

void initCost() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            changeCost[i][j] = calCost(i, j);
            //printf("cost %d to %d : %d\n", i, j, changeCost[i][j]);
        }
    }
}

string changeIntToString() { //X를 K자리의 string으로 바꾸기
    string s = to_string(X);
    while (s.length() < K) {
        s.insert(s.begin(), '0');
    }
    return s;
}

//변경할 자리 위치, 남은 변경 가능 횟수
void findMinCnt(int index, int remainCnt) {

    if (index >= numStr.length()) {
        int nowMakeNum = stoi(numStr);
        if (nowMakeNum <= N && nowMakeNum > 0 && nowMakeNum != X) {
            answer++;
        }
        return;
    }

    //변경할 자리의 원래 숫자
    int nowNum = numStr[index] - '0';

    for (int i = 0; i < 10; i++) { //0~9까지 변경 가능한 숫자 변경, 자기 자신이면 변경하지 않는 것    
        int cost = changeCost[nowNum][i];
        //printf("nowNum: %d i: %d cost: %d remainCost: %d\n", nowNum, i, cost, remainCnt);        
        if (remainCnt >= cost) { //변경 가능
            numStr[index] = i + '0';
            findMinCnt(index + 1, remainCnt - cost);
            numStr[index] = nowNum + '0';
        }
    }
}

int main(int argc, char** argv)
{
    scanf("%d %d %d %d", &N, &K, &P, &X);

    numStr = changeIntToString();
    initCost();

    findMinCnt(0, P);

    printf("%d", answer);
    return 0;
}
