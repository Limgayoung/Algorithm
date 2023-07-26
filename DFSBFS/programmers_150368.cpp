#include <string>
#include <vector>

using namespace std;

int sale[4] = {10,20,30,40};
vector<vector<int>> u;
vector<int> e;
int plusCount = 0;
int salesCount = 0;

void vectorPrint(vector<int> v){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);        
    }
    printf("\n");
}

pair<int,int> calCount(vector<int> saleEmoticons){ //플러스 가입자, 판매액 계산
    int sum;
    int pCount=0;
    int sSum=0;
    for(int i=0;i<u.size();i++){
        sum = 0;
        for(int j=0;j<saleEmoticons.size();j++){
            if(u[i][0] <= saleEmoticons[j]){
                sum += e[j] * (100-saleEmoticons[j]) / 100;
            }
        }
        if(u[i][1] <= sum){ //이모티콘 플러스 구독
            pCount++;
        }
        else{
            sSum+=sum;        
        }
    }
    return make_pair(pCount, sSum);
}

void dfs(int x, vector<int> saleEmoticons, int lastEmoticon){
    if(x!=0) saleEmoticons.push_back(lastEmoticon);
    
    if(saleEmoticons.size() == e.size()){ //종료 조건        
        pair<int,int> result = calCount(saleEmoticons);
        //printf("result plus가입자: %d  판매액: %d\n",result.first, result.second);
        if(result.first > plusCount){
            plusCount = result.first;
            salesCount = result.second;
        }
        else if(result.first == plusCount && result.second > salesCount){
            plusCount = result.first;
            salesCount = result.second;
        }
    }
    
    for(int i=0;i<4;i++){
        if(x < e.size()){
            dfs(x+1, saleEmoticons, sale[i]);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    u = users;
    e = emoticons;
    vector<int> saleEmoticons;
    
    dfs(0,saleEmoticons,0);
    answer.push_back(plusCount);
    answer.push_back(salesCount);
    
    return answer;
}
