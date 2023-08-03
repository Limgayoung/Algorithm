#include <string>
using namespace std;

int visit[11][11][4]; //0123 왼위오아
int x,y;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solution(string dirs) {
    int answer = 0;
    int di;

    x=y=5;
    
    for(int i=0;i<dirs.size();i++){
        if(dirs[i] == 'L'){
            di = 0;
        }
        else if(dirs[i] == 'U'){
            di = 1;
        }
        else if(dirs[i] == 'R'){
            di = 2;
        }
        else if(dirs[i] == 'D'){
            di = 3;
        }
        
        int nx = x+dx[di];
        int ny = y+dy[di];
        
        if(nx >= 0 && nx < 11 && ny >=0 && ny <11){
            if(visit[nx][ny][((di+2)%4)] == 0 && visit[x][y][di] == 0){
                visit[nx][ny][((di+2)%4)] = 1;
                visit[x][y][di] = 1;
                answer++;
            }
            x = nx;
            y = ny;
        }
    }
    return answer;
}
