#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> map(5,vector<int>(5)); //0빈자리 1파티션 2사용자
pair<int,int> checkPoint; //비교할 사용자 위치
int flag = 0;

void printMap(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isInside(int x,int y){ //map 안인지 확인
    if(x < 5 && x >= 0 && y < 5 && y >= 0) return 1;    
    else return 0;
}

int calManDistance(int x,int y){ //맨해튼 거리 계산
    int mx = checkPoint.first - x;
    int my = checkPoint.second - y;
    if(mx < 0) mx = -mx;
    if(my < 0) my = -my;
    
    return mx+my;
}

void dfs(int x,int y){
    if(flag == 1 || isInside(x,y) == 0 || calManDistance(x,y) > 2) return;
    
    for(int i=0;i<4;i++){ //4방향 확인
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(isInside(nx,ny) == 1 && calManDistance(nx,ny) <= 2){
            if(map[nx][ny] == 0){ //빈자리, 계속 탐색
                if(calManDistance(nx,ny) == 2) continue;
                dfs(nx,ny);
            }
            else if(map[nx][ny] == 2){ //사용자
                
                //printf("사용자 위치: (%d, %d)\n", nx, ny);
                flag = 1;
                break;
            }
            
        }        
    }
}

int checkDistancing(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(map[i][j] == 2){ //사용자일 경우 체크
                checkPoint = {i,j};
                map[i][j] = 3;
                //printf("checkPoint: %d, %d\n",i,j);
                dfs(i,j);
                if(flag == 1){ //거리두기 안지킴
                    //printf("거리두기 안지킴\n");
                    return 0;                    
                }
            }
        }
    }
    //printf("거리두기 지킴\n");
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    //1. 배열로 옮기기
    for(int i=0;i<5;i++){ //각 대기실
        flag = 0;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k] == 'P'){ //사용자
                    map[j][k] = 2;
                }
                else if(places[i][j][k] == 'O'){ //빈자리
                    map[j][k] = 0;
                }
                else if(places[i][j][k] == 'X'){ //파티션
                    map[j][k] = 1;
                }
            }
        }
        //printMap();
        //각 대기실마다 거리두기 확인
        int result = checkDistancing();
        answer.push_back(result);
    }

    return answer;
}
