#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int arr[12];
int oper[4]; //+ - * /
int resultMax = -1000000001;
int resultMin = 1000000001;

void dfs(int result, int index) { //현재 연산 결과, arr index

    int i;

    if (index == N) { //종료 조건
        if (resultMin > result) resultMin = result;
        if (resultMax < result) resultMax = result;
        return;
    }

    for (i = 0; i < 4; i++) { //연산자 4개에 대해 dfs 수행 //+-*/
        if (oper[i] > 0) {
            oper[i]--;
            if (i == 0) { // +
                dfs(result + arr[index], index + 1);
            }
            else if (i == 1) { // -
                dfs(result - arr[index], index + 1);
            }
            else if (i == 2) { // *
                dfs(result * arr[index], index + 1);
            }
            else { // /
                dfs(result / arr[index], index + 1);
            }
            oper[i]++;
        }        
    }

}


int main() {  
    int i, j;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 4; i++) {
        scanf("%d", &oper[i]);
    }

    dfs(arr[0], 1);

    printf("%d\n%d", resultMax, resultMin);


    return 0;
}

/*
2 
5 6 
0 0 1 0

3 
3 4 5 
1 0 1 0

6 
1 2 3 4 5 6 
2 1 1 1

*/
