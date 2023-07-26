#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int jocker=0;
    int correct = 0;
    int minRank=6, maxRank=6;
    int rank[6] = {-1,6,5,4,3,2};
    int i;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int j=0;
    for(i=0;i<6;i++){
        if(j>5) break;
        if(lottos[i] == 0){
            jocker++;
        }
        else if(lottos[i] == win_nums[j]){
            correct++;
            j++;
            continue;
        }
        else if(lottos[i] < win_nums[j]){
            continue;
        }
        else{
            j++;
            i--;
            continue;
        }
    }
    
    for(i=1;i<=5;i++){
        if(correct+jocker == rank[i]){
            maxRank = i;
        }
        if(correct == rank[i]){
            minRank = i;
        }
    }
    answer.push_back(maxRank);
    answer.push_back(minRank);
    return answer;
}
