#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;    
    int dist;    
    int wdist = w*2 + 1;    
    
    int j=0;
    int start, end;
    for(int i=1;i<=n;i++){
        dist = 0;      
        if( j >= stations.size()){ //마지막
            start = n;
            end = n;
            if(i == start) dist = 1;
        }
        else{
            start = stations[j]-w;
            end = stations[j]+w;
        }
        if(i < start){
            dist = start - i;
        }
        
        //계산
        if(dist != 0){
            answer+= (dist/wdist);
            if(dist%wdist!=0) answer++;        
        }
        
        i = end;
        j++;
    }
    
    return answer;
}
