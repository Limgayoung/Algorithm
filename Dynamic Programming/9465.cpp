#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        scanf("%d",&N);
        vector<vector<int>> sticker(2, vector<int>(N)); 
        //dp : 현재 위치에서 가장 큰 값
        vector<vector<int>> dp(2, vector<int> (N, 0));

        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&sticker[i][j]);
            }
        }
        
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        if(N == 1) {            
            printf("%d\n",max(dp[0][0], dp[1][0]));
            continue;
        }
        dp[0][1] = dp[1][0]+sticker[0][1];
        dp[1][1] = dp[0][0]+sticker[1][1];
        
        for(int i=2;i<N;i++){  
            //위 : 전아래+현재위  전전위+현재위  전전아래+현재위
            //아래 : 전위+현재아래  전전위+현재아래  전전아래+현재아래
            //위
            int beforeMax = max(dp[0][i-2]+sticker[0][i], dp[1][i-2]+sticker[0][i]);
            dp[0][i] = max(dp[1][i-1]+sticker[0][i], beforeMax);

            //아래
            beforeMax = max(dp[1][i-2]+sticker[1][i], dp[0][i-2]+sticker[1][i]);
            dp[1][i] = max(dp[0][i-1]+sticker[1][i], beforeMax);

        }
        
        printf("%d\n",max(dp[0][N-1], dp[1][N-1]));                
	}
	return 0;
}
