#include <string>
#include <vector>

using namespace std;

//우좌상하 방향
//direction 0123
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

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

vector<vector<int>> move(vector<vector<int>> key, int x, int y){ //1칸 이동
    int size = key.size();
    int i=0,j=0;
    int copyStartI=0, copyEndI=size, copyStartJ=0,copyEndJ=size;
    int pasteStartI=0,pasteEndI=size,pasteStartJ=0,pasteEndJ=size;
    
    vector<vector<int>> result(size, vector<int>(size, 0)); //0으로 초기화        
    
    if(y == 0){ 
        if(x==1){ //오른쪽으로 이동
            copyEndI=size-1;
            pasteStartI=1;
        }
        else{ //왼쪽으로 이동
            copyStartI=1;
            pasteEndI=size-1;
        }
    }
    else{
        if(y==1){ //위로 이동
            copyStartJ=1;
            pasteEndJ=size-1;
        }
        else{ //아래로 이동
            copyEndJ=size-1;
            pasteStartJ=1;            
        }
    }
    
    int pasteI=pasteStartI, pasteJ=pasteStartJ;
    
    for(i=copyStartI;i<copyEndI;i++){
        pasteJ=pasteStartJ;
        for(j=copyStartJ;j<copyEndJ;j++){
            result[pasteJ][pasteI] = key[j][i];
            pasteJ++;
        }
        pasteI++;
    }    
    return result;
}

bool isUnlock(vector<vector<int>> key, vector<vector<int>> lock){ //풀렸는지 확인
    int size = key.size();
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(key[i][j] + lock[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

bool dfs(vector<vector<int>> key,vector<vector<int>> lock, int count, int size){  
    bool answer = false;
    if(isUnlock(key, lock)) {
        answer = true;
        return true;        
    }
    if(count >= size){ //이미 다 이동했음
        return false;
    }
    
    for(int i=0;i<4;i++){ //4방향        
            answer = dfs(move(key, x[i], y[i]), lock, count+1, size);
            if(answer) return true;        
    }
    return answer;
}

bool findKey(vector<vector<int>> key, vector<vector<int>> lock){
    int size = key.size();        
    //90도 돌리고 1칸씩 모든 방향으로 size 만큼 이동        
    for(int i=0;i<4;i++){
        key = rotation(key);        
        if(dfs(key, lock, 0, size)) return true;
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    printVector(key);    
    
    bool answer;
    answer = findKey(key, lock);    
    
    return answer;
}
