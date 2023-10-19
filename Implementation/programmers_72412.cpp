#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<vector<vector<vector<vector<int>>>>> infoMap(3,vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>()))));
//개발언어(cpp, java, python), 직군(backend, frontend), 경력(junior, senior)
//소울푸드(chicken, pizza), 점수(자연수)

map<string, int> lanMap, jobMap, careerMap, foodMap;

void printInfoMap(){
    for(int a=0;a<3;a++){
        for(int b=0;b<2;b++){
            for(int c=0;c<2;c++){
                for(int d=0;d<2;d++){                    
                    for(int e=0;e<infoMap[a][b][c][d].size();e++){
                        printf("a: %d b: %d c: %d d: %d score: %d\n", a,b,c,d, infoMap[a][b][c][d][e]);
                    }
                }
            }
        }
    }
    printf("\n");
}

void initMap(){
    lanMap.insert({"cpp", 0});
    lanMap.insert({"java", 1});
    lanMap.insert({"python", 2});
    lanMap.insert({"-", -1});
    
    jobMap.insert({"backend", 0});
    jobMap.insert({"frontend", 1});
    jobMap.insert({"-", -1});
    
    careerMap.insert({"junior", 0});
    careerMap.insert({"senior", 1});
    careerMap.insert({"-", -1});
    
    foodMap.insert({"chicken", 0});
    foodMap.insert({"pizza", 1});
    foodMap.insert({"-", -1});
}

void initInfoMap(vector<string> info){ //info 내용을 infoMap에 저장
    string word;
    int cnt;
    int a,b,c,d,e; //index
    for(string s:info){
        word="";
        cnt =a=b=c=d=e= 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '|| i == s.length()-1){
                //cout<<"cnt: "<<cnt<<" word: "<<word<<endl;
                if(cnt == 0){ //lan
                    a = lanMap[word];
                }
                else if(cnt == 1){ //job
                    b = jobMap[word];
                }
                else if(cnt == 2){ //career
                    c = careerMap[word];
                }
                else if(cnt == 3){ //food
                    d = foodMap[word];
                }
                else{ //score
                    //printf("%d\n",stoi(word));
                    word+=s[i];
                    infoMap[a][b][c][d].push_back(stoi(word));
                }
                
                word = "";
                cnt++;
            }
            else{
                word+=s[i];
            }
        }
    }
}

int countQueryInfo(string s){
    int a,b,c,d;
    int score;
    string word="";
    int cnt=0;
    for(int i=0;i<s.length();i++){ //query 분석
        if(s[i] == ' '|| i == s.length()-1){    
            if(word.compare("and") == 0){
                word="";
                continue;
            }            
            if(cnt == 0){ //lan
                a = lanMap[word];
            }
            else if(cnt == 1){ //job
                b = jobMap[word];
            }
            else if(cnt == 2){ //career
                c = careerMap[word];
            }
            else if(cnt == 3){ //food
                d = foodMap[word];
            }
            else{ //score
                //printf("%d\n",stoi(word));
                word+=s[i];
                score = stoi(word);
            }        
            word="";
            cnt++;
        }
        else{
            word+=s[i];
        }        
    }
    
    //printf("query score: %d\n",score);

    vector<int> alist,blist,clist,dlist;

    if(a == -1){
        for(int i=0;i<3;i++){
            alist.push_back(i);
        }
    }
    else alist.push_back(a);
    if(b == -1){
        for(int i=0;i<2;i++){
            blist.push_back(i);
        }
    }
    else blist.push_back(b);
    if(c == -1){
        for(int i=0;i<2;i++){
            clist.push_back(i);
        }
    }
    else clist.push_back(c);
    if(d == -1){
        for(int i=0;i<2;i++){
            dlist.push_back(i);
        }
    }
    else dlist.push_back(d);

    int sum=0;
    int ai,bi,ci,di;;
    
    for(int i=0;i<alist.size();i++){
        ai=alist[i];
        for(int j=0;j<blist.size();j++){
            bi=blist[j];
            for(int k=0;k<clist.size();k++){
                ci=clist[k];
                for(int l=0;l<dlist.size();l++){
                    di=dlist[l];
                    for(int o=0;o<infoMap[ai][bi][ci][di].size();o++){
                        //printf("score: %d 비교: %d", score, infoMap[ai][bi][ci][di][o]);
                        if(infoMap[ai][bi][ci][di][o] >= score) {
                            sum++;
                        }
                    }
                }
            }
        }
    }
       
    //printf("sum: %d\n",sum);
    return sum;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    initMap();
    initInfoMap(info);
    //printInfoMap();
    //printf("1번: %d\n", infoMap[1][0][0][1].size());
    
    for(string q:query){
        answer.push_back(countQueryInfo(q));
    }
    
    return answer;
}
