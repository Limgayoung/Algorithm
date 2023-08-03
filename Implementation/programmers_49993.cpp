#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char,char> skillMap; //스킬, 선행스킬

int isAvailableSkillTree(string skillTree){
    int isLearn[26]; //A~Z 배움 여부
    fill(&isLearn[0], &isLearn[25], 0);
    
    for(int i=0;i<skillTree.size();i++){
        char nowSkill = skillTree[i];
        //printf("nowSkill: %c\n",nowSkill);
        if(skillMap.count(nowSkill) == 1){ //선행스킬 존재
            //printf("선행스킬: %c 배움여부: %d\n", skillMap[nowSkill], isLearn[skillMap[nowSkill]-'A']);
            
            if(isLearn[skillMap[nowSkill] - 'A'] == 0){
                return 0;
            }            
        }
        isLearn[nowSkill - 'A'] = 1;
    }                                                                
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=1;i<skill.size();i++){ //맨 처음은 선행스킬 없음
        skillMap.insert({skill[i], skill[i-1]});
    }
    
    for(int i=0;i<skill_trees.size();i++){
        if(isAvailableSkillTree(skill_trees[i]) == 1){
            answer++;
        }
        //printf("\n");
    }
    
    return answer;
}
