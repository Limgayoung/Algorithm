#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v){
    for(int i:v){
        printf("%d ",i);
    }
    printf("\n");
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command:commands){
        int start = command[0]-1;
        int end = command[1];
        int index = command[2]-1;
        vector<int> newArray(&(array[start]), &(array[end]));
        sort(newArray.begin(), newArray.end());
        //printVector(newArray);
        answer.push_back(newArray[index]);
    }
    
    return answer;
}
