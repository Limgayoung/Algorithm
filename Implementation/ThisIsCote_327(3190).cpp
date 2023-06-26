#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, K, L;
int map[101][101]; //사과 있으면 2, 뱀 있으면 1, 아무것도 없으면 0
int direction[101][2]; //뱀 방향 (시간, 방향) 왼쪽 0, 오른쪽 1
// → ↓ ← ↑ 방향
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int nowDir = 0; //처음에 오른쪽 방향부터 시작
int nowTime = 0; //현재 시간

queue<pair<int,int>> snakeQueue; //뱀 꼬리 위치 저장하는 queue

int main() {
    int i, j;
    int x=1, y=1; //뱀의 현재 위치
    int di=0; //direction index

    scanf("%d", &N);
    //사과 위치 입력받기 -> map에 2로 저장하기
    scanf("%d", &K);    
    for (i = 0; i < K; i++) { 
        int a, b;
        scanf("%d %d", &a,&b);
        map[b][a] = 2;
    }
    //뱀 방향 입력받기
    scanf("%d", &L);
    for (i = 0; i < L; i++) {
        char dir;
        scanf("%d %c", &direction[i][0], &dir);
        if (dir == 'L') direction[i][1] = 0;
        else direction[i][1] = 1;
    }    

    //뱀 이동
    snakeQueue.push(make_pair(1, 1));

    while (1) {

        nowTime++;

        //이동
        x = x + dx[nowDir];
        y = y + dy[nowDir];
        snakeQueue.push(make_pair(x, y));

        //사과 확인
        if (map[x][y] == 2) { //사과 있음
            map[x][y] = 1;
        }
        else { //사과 없음
            if (map[x][y] == 1) { //머리, 꼬리 닿음
                break;
            }
            else {
                map[x][y] = 1;
            }
            map[snakeQueue.front().first][snakeQueue.front().second] = 0;
            snakeQueue.pop();
        }

        //회전 여부 체크
        if (nowTime == direction[di][0] && di < L) { //회전해주기
            if (direction[di][1] == 0) { //왼쪽 회전
                nowDir--;
                if (nowDir == -1) nowDir = 3;
            }
            else { //오른쪽 회전
                nowDir++;
                if (nowDir == 4) nowDir = 0;
            }
            di++;
        }

        //map 벗어나는지 확인
        if (x > N || x < 1 || y > N || y < 1) {
            break;
        }
    }

    printf("%d", nowTime);

    return 0;
}

/*
6 
3 
3 4 
2 5 
5 3 
3 
3 D 
15 L 
17 D

10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L

10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L

*/
