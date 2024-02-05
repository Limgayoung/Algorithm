package com.day2.perm;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;


public class sweq {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M;     
    static Stack<Character> s = new Stack<>();

    public static void main(String[] args) throws Exception {
    	
    	N = Integer.parseInt(br.readLine());
    	String str = br.readLine();
    	int answer = 0;
    	for(int i=0;i<str.length();i++) {
    		answer = Math.max(s.size(), answer);
    		if(s.empty() || s.peek() == str.charAt(i)) {
    			s.add(str.charAt(i));
    		}
    		else {
    			s.pop();
    		}
    	}
    	
    	if(s.empty()) bw.write(answer+"\n");
    	else bw.write("-1");
    	

    	bw.close();
    }             
    

    
}

/*

*/
