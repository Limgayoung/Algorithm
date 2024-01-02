#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int visit[102] = {0};

void dfs(int n, vector<vector<int>> g){
    visit[n] = 1;
    
    for(int i=0;i<g[n].size();i++){
        int nextNode = g[n][i];
     	if(visit[nextNode] == 0){
         	dfs(nextNode, g);   
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N,M;
    int a,b;
    int answer;
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d %d",&N,&M);
        vector<vector<int>> g(N+1);
        fill(visit, visit+101,0);
        answer = 0;
        
        for(int i=0;i<M;i++){
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        for(int i=1;i<=N;i++){
            if(visit[i] == 0){
             	dfs(i,g);
                answer++;
            }
        }
        
        printf("#%d %d\n",test_case, answer);
	}
	return 0;
}
