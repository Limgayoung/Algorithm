#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int answer = 0;
set<int> numberSet;

int isPrime(int number){
    vector<int> prime(number+1, 1);
    if(number==0 ||number==1) return 0;
    for(int i=2;i<=sqrt(number);i++){
        if(number%i == 0) return 0;                
    }
    return 1;
}

void dfs(string makeNumbers, string numbers){
    if(makeNumbers != ""){
        numberSet.insert(stoi(makeNumbers));
    }
    
    for(int i=0;i<numbers.size();i++){
        string newNumber = makeNumbers + numbers[i];
        dfs(newNumber, numbers.substr(0,i) + numbers.substr(i+1)); // i번째 뺀 값 넘겨주기
    }
}

int solution(string numbers) {

    dfs("", numbers);
    for(int n:numberSet){
        if(isPrime(n) == 1){
            answer++;
        }
    }
    
    return answer;
}
