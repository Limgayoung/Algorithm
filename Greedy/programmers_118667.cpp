#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1, sum2;
    int index1, index2;
    int queueSize = queue1.size();
    sum1 = sum2 = index1 = index2 = 0;
    
    for(int i=0;i<queueSize;i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    if((sum1+sum2)%2 != 0) return -1;

    //printf("sum1: %d sum2: %d index1: %d index2: %d count: %d\n", sum1, sum2, index1, index2, answer);
    
    while(1) {             
        if(answer > (queueSize*3)) return -1;
        
        if(sum1 > sum2){
            sum1-=queue1[index1];            
            sum2+=queue1[index1];
            queue2.push_back(queue1[index1]);
            index1++;
        }
        else if(sum1 < sum2){
            sum2-=queue2[index2];            
            sum1+=queue2[index2];
            queue1.push_back(queue2[index2]);
            index2++;
        }
        else{
            break;
        }
        answer++;
        //printf("sum1: %d sum2: %d index1: %d index2: %d count: %d\n", sum1, sum2, index1, index2, answer);
    }
    
    return answer;
}
