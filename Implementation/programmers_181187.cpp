/* //처음 시도한 풀이 (4개 테케 시간초과)
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double distance(int x, int y){ //0,0부터 x,y까지의 거리
    double dist = sqrt(x*x + y*y);
    return dist;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    vector<vector<int>> map(r2, vector<int>(r2, 0));
    int i,j;
    int count=0;
    
    for(i=1;i<=r2;i++){
        for(j=0;j<=r2;j++){
            double dist = distance(i,j);
            if(dist <=r2 && dist >=r1){
                count++;
                //printf("dist: %f x,y: %d %d\n",dist,i,j);
            }
        }
    }
    
    answer = count*4;
    return answer;
}
*/  

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    int big,small;

    for(int i=1;i<r2;i++){
        //큰 원(내림) - 작은 원(올림)이 세로축 점의 개수
        //x^2 + y^2 = a^ -> y = sqrt(pow(a,2) - pow(x, 2))
        // y값 = sqrt(pow(r2,2) - pow(i,2));
        
        big = (int)floor(sqrt(pow(r2,2)-pow(i,2)));
        if(i<r1){
            small = (int)ceil(sqrt(pow(r1,2)-pow(i,2)));
        }
        else{
            small = 1; //j가 0일 경우는 빼고 계산해야 함
        }        
        answer += big - small + 1;        
    }
    
    answer += (r2-r1+1);
    answer *=4;
    
    return answer;
}
