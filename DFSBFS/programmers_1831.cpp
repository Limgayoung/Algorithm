#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

int N;
int cnt;
int maxMul;


/*
뒤에서부터 시작
num이 3으로 나눠 떨어지는 경우 -> *
num이 3으로 나눠 떨어지지 않을 때 -> +
*/

void dfs(int num, int plusCnt, int mulCnt){
    if(plusCnt > maxMul*2) return; //* 개수 초과
    
    if(num == 1 && plusCnt == mulCnt*2){ //숫자 완성
        cnt++;
        return;
    }
    
    if(num%3==0){        
        if(plusCnt >= (mulCnt+1)*2) //한 번 더 나눌 수 있다면 *
            dfs(num/3, plusCnt, mulCnt+1);
        dfs(num-3, plusCnt+3, mulCnt); //3번 + 하는 경우
    }
    else{ //+
        dfs(num-(num%3), plusCnt+(num%3), mulCnt);
    }
    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    int answer = 0;
    N = n;
    cnt = 0;
    
    maxMul = log(n)/log(3); //* 최대 개수
    dfs(n,0,0);
    answer = cnt;
    return answer;
}
