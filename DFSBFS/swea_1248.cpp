#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

int V,E,s1,s2;
int parent[10001];
vector<int> G[10001];
int answer;

int findLevel(int a, int level){ //레벨 확인
    if(parent[a] == 0) return level;
    else return findLevel(parent[a], level+1);
}

int findSameParent(int a, int b){ //공통 조상 찾기
    //1. 각각의 레벨 확인    
    int levelA = findLevel(a, 1);
    int levelB = findLevel(b, 1);

    //2. 둘의 레벨 같게 맞춰주기 (레벨이 같은거보다 높은 곳이 조상)
    //항상 a가 b보다 level이 작게
    if(levelA > levelB){ //a,b 바꾸기
        int t = a;
        a = b;
        b = t;        
        t = levelA;
        levelA = levelB;
        levelB = t;
    }
    int parentA = a;
    int parentB = b;
    while(levelA != levelB){
        parentB = parent[b];
        b = parentB;
        levelB--;
    }
    
    //같이 레벨 올리면서 공동 조상 찾기
    while(parentA != parentB){
        parentA = parent[a];
        parentB = parent[b];
        a = parentA;
        b = parentB;
        //printf("parentA: %d parentB: %d\n",parentA, parentB);
    }    
    
    return parentA;
}

void dfs(int a){
    answer++;
    for(int i=0;i<G[a].size();i++){
        dfs(G[a][i]);
    }
}

void calServeTree(int r){
    dfs(r);    
}

void printParent(){
    for(int i=1;i<=V;i++){
        printf("%d의 부모: %d\n", i, parent[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{        
        int a,b;
        answer = 0;
        cin >> V >> E >> s1 >> s2;
        fill(&parent[0], &parent[10000], 0);
        fill(&G[0], &G[10000], vector<int>());
		for(int i=0;i<E;i++){
            cin >> a >> b; //부모 자식
            G[a].push_back(b);
            parent[b] = a;
        }
        int sameParent = findSameParent(s1,s2);
        calServeTree(sameParent);
        
        printf("#%d %d %d\n",test_case, sameParent, answer);
	}
	return 0;
}
