#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visit[101][101] = {0};
int mapN, mapM;
vector<vector<int>> map;
int areaSize;

void dfs(int x, int y, int color){
    int i;
    visit[x][y] = 1;
    areaSize++;
    for(i=0;i<4;i++){ //4방향 탐색
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && nx < mapM && ny >= 0 && ny < mapN && visit[nx][ny] == 0){
            if(map[nx][ny] == color){ //색이 같아야 탐색 가능
                dfs(nx,ny,color);
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    mapN=n;
    mapM=m;
    map = picture;
    
    fill(&visit[0][0],&visit[100][100],0);
    dx[0] = 1; dx[1] = -1; dx[2] = 0; dx[3] = 0;
    dy[0] = 0; dy[1] = 0; dy[2] = 1; dy[3] = -1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j] == 0 && map[i][j] != 0){
                areaSize=0;
                dfs(i,j,map[i][j]);
                number_of_area++;
                if(areaSize > max_size_of_one_area) max_size_of_one_area = areaSize;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
