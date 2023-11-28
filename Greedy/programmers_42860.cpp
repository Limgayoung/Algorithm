#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

pair<int,int> findCursorIndex(string name, string makeName, int index){
    int leftCnt, rightCnt;
    int leftIndex, rightIndex;
    
    leftCnt = rightCnt = 0;
    leftIndex = rightIndex = index;
    //왼쪽으로 이동
    while(name[leftIndex] == makeName[leftIndex]){
        leftCnt++;
        leftIndex--;
        if(leftIndex<0){
            leftIndex = n-1; //마지막 위치로 이동
        }
    } 
    
    //오른쪽으로 이동
    while(name[rightIndex] == makeName[rightIndex]){
        rightCnt++;
        rightIndex++;
        if(rightIndex>=n){
            rightIndex = 0; //처음 위치로 이동
        }
    }
    
    if(leftCnt < rightCnt){
        return {leftCnt, leftIndex};
    }
    else return {rightCnt, rightIndex};
}

int solution(string name) {
    int answer = 0;
    string makeName = "";
    n = name.length();
    //커서를 움직여서 바꿀 알파벳으로 이동해야 함!!
    
    //초기에 전부 A
    for(int i=0;i<n;i++){
        makeName+='A';
    }
    
    int cnt = 0;
    int nowIndex=0; //현재 커서 위치
    int turn = n-1; //조이스틱을 한 방향으로 움직임
    
    for(int i=0;i<n;i++){
        // 현재 문자 변경하기
        char nowChar = makeName[i];
        char compareChar = name[i];
        answer += min(abs(compareChar - 'A'), 1+(abs('Z' - compareChar)));   
        makeName[i] = name[i];
        
        int ind = i+1;
        while(ind < n && name[ind] =='A') ind++; //변경할 문자가 A가 아닌 곳 찾기
        
        //원점->i->원점->ind  원점->ind->원점->i
        //한 번 방향 전환하면 됨
        turn = min(turn, i+n-ind + min(i, n-ind));        
    }
   
    answer += turn;

 
    return answer;
}
