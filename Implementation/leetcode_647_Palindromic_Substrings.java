/*
앞뒤 똑같으면 펠린드롬
펠린드롬인 부분 문자열 개수 찾기.
N<=1000 -> 완탐 가능
*/

class Solution {

    List<String> subStrings = new ArrayList<>();
    int length;

    public void makeSubStrings(String s){
        
        for(int i=1;i<=length;i++){ //부분 문자열 길이
            for(int j=0;j<length;j++){ //시작점
                if(j+i>length) break;
                String subStr = s.substring(j, j+i);
                subStrings.add(subStr);
            }
        }
    }

    public boolean isPalindrome(String s){
        int l = s.length();

        for(int i=0;i<l;i++){
            if(s.charAt(i) != s.charAt(l-1-i)) return false;
        }
        return true;
    }
    
    public int countSubstrings(String s) {
        int answer = 0;
        length = s.length();

        makeSubStrings(s);
        for(int i=0;i<subStrings.size();i++){
            if(isPalindrome(subStrings.get(i))){
                answer++;
            }
        }

        return answer;
    }
}
