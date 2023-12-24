#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

void printVector(vector<vector<int>> routes){
    for(vector<int> v:routes){
        printf("%d %d\n",v[0],v[1]);
    }
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    //1. 정렬 - 진입 시점 빠른순, 진출 시점 빠른순
    sort(routes.begin(), routes.end(), compare);
    //printVector(routes);
    
    //2. 감시카메라 개수 계산
    //이전 진출이 현재 진입, 진출 구간 사이에 있다면 감시카메라 공유 가능
    //겹치는 구간이 아니라면 현재 구간에 감시카메라 설치 필요
    int beforeOut = routes[0][1];
    int curIn, curOut;
    answer++;
    for(int i=1;i<routes.size();i++){
        curIn = routes[i][0];
        curOut = routes[i][1];
        
        if(beforeOut < curIn || beforeOut > curOut){ //겹치는 구간 x
            answer++;
            beforeOut = curOut;
        }                
    }
    
    return answer;
}
