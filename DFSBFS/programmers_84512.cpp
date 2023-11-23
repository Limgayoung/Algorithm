#include <string>
#include <vector>

using namespace std;
char alp[5] = {'A','E','I','O','U'};
int answer = 0;
int cnt = 0;
void dfs(int length, string makeWord, string compareWord){    
    if(makeWord != "") {
        cnt++;    
        //printf("cnt: %d word: %s\n",cnt, makeWord.c_str());
    }
    if(makeWord == compareWord){
        answer = cnt;        
        return;
    }
    if(length >5) return;
    if(answer != 0) return;
        
    for(int i=0;i<5;i++){
        string newWord = makeWord + alp[i];
        if(length+1 <=5){
            dfs(length+1, newWord, compareWord);
        }
    }
}

int solution(string word) {

    dfs(0,"", word);
    return answer;
}
