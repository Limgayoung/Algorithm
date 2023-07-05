#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
char map[6][6] = { 0 }; //T,S,O,X
int tnum = 0; //선생님 수
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0,1,-1 };
int flag = 0;
vector<pair<int, int>> e,t; //빈 칸 위치
int emptyNum; //빈 칸 개수

void printMap() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isThereStudent(int x,int y) {
    int i;
    int nx, ny;

    for (i = 0; i < 4; i++) { //4방향 확인
        nx = x;
        ny = y;
        while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] == 'O') //장애물 있으면 멈추기
                break;
            if (map[nx][ny] == 'S') { //학생 있음
                return true;
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    return false;
}

bool chekcAllTeacher() {
    int i;

    for (i = 0; i < tnum; i++) {
        if (isThereStudent(t[i].first, t[i].second)) { //학생 발견
            return false;
        }
    }
    return true; //통과
}

void dfs(int cnt, int index) {
    int i;

    if (cnt == 3) { //장애물 설치 완료
        if (chekcAllTeacher()) {
            printf("YES");
            exit(0);
        }        
        return;
    }    

    for (i = index; i < emptyNum; i++) {
        map[e[i].first][e[i].second] = 'O';
        dfs(cnt + 1, i+1);
        map[e[i].first][e[i].second] = 'X';
    }

}

int main() {  
   
    int i, j;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            getchar();
            scanf("%c", &map[i][j]);            
            if (map[i][j] == 'T')
                t.push_back(make_pair(i, j));                                            
            else if(map[i][j] == 'X')
                e.push_back(make_pair(i, j));            
        }
    }
    emptyNum = e.size();
    tnum = t.size();

    dfs(0, 0);

    printf("NO");

    return 0;
}

/*
5
X S X X T
T X S X X
X X X X X
X T X X X
X X T X X

4
S S S T
X X X X
X X X X
T T T X

5
X X S X X
X X X X X
S X T X S
X X X X X
X X S X X

5
X T X T X
T X S X T
X S S S X
T X S X X
X T X X X
*/
