#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> parent(101);

bool compareVector(vector<int> a, vector<int> b){
    if(a[2] == b[2]){
        return a[0] < b[0];        
    }
    return a[2] < b[2];
}

int findParent(int a){
    if(parent[a] == a) return a;
    else return findParent(parent[a]);
}

bool isSameParent(int a,int b){
    if(findParent(a) == findParent(b)) return true;
    else return false;
}

void makeUnion(int a, int b){
    int parentA, parentB;
    parentA = findParent(a);
    parentB = findParent(b);    
    
    if(parentA < parentB){
        parent[parentB] = parentA;
    }
    else{
        parent[parentA] = parentB;
    }
}

void printParent(int n){
    printf("parent print\n");
    for(int i=0;i<n;i++){
        printf("i: %d parent: %d\n",i,parent[i]);
    }
    printf("\n\n");
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), compareVector);
    
    for(int i=0;i<n;i++){ //처음에는 자기 자신이 부모
        parent[i] = i;
    }
    
    for(vector<int> cost:costs){
        int a = cost[0];
        int b = cost[1];
        int c = cost[2]; 
        
        if(!isSameParent(a,b)){ //같은 그룹으로 만들어 줘야 함
            //printf("makeUnion %d %d cost: %d\n",a,b,c);
            makeUnion(a,b);
            answer+=c;
            //printParent(n);
        }
    }
 
    return answer;
}
