#include <string>
#include <vector>
#include <algorithm>

#define MAX_INT 100000

using namespace std;

int dp[201][201]; //alp, cop

int solution(int alp, int cop, vector<vector<int>> problems) {    
    int maxAlp = 0, maxCop = 0;        
    
    //max 찾기
    for(int i=0;i<problems.size();i++){
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);        
    }
    
    if(alp >= maxAlp && cop >= maxCop) return 0;
    
    //둘 중 하나라도 큰 경우 위해
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    
    //dp 초기화
    fill(&dp[0][0], &dp[200][200], MAX_INT);          
    dp[alp][cop] = 0;
        
    int changeAlp, changeCop;
    
    for(int i=alp;i<=maxAlp;i++){
        for(int j=cop;j<=maxCop;j++){
            changeAlp = min(i+1, maxAlp);
            changeCop = min(j+1, maxCop);
            dp[changeAlp][j] = min(dp[changeAlp][j], dp[i][j]+1);
            dp[i][changeCop] = min(dp[i][changeCop], dp[i][j]+1);
            
            //problems
            for(vector<int> problem:problems){
                int needAlp = problem[0];
                int needCop = problem[1];
                int plusAlp = problem[2];
                int plusCop = problem[3];
                int cost = problem[4];
                
                if(i<needAlp || j<needCop) continue;
                changeAlp = min(i+plusAlp, maxAlp);
                changeCop = min(j+plusCop, maxCop);
                dp[changeAlp][changeCop] = min(dp[changeAlp][changeCop],dp[i][j]+cost);
            }
            
        }
    }        

    return dp[maxAlp][maxCop];
}
