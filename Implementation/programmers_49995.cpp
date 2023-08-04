#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int cookieSize = cookie.size();
    int leftSum, rightSum;
    int l,r;
        
    //범위 내에서 l은 --, r은 ++만 함
    for(int i=0;i<cookieSize-1;i++){ //i가 m                
        l = i;
        r = i+1;        

        leftSum = cookie[l];
        rightSum = cookie[r];
        
        while(l >= 0 && r < cookieSize){                                    
            if(leftSum == rightSum){
                answer = max(answer, leftSum);   
                if(l-1 >= 0){
                    l--;
                    leftSum += cookie[l];
                }
                else if(r+1 <= cookieSize){
                    r++;
                    rightSum += cookie[r];
                }
                else break;
            }
            else if(leftSum < rightSum){
                if(l-1 < 0) break;
                l--;
                leftSum += cookie[l];
            }
            else if(leftSum > rightSum){
                if(r+1 >= cookieSize) break;
                r++;
                rightSum += cookie[r];
            }
        }
    }
        
    return answer;
}
