/*
//그리디 풀이
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int i,j;
    int seSize = sequence.size();
    int start, end;
    int length = seSize+1;
    int sum;
    
    for(i=0;i<seSize;i++){
        start = i;
        sum = 0;
        for(j=i;j<seSize;j++){
            sum+=sequence[j];
            if(sum == k){
                end = j;
                printf("start: %d end: %d\n",start, end);
                if(end - start < length) {
                    answer[0] = start;
                    answer[1] = end;
                    length = end-start;
                }
                printf("length: %d\n",length);
                break;
            }
        }
    }
    return answer;
}
*/  

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int i,j;
    int seSize = sequence.size();
    int start, end;
    int length = seSize+1;
    int sum;
    
    for(i=0;i<seSize;i++){
        start = i;
        sum = 0;
        for(j=i;j<seSize;j++){
            sum+=sequence[j];
            if(sum == k){
                end = j;
                printf("start: %d end: %d\n",start, end);
                if(end - start < length) {
                    answer[0] = start;
                    answer[1] = end;
                    length = end-start;
                }
                printf("length: %d\n",length);
                break;
            }
        }
    }
    return answer;
}
