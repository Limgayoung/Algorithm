import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static Node[] G;
    static Stack<Integer> s = new Stack<>();
    static boolean answer;
    
    //char형 그래프
    //left, right 자식 o
    // 자식이 다음 연결리스트 가리킴
    
    static class Node{
    	
    	//n이 -1이면 연산자
    	int n;
    	int left;
    	int right;
    	
		public Node(int n, int left, int right) {
			this.n = n;
			this.left = left;
			this.right = right;
		}    	
    }
    
    static void traversal(int node) {
    	
    	if(!answer) return;
    	if(G[node].left != 0) { //왼쪽 자식 먼저
    		traversal(G[node].left);    		
    	}    	
    	
    	if(G[node].right != 0) { //다음 오른쪽 자식
    		traversal(G[node].right);   
    	}
    	//System.out.print(G[node].n+" ");
    	if(G[node].n == -1) { //연산, 다음 연산을 위해 1개만 제거
    		if(s.size()<2 || s.pop() == -1 || s.peek() == -1) {
    			answer = false;
    			return;
    		}  
    	}
    	else s.add(G[node].n);
    	//System.out.println(node);
    }
    
    
    public static void main(String[] args) throws Exception {
    	//st = new StringTokenizer(br.readLine(), " ");
    	
    	for(int t=1;t<=10;t++) {
    		
    		N = Integer.parseInt(br.readLine());
    		G = new Node[N+1];
    		s.clear();
    		answer = true;
    		//입력받기
    		for(int i=1;i<=N;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			int index = Integer.parseInt(st.nextToken());
    			String node = st.nextToken();

    			int n = -1;    			
    			try {
    				n = Integer.parseInt(node);
    			} catch (Exception e) {
					
				}
    			
    			int left, right;
    			left = right = 0;
    			if(st.hasMoreTokens()) {
    				left = Integer.parseInt(st.nextToken());
    			}
    			if(st.hasMoreTokens()) {
    				right = Integer.parseInt(st.nextToken());
    			}
    			G[i] = new Node(n,left,right);
    		}
    		
    		traversal(1);
    		bw.write("#"+t+" ");
    		if(answer) bw.write(1+"\n");
    		else bw.write(0+"\n");
    		
    	}
    	
    	

        bw.close();
    }             
    
    

    
}

/*
9
1 * 2 3
2 + 4 5
3 - 6 7
4 / 8 9
5 2
6 6
7 4
8 8
9 7

9
1 * 2 3
2 + 4 5
3 - 6 7
4 1 8 9
5 2
6 6
7 4
8 8
9 *

*/
