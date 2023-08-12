using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for(int i=1;i<w;i++){
        long long n = (((double)h*i)/w);
        answer+=n;
    }
    answer *= 2;
    return answer;
}
