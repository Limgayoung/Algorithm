#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int indexA, indexB;
    indexA = indexB = A.size()-1;
    
    while(1){
        if(indexA < 0 || indexB < 0) break;
        if(A[indexA] < B[indexB]){ //승점
            answer++;
            indexA--;
            indexB--;
        }
        else if(A[indexA] > B[indexB]){
            indexA--;
        }
        else if(A[indexA] == B[indexB]){
            indexA--;            
        }
    }
    
    return answer;
}
