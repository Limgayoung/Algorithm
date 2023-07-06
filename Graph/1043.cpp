#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> partyPeople[50];
vector<int> truthPeople;
int parent[51]; //N들의 parent, 0이면 진실

int changeParent(int index) { //party에 참여한 사람들의 parent 0으로 변경
    int i;
    int flag = 0;
    for (i = 0; i < partyPeople[index].size(); i++) {
        if (parent[partyPeople[index][i]] != 0) {
            parent[partyPeople[index][i]] = 0;
            flag = 1;
        }
    }
    return flag;
}

int renewParent() {
    int flag = 0;
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < partyPeople[i].size(); j++) {
            if (parent[partyPeople[i][j]] == 0) { //party에 참여한 사람들 중 parent가 0인 사람이 있다면 changeParent 해주기
                if(changeParent(i) == 1)
                    flag = 1;
                break;
            }
        }
    }

    return flag; //flag 1이면 갱신된 것
}

int checkParty() {
    int i;
    int count = 0;

    for (i = 0; i < M; i++) {
        if (parent[partyPeople[i].front()] != 0) {
            count++;
        }
    }

    return count;
}

int main() {  
    int tNum;
    int i, j, t, num;
    int pa;

    scanf("%d %d", &N, &M);

    scanf("%d", &tNum);
    for (i = 0; i < tNum; i++) {
        scanf("%d", &t);
        truthPeople.push_back(t);
    }

    //party
    for (i = 0; i < M; i++) {
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &t);         
            if (j == 0) { //맨 앞일 경우
                pa = t;
            }
            parent[t] = pa;
            partyPeople[i].push_back(t);
        }
    }
    for (i = 0; i < truthPeople.size(); i++) {
        parent[truthPeople[i]] = 0;
    }

    //truth people 갱신
    while (1) {
        if (renewParent() == 0) {
            break;
        }
    }

    printf("%d", checkParty());

    return 0;
}
