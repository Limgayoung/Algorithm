#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;

int visit[301][301];
int map[301][301];

int dx[8] = {0,0,1,-1,-1,1,-1,1};
int dy[8] = {1,-1,0,0,1,1,-1,-1};
int visitNum;

void printVisit(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");    
}

void dfs(int x, int y){    
    visit[x][y] = 1;
    visitNum++;

    for(int i=0;i<8;i++){ 
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx < N && ny < N && nx >= 0 && ny >= 0 && visit[nx][ny] == 0){
            if(map[nx][ny] == 0){
                dfs(nx,ny);
            }    
            else{
                visit[nx][ny] = 1;
                visitNum++;
            }
        }      
    }    
}

int main(int argc, char** argv)
{
   int test_case;
   int T;

   cin>>T;

   for(test_case = 1; test_case <= T; ++test_case)
   {
        cin>>N;                            
       	fill(&visit[0][0], &visit[300][300], 0);
        fill(&map[0][0], &map[300][300], 0);

        int answer = 0;
        visitNum = 0;

        for(int i=0;i<N;i++){
            string str;
            cin >> str;
         for(int j=0;j<str.size();j++){
                if(str[j]=='*') {
                    map[i][j] = -1;                
                    visit[i][j] = -1;
                    visitNum++;
                    for(int k=0;k<8;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];                
                        if(nx < N && ny < N && nx >= 0 && ny >= 0 && map[nx][ny] != -1){
                            map[nx][ny]++;
                        }
                    }
                }
            }
        }
       
       //printMap();
 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j] == 0 && visit[i][j] == 0){
                    dfs(i,j);
                    answer++;
                }
            }
        }
       //printVisit();
        int remainVisitNum = N*N - visitNum;
        //printf("visitNum: %d remainVisitNum: %d dfsNum: %d\n",visitNum, remainVisitNum, answer);
        answer+= remainVisitNum;
        printf("#%d %d\n",test_case, answer);
   }
   return 0;
}
