#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n+1,1);    

    for(int l:lost){
        student[l]--;
    }
    
    for(int r:reserve){
        student[r]++;
    }
    
    for(int i=1;i<=n;i++){ //앞뒤로 주고받을 수 있음
        if(i-1 >= 1 && student[i-1] < 1){ //전사람이 도난당함
            if(student[i] > 1){ //빌려줄 수 있음
                student[i-1]++;
                student[i]--;
            }            
        }
        else if(i+1<n+1 && student[i+1]<1){ //뒷사람이 도난당함
            if(student[i]>1){
                student[i+1]++;
                student[i]--;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(student[i] >0) answer++;
    }
    
    return answer;
}
