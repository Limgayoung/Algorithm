#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fact[250001];

int main(int argc, char** argv)
{
    int T;
    int N;
    long long prime;
    
    int index = 2;
    int beforePrime = 0;
	long long answer;
    scanf("%d",&T);    
    
    fact[1] = 1;
    
    for(int test_case=1;test_case<=T;test_case++){        
        answer = 0;        
        scanf("%d %lld",&N, &prime);
        
        if(prime != beforePrime) index = 2;
        
        for(int i=index;i<=N;i++){
            fact[i] = (fact[i-1]*i)%prime;
        }
        
        answer += (N*fact[N]);
        for(int i=1;i<N;i++){
            answer += ((((N-i)*fact[N-i])%prime) * fact[i+1]);
            answer %= prime;
        }

        printf("#%d %lld\n",test_case, answer);
        beforePrime = prime;
    }
    
	return 0;
}
