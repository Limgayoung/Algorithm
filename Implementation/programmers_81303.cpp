#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct node{
    int next;
    int prev;    
    int num;
    bool isDeleted;
}node;

node table[1000005];
string answer = "";
stack<int> deletedNode;

void makeTable(int n){
    table[0].next = 1;
    table[0].prev = -1;
    table[0].num = 0;
    table[0].isDeleted = false;
    for(int i=1;i<n-1;i++){
        table[i].next = i+1;
        table[i].prev = i-1;
        table[i].num = i;
        table[i].isDeleted = false;
    }
    table[n-1].prev = n-2;
    table[n-1].next = -1;
    table[n-1].num = n-1;
    table[n-1].isDeleted = false;
}

int deleteNode(int nowNode){
    deletedNode.push(nowNode);
    
    int next = table[nowNode].next;
    int prev = table[nowNode].prev;
    
    int newNowNode;    
    if(prev != -1){ //맨 앞이 아닐 경우
        table[prev].next = next;
    }
    if(next != -1){ //맨 뒤가 아닐 경우
        table[next].prev = prev;
        newNowNode = next;
    }
    if(next == -1){ //맨 뒤일 경우
        newNowNode = prev;        
    }
        
    table[nowNode].isDeleted = true;
    return newNowNode;
}

void insertNode(){
    int num = deletedNode.top();
    deletedNode.pop();
    table[num].isDeleted = false;
    
    int prev = table[num].prev;
    int next = table[num].next;
    
    if(prev != -1){ //맨 앞 삽입 아닐때
        table[prev].next = num;
    }
    if(next != -1){ //맨 뒤 삽입 아닐때
        table[next].prev = num;                
    }
}

int runCmd(string cmd, int nowNode){
    char c = cmd[0];
    if(c == 'U'){
        // int num = cmd[2] - '0';     
        int num = stoi(cmd.substr(2));
        for(int i=0;i<num;i++){
            nowNode = table[nowNode].prev;
        }        
    }
    else if(c == 'D'){
        //int num = cmd[2] - '0';
        int num = stoi(cmd.substr(2));
        for(int i=0;i<num;i++){
            nowNode = table[nowNode].next;
        }          
    }
    else if(c == 'C'){ //delete
        nowNode = deleteNode(nowNode);        
    }
    else if(c == 'Z'){ //insert
        insertNode();
    }
    return nowNode;
}

string solution(int n, int k, vector<string> cmd) {
    
    makeTable(n);
    
    //nowNode 이동
    int nowNode = k;
    //cmd 실행    
    for(string s:cmd){
        nowNode = runCmd(s, nowNode);
    }
    
    for(int i=0;i<n;i++){
        if(table[i].isDeleted == 1){
            answer+="X";
        }
        else answer+="O";
    }
    
    return answer;
}
