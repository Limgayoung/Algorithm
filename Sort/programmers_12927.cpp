#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

void printVector(vector<int> vec){
    for(int v:vec){
        printf("%d ",v);
    }
    printf("\n");
}

//야근 피로도 : 남은일 제곱의 합
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    //정렬 후 가장 큰 수부터 -1씩, N만큼 반복
    //10, 10, 8, 6, 4  N이 5라면
    //8 8 7 6 4 -> 64+64+49+36+16
    //n: 100만
    //다음 수가 현재 수와 같으면 현재 수의 맨 앞으로 가서 다시 -1씩 하기
    
    sort(works.begin(), works.end(), compare);
    //printVector(works);
    
    int nowIndex = 0;
    for(int i=0;i<n;i++){
        int nextIndex = nowIndex+1;
        
        if(works[nowIndex] == 0){ //모든 작업 완료!
            break;
        }
        works[nowIndex]--;
        if(nextIndex >= works.size()){ //다음 수가 없음 -> 0으로 돌아가기
            nextIndex = 0;
        }
        if(works[nowIndex] >= works[nextIndex]){ //큰 수 -1 완료함 -> 0으로 가기
            nextIndex = 0;
        }
        
        nowIndex = nextIndex;        
    }
    
    for(int i=0;i<works.size();i++){
        answer += (works[i] * works[i]);
    }
    //printf("%d", 8*8+8*8+7*7+6*6+4*4);
    return answer;
}
