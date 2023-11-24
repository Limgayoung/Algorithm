#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int isVisit[31][31] = {0};

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<queue<int>> map(board.size());
    stack<int> doll;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){            
            if(board[i][j] != 0){
                map[j].push(board[i][j]);
            }
        }
    }
    
    for(int move:moves){
        move--;
        if(map[move].empty()) continue;
        
        int newDoll = map[move].front();
        map[move].pop();
        int topDoll;
        
        if(doll.empty()){
            doll.push(newDoll);
            topDoll = -1;
        }
        else{
            topDoll = doll.top();
            if(topDoll == newDoll){
                answer+=2;
                doll.pop();
            }
            else doll.push(newDoll);
        }

        //printf("뽑은 인형: %d 맨 위 인형: %d\n",newDoll, topDoll);
        
    }
    return answer;
}
