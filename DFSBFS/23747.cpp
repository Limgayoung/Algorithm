#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R,C;
char map[1001][1001];
bool isVisit[1001][1001];

//상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int findDir(char a){
    if(a=='U') return 0;
    else if(a=='D') return 1;
    else if(a=='L') return 2;
    else if(a=='R') return 3;
    else return -1;
}

bool isInside(int x, int y){
    if(x>0 && y>0 && x<=R && y <=C) return true;
    return false;
}

void dfs(int x, int y, char nowChar){
    isVisit[x][y] = true;
    
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(isInside(nx,ny) && map[nx][ny] == nowChar && isVisit[nx][ny] == 0){           
            dfs(nx,ny,nowChar);
        }
    }
}

int main(int argc, char** argv)
{
    scanf("%d %d",&R,&C);
    
    string str;
    for(int i=1;i<=R;i++){
        cin>>str;
        for(int j=1;j<=C;j++){
            map[i][j] = str[j-1];            
        }
    }
    
    int x,y;
    scanf("%d %d",&x,&y);
    
    cin>>str;
    for(int i=0;i<str.length();i++){
        int nowDir = findDir(str[i]);
        if(nowDir == -1){ //W
            //printf("와드! map[%d][%d]: %c\n",x,y,map[x][y]);
            dfs(x,y,map[x][y]);
        }
        else{ //이동
            
            x += dx[nowDir];
            y += dy[nowDir];
            //printf("이동! dir: %c map[%d][%d]: %c\n",nowDir, x,y,map[x][y]);
        }        
    }
    
    //printf("마지막 위치 : map[%d][%d]: %c\n",x,y,map[x][y]);
    isVisit[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(isInside(nx,ny)){
            isVisit[nx][ny] = true;
        }
    }
    
    int answer = 0;
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(isVisit[i][j]) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    
    
    
    return 0;
}
