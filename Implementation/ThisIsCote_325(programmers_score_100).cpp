#include <string>
#include <vector>

using namespace std;

int N,M;

void printVector(vector<vector<int>> key){
    int size = key.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",key[i][j]);
        }
        printf("\n");
    }
}

vector<vector<int>> rotation(vector<vector<int>> key){ //90도 회전
    int size = key.size();
    vector<vector<int>> result;        
    
    //0열 N-1 행부터 차례로 result에 넣기
    for(int i=0;i<size;i++){
        vector<int> row;
        for(int j=size-1;j>=0;j--){
            row.push_back(key[j][i]);
        }
        result.push_back(row);
    }    
    return result;
}

bool isUnlock(vector<vector<int>> map, vector<vector<int>> key, int x, int y){
    int i,j;
    
    //map에 key 값 더하기
    for(i=x;i<x+M;i++){
        for(j=y;j<y+M;j++){
            map[i][j] += key[i-x][j-y];
        }
    }
    
    //합이 1인지 확인
    for(i=M;i<M+N;i++){
        for(j=M;j<M+N;j++){
            if(map[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

bool findKey(vector<vector<int>> map, vector<vector<int>> key){
    int i,j;
    
    for(i=0;i<N+M;i++){
        for(j=0;j<N+M;j++){
            if(isUnlock(map, key, i,j)){
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    printVector(key);    
    N = lock.size();
    M = key.size();
    int i,j;
    
    vector<vector<int>> compareMap(N+(M*2), vector<int>(N+(M*2), -1)); //-1로 초기화
    //compareMap의 가운데 부분을 lock으로 만들기
    for(i=M;i<M+N;i++){
        for(j=M;j<M+N;j++){
            compareMap[i][j] = lock[i-M][j-M];
        }
    }
    
    //find key
    for(i=0;i<4;i++){ //90도씩 회전하면서 확인
        key = rotation(key);
        if(findKey(compareMap, key)) return true;
    }
    return false;
}
