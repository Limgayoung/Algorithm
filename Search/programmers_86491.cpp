#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxWidth, maxHeight;
    maxWidth=maxHeight=0;
    for(vector<int> size:sizes){ 
        //1. 가로 > 세로 하도록 변경
        int ga = size[0];
        int se = size[1];
        
        if(ga < se){
            size[0] = se;
            size[1] = ga;
        }
        //max 값 판단
        if(maxWidth < size[0]){
            maxWidth = size[0];
        }
        if(maxHeight < size[1]){
            maxHeight = size[1];
        }        
    }
    
    answer = maxWidth * maxHeight;
    
    return answer;
}
