#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
n,coin < 1000
처음에 카드 n/3장 뽑기
1. 카드 두 장 뽑기 (남은 카드 없으면 게임 종료)
2. 카드 한 장 동전 하나 써서 가지기 / 동전 안쓰고 버리기
3. 카드에 적힌 수의 합이 n+1 되도록 두 장 내고 다음 라운드 (못 내면 종료)

1. 각 카드의 라운드 저장
2. 각 카드의 상대 숫자 저장 (n+1이 13, 카드가 3이면 상대 숫자는 10)
3. 라운드 돌기
*/

int N;
vector<int> otherNums; //각 카드의 상대 숫자
vector<int> numRounds; //각 카드의 라운드
vector<int> numIndex; //숫자 위치
vector<int> nums;
vector<bool> visit; //사용 여부

void initNumIndex(){
    numIndex = vector<int>(N+1);
    for(int i=0;i<N;i++){
        numIndex[nums[i]] = i;
    }
}

void initOtherNums(){
    otherNums = vector<int>(N+1);
    for(int i=0;i<N;i++){
        otherNums[i] = (N+1)-nums[i];
    }
}

void initNumRounds(){
    numRounds = vector<int>(N);
    for(int i=0;i<N/3;i++){
        numRounds[i] = 0;
    }
    
    int i=N/3;
    int j=0;
    int round = 1;    
    while(i<N){
        numRounds[i] = round;
        i++;
        j++;
        if((j)%2 == 0){
            round++;
        }
    }
}

void printVector(vector<int> vec){
    for(int v:vec){
        printf("%d ",v);
    }
    printf("\n");
}

//지금꺼 살지 말지
    //coin 1개 필요 -> 바로 queue에 넣기
    //coin 2개 필요 -> 일단 보류 queue(우선순위큐)에 넣기
//이를 queue가 비기 전까지 반복 (최대한 채워놓기)
//queue가 비면 보류 queue의 맨 앞꺼 pop, coin -= 2 (다음 라운드 간 것)
//반복
int playGame(int coin){
    queue<int> q; //바로 사용 가능
    queue<int> waitQ; //보류 큐
    
    //0라운드, 바로 사용 가능함    
    for(int i=0;i<N/3;i++){
        int otherNum = otherNums[i];
        if(numRounds[numIndex[otherNum]] == 0 && !visit[otherNum]){
            q.push(nums[i]);
            visit[nums[i]] = true;
            visit[otherNum] = true;
        }
    }
    
    //게임 시작
    int nowRound = 1;
    int i=N/3; //card index
    while(i<N){
        int nowCard = nums[i];
        int otherNum = otherNums[i];
   
        //1원으로 살 수 있음
        if(numRounds[numIndex[otherNum]] == 0 && !visit[otherNum] && coin>0){ 
            q.push(nums[i]);
            visit[nums[i]] = true;
            visit[otherNum] = true;
            coin--;
        }
        //2원으로 살 수 있음
        else if(numRounds[numIndex[otherNum]] <= nowRound && !visit[otherNum]){ 
            waitQ.push(nums[i]);
            visit[nums[i]] = true;
            visit[otherNum] = true;            
        }
        

        i++;
        if((i-N/3)%2 == 0){ //라운드 종료
            //waitQueue에 있는 것 하나를 queue로 옮겨야 함
            if(q.empty()){
                if(!waitQ.empty() && coin>1) {
                    int n = waitQ.front();
                    waitQ.pop();
                    q.push(n);
                    coin -= 2;   
                }
            }
            if(q.empty()) break;
            q.pop();
            nowRound++;  
        } 
    }
    
    return nowRound;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    N = cards.size();
    nums = cards;
    initNumIndex();
    initOtherNums();
    initNumRounds();
    visit = vector<bool>(N+1, false);
    answer = playGame(coin);
    return answer;
}
