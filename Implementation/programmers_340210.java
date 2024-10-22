/*
expressions <= 100
완탐 -> 100 * 10(진법 찾아내기) + 100 * 10(정답 알아내기)
무조건 A +/- B = C
2~9진법 중에 하나.
각각의 진법을 적용해보고 마지막까지 존재하는 진법이 정답들
이때 X의 값이 모든 진법에 동일하게 적용된다면 X를 해당 값으로 대체한게 정답, 다른 답이 나온다면 ?

0. init
- expressions에서 완전한 수식과 정답을 알아내야 하는 수식을 각각의 list에 넣어야 한다.

1. N진법을 수식에 적용했을 때 결과 반환하는 메서드
2. X의 결과 반환하는 메서드
*/
import java.util.*;

class Solution {
    
    List<String> fullExpressions;
    List<String> xExpressions;
    boolean[] nArr = new boolean[10]; //n진법 가능한지
    List<Integer> availN = new ArrayList<>(); //가능한 진법
    
    public void makeNArrFalse(int n){
        int third = 0;        
        int first = n%10;
        n/=10;
        int second = n%10;
        if(n>100){
            n/=10;
            third = n%10;
        }
        int num = first;
        num = Math.max(num, second);
        num = Math.max(num, third);
        for(int i=num;i>=2;i--){            
            nArr[i] = false;
        }
    }
    
    public void init(String[] expressions){
        fullExpressions = new ArrayList<>();
        xExpressions = new ArrayList<>();
        Arrays.fill(nArr, true);
        for(String expression:expressions){
            String[] splits = expression.split(" ");
            
            makeNArrFalse(Integer.parseInt(splits[0]));
            makeNArrFalse(Integer.parseInt(splits[2]));
            if(!splits[4].equals("X")){
                makeNArrFalse(Integer.parseInt(splits[4]));    
            }
            
            if(splits[4].equals("X")){                
                xExpressions.add(expression);
            }
            else{
                fullExpressions.add(expression);
            }
        }
    }
    
    //n진법을 10진법으로 변환
    public int makeNToTen(int n, int num){
        //2자리수가 최대. 10의자리는 *n 하고 1의자리는 그냥 해서 새로운 수 만들기
        int result = 0;
        
        result += num%10;
        result += (num/10)*n;
        
        return result;
    }    
    
    public int makeTenToN(int n, int num){
        int result = 0;
        int i = 1;
        while(num>0){
            result += i*(num%n);
            num/=n;
            i*=10;
        }

        // result += 10*(num/n);
        // result += num%n;
        return result;        
    }
    
    //수식이 n진법을 사용했을 때 만들 수 있는지 확인
    public boolean canMake(String expression, int n){
        //2자리수가 최대. 10의자리는 *num 하고 1의자리는 그냥 해서 새로운 수 만들기
        // expression의 수식대로 계산해서 answer가 나오면 true
        String[] splits = expression.split(" ");
        int first = makeNToTen(n, Integer.parseInt(splits[0]));
        int second = makeNToTen(n, Integer.parseInt(splits[2]));
        int result = Integer.parseInt(splits[4]);
        // int result = makeNToTen(n, Integer.parseInt(splits[4]));
        //System.out.println("======expression: "+expression+" n: "+n+" =======");
        //System.out.println("first: "+first+" second: "+second+" result: "+result+" makeTenToN: "+makeTenToN(n,first+second));
        if(splits[1].equals("+")){
            if(makeTenToN(n,first+second) != result) return false;
        } else{ //-
            if(makeTenToN(n,first-second) != result) return false;
        }
        return true;
    }
    
    public int makeResult(String expression, int n){
        String[] splits = expression.split(" ");
        int first = makeNToTen(n, Integer.parseInt(splits[0]));
        int second = makeNToTen(n, Integer.parseInt(splits[2]));
        int result;
        if(splits[1].equals("+")){
            result = first+second;
        } else{ //-
            result = first-second;
        }
        return makeTenToN(n,result);
    }
    
    public String makeAnswer(String expression, int n){
        String[] splits = expression.split(" ");
        String result = splits[0]+" "+splits[1]+" "+splits[2]+" "+splits[3]+" ";
        if(n<0) result += "?";
        else result += n;
        return result;
    }
    
    public String[] solution(String[] expressions) {
        String[] answer;
        init(expressions);
        answer = new String[xExpressions.size()];
        
        for(String expression:fullExpressions){
            for(int i=2;i<=9;i++){
                if(!nArr[i]) continue;
                if(!canMake(expression, i)){
                    nArr[i] = false;
                }
            }            
        }
        
        for(int i=2;i<=9;i++){
            if(nArr[i]){
                availN.add(i);
                //System.out.println("진법: "+i);
            }
        }
        
        //답 구하기
        int j=0;
        for(String expression:xExpressions){
            int ans = makeResult(expression, availN.get(0));
            boolean flag = true;
            for(int i=1;i<availN.size();i++){
                int nowAns = makeResult(expression, availN.get(i));
                //System.out.println("ans: "+ans+" nowAns: "+nowAns);
                if(ans != nowAns){
                    flag = false;
                    break;
                }
            }
            if(flag){                
                answer[j] = makeAnswer(expression, ans);
            }
            else{
                answer[j] = makeAnswer(expression,-1);
            }
            j++;
        }
        
        return answer;
    }
}
