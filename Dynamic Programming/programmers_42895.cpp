#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> dp[9]; //1~8까지의 연산으로 만들 수 있는수

int solution(int N, int number) {
    int answer = -1;
    
    //N을 이어붙인 수 dp에 먼저 넣어주기
    int num = 0;
    for(int i=1;i<9;i++){
        num*=10;
        num+=N;
        dp[i].insert(num);
    }
    
    //각 i번째 연산으로 만들 수 있는 수 초기화
    //1~i-1까지 숫자에 사칙연산으로 추가    
    for(int i=2;i<9;i++){ //1번째 수는 이미 완성됨 (N 한개)
        for(int j=1;j<i;j++){ //연산으로 만들어진 수들을 각각 사칙연산 하면 됨 
            //ex) i가 5일 경우 j: 2면 j:3인 수와 연산 -> dp[5]인 수 완성
            for(int a:dp[j]){ //이전 연산
                for(int b:dp[i-j]){
                    dp[i].insert(a+b);
                    dp[i].insert(a*b);
                    if(a/b >0)
                        dp[i].insert(a/b);
                    if(a-b >0)
                        dp[i].insert(a-b);
                }
            }
        }
    }
    
    //number 랑 같은 수 찾기
    for(int i=1;i<=8;i++){
        for(int a:dp[i]){
            if(a==number) return i;
        }
    }
    
    
    return answer;
}
