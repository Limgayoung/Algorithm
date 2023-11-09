#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<pair<int,int>>> genreMap;
map<string, int> genreCount; //각 장르별 전체 재생 횟수

bool compare(pair<int,int> a, pair<int,int> b){ //재생횟수 높은순, 고유번호 낮은순
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool compareStringPair(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

void initMap(vector<string> genres, vector<int> plays){    
    for(int i=0;i<genres.size();i++){
        if(genreMap.count(genres[i]) == 0){ //처음 넣는것
            vector<pair<int,int>> v;
            v.push_back({plays[i], i});
            genreMap.insert({genres[i], v});
            genreCount.insert({genres[i], plays[i]});
        }
        else{
            genreMap[genres[i]].push_back({plays[i],i});
            genreCount[genres[i]]+=plays[i];
        }        
    }
}

void printMap(){
        for(auto iter:genreMap){
            for(int i=0;i<iter.second.size();i++){
                cout<<"재생횟수: "<<iter.second[i].first<<" 고유번호: "<<iter.second[i].second<<endl;
            }
    }
    cout<<endl;
}

void sortMap(){
    for(auto iter:genreMap){
        vector<pair<int,int>> v(iter.second.begin(), iter.second.end());
        sort(v.begin(), v.end(), compare);
        genreMap[iter.first] = v;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    initMap(genres, plays);
    // printMap();
    sortMap();
    // printMap();
    vector<pair<string,int>> genreCountList(genreCount.begin(), genreCount.end());
    sort(genreCountList.begin(), genreCountList.end(), compareStringPair);
    
    for(int i=0;i<genreCountList.size();i++){
        int flag = 0;
        string genreName = genreCountList[i].first;
        vector<pair<int,int>> playList(genreMap[genreName].begin(), genreMap[genreName].end());
        for(int j=0;j<playList.size();j++){
            if(flag >=2) break;
            answer.push_back(playList[j].second);
            flag++;
        }
    }
    
    return answer;
}
