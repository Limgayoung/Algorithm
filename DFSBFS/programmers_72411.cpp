#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> courseMap;
vector<string> answer;
bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void dfs(string order, string course, int n, int index){
    if(course.length() == n){
        courseMap[course]++;
        return;
    }
    for(int i=index;i<order.length();i++){
        dfs(order, course+order[i], n, i+1);
    }
}

void findCourse(vector<string> orders, vector<int> courseNum){
    //각 주문별 조합 찾기
    for(int num:courseNum){
        for(string s:orders){
            sort(s.begin(), s.end());
            dfs(s, "", num, 0);
        }
        vector<pair<string, int>> courseList (courseMap.begin(), courseMap.end());
        sort(courseList.begin(), courseList.end(), compare);
        
        int maxCnt = courseList[0].second;
        for(pair<string, int> p:courseList){
            if(p.second < 2) break;
            if(p.second == maxCnt){
                answer.push_back(p.first);
            }
        }
        courseMap.clear();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {   
    //조합 찾기
    findCourse(orders, course);

    //answer 사전 순으로 오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}
