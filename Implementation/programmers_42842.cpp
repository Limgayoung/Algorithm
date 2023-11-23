#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> combi; //x,y 될 수 있는 조합
    
    int area = brown + yellow;
    int length = brown + 4; //사각형 둘레 (가로 + 세로)*2
    
    for(int i=1;i<=area;i++){
        if(area % i == 0){
            int y = i; //세로
            int x = area/i; //가로
            if(x<y) break;
            combi.push_back({x,y});
        }
    }
    
    for(pair<int,int> p:combi){
        int x = p.first;
        int y = p.second;
        
        if((x+y) * 2 == length){
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
    
    return answer;
}
