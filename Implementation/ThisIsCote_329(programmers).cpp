#include <string>
#include <vector>

using namespace std;

bool map[101][101][2]={false}; //x, y, 기둥/보 여부 0: 기둥 1: 보
int mapSize;

bool sizeCheck(int x,int y){
    if(x < 0 || y < 0 || x > mapSize || y > mapSize){
        return false;
    }
    return true;
}

bool isCanInstall(int x, int y, int type){
    //기둥    
    if(type == 0){
        if(y==0){ //바닥에 설치
            return true;
        }
        else if(sizeCheck(x,y-1) && map[x][y-1][0]){ //아래가 기둥이면
            return true;
        }
        else if(map[x][y][1] || (sizeCheck(x-1, y) && map[x-1][y][1])){ //아래가 보
            return true;
        }
    }
    //보
    else{
        if((sizeCheck(x,y-1) && map[x][y-1][0]) || (sizeCheck(x+1,y-1) && map[x+1][y-1][0])){ //아래가 기둥
            return true;
        }
        if((sizeCheck(x-1,y) && sizeCheck(x+1,y) && map[x-1][y][1] && map[x+1][y][1])){ //양 옆이 보
            return true;
        }
    }
    return false;
}

bool isCanUninstall(){
    for(int i=0;i<=mapSize;i++){
        for(int j=0;j<=mapSize;j++){
            for(int k=0;k<2;k++){
                if(map[i][j][k] == 1){
                    if(!isCanInstall(i,j,k)) return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int i,j;
    int x,y,a,b;
    mapSize = n;
    int commandSize = build_frame.size();
    
    for(i=0;i<commandSize;i++){
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        
        if(b == 1){ //설치
            // printf("install x: %d y: %d a: %d\n", x,y,a);
            if(isCanInstall(x,y,a)){
                // printf("설치\n");
                map[x][y][a] = true;
            }
        }
        else{ //삭제
            // printf("uninstall x: %d y: %d a: %d\n", x,y,a);
            map[x][y][a] = false; //일단 먼저 삭제
            if(!isCanUninstall()) {
                map[x][y][a] = true;
            }
            // else printf("삭제\n");
        }
    }
    
    int answerCnt=0;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                if(map[i][j][k] == true){
                    vector<int> answerRow;
                    answerRow.push_back(i);
                    answerRow.push_back(j);
                    answerRow.push_back(k);
                    answer.push_back(answerRow);
                }
            }
        }
    }
    
    
    return answer;
}
