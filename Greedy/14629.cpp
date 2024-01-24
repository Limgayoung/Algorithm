#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>

using namespace std;

int num[15];
int numSize;
set<int> useNum; //smallNum
set<int> useBigNum;

void printNum(){
    printf("num 출력\n");
    for(int i=0;i<numSize;i++){
        printf("%d ",num[i]);
    }
    printf("\n\n");
}

void initNum(string str){
    numSize = str.size();
    for(int i=0;i<numSize;i++){
        num[i] = str[i]-'0';
    }    
}

void initUseBigNum(){
    for(auto iter:useNum){
        useBigNum.insert(iter);
    }
}

int findSmallNum(){
    for(int i=0;i<=9;i++){
        if(useNum.count(i) == 0) return i;
    }
}

int findBigNum(){
    for(int i=9;i>=0;i--){
        if(useNum.count(i) == 0) return i;
    }
}

int findNearSmallNum(int n){
    for(int i=n;i>=0;i--){
        if(useNum.count(i) == 0 && i != n) return i;
    }
    return -1;
}

int findNearBigNum(int n){
    for(int i=n;i<=9;i++){
        if(useNum.count(i) == 0 && i != n) return i;
    }
    return -1;
}

string makeSmallNum(string n){    
    int t = 0;
    for(int i=n.size()-1;i>=0;i--){ //마지막 꺼부터 작은거로 변환 ㄱㄴ하면 변환
        t++;
		int nowNum = n[i]-'0';
        useNum.erase(useNum.find(nowNum));
        int smallNum = findNearSmallNum(nowNum);
        n.pop_back();
        
        if(smallNum != -1) { //변경 가능
            n += to_string(smallNum);
            useNum.insert(smallNum);
            break;
        }        
    }
    t--;
    for(t;t>0;t--){
        int bigNum = findBigNum();
        n += to_string(bigNum);
        useNum.insert(bigNum);
    }

    return n;
}

string makeBigNum(string n){
    int t = 0;
    for(int i=n.size()-1;i>=0;i--){ //마지막 꺼부터 큰거로 변환 ㄱㄴ하면 변환
        t++;
		int nowNum = n[i]-'0';
        useNum.erase(useNum.find(nowNum));
        int bigNum = findNearBigNum(nowNum);
        n.pop_back();
        
        if(bigNum != -1) { //변경 가능
            n += to_string(bigNum);
            useBigNum.insert(bigNum);
            break;
        }        
    }
    t--;
    for(t;t>0;t--){
        int smallNum = findSmallNum();
        n += to_string(smallNum);
        useNum.insert(smallNum);
    }

    return n;
}

int main(int argc, char** argv)
{

    //1. string으로 입력받기
    string str;
    string small="", big="";
    
    cin >> str;
    
    // size가 10보다 큰 경우에 9876543210이 답
    if(str.size() > 10) {
        printf("9876543210");
        return 0;
    }
    
    initNum(str);
    
    //2. 앞에서부터 big, small 값 저장하기
    //2-1. 안겹치면서 같은 수일 경우엔 계속 진행
    //2-2. 겹치면 big/small 나눠서 계산
    //2-3. 현재 자리수보다 작은 수가 없을 경우에 앞자리를 작은 수로 변경해 더 작은 수로 만들어줘야함
    int i;
    for(i=0;i<numSize;i++){
        int nowNum = num[i];        
        if(useNum.count(nowNum) != 0){ //사용 불가능
            //가장 가까운 작은거 큰거 찾아야함, 원래 로직 사용 필요
            initUseBigNum();
            int nextSmall = findNearSmallNum(nowNum);
            int nextBig = findNearBigNum(nowNum);
            
            if(nextSmall == -1){ //앞자리 변경 필요
                small = makeSmallNum(small); //210 -> 209
                nextSmall = findBigNum();
            }
            
            if(nextBig == -1){
                big = makeBigNum(big);
                nextBig = findSmallNum();
            }       
            small += to_string(nextSmall);
            useNum.insert(nextSmall);
            big += to_string(nextBig);
            useBigNum.insert(nextBig);
            break;
        }
        //사용 가능
        small += to_string(nowNum);
        big += to_string(nowNum);
        useNum.insert(nowNum);
    }

    //나머지 숫자 만들어줘야함
    i++;
    for(i;i<numSize;i++){
        int findSmall = findSmallNum();
        int findBig = findBigNum();
        
        small += to_string(findBig);
        useNum.insert(findBig);
        big += to_string(findSmall);
        useBigNum.insert(findSmall);
    }
    
    long long smallDiff = abs(stoll(str)-stoll(small));
    long long bigDiff = abs(stoll(big)-stoll(str));

    if(smallDiff > bigDiff) cout<<stoll(big);
    else cout<<stoll(small);
	return 0;
}
