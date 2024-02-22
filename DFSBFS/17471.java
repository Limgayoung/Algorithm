package com.day16;
import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

import javax.print.StreamPrintService;

/**
 * 
 */

public class Code {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[] peopleNum; //각 구역의 인구수
    static boolean[] visit, subset;
    static ArrayList<Integer> G[];
    static int totalNum = 0;
    static int minDiff = 1000000;
    
    public static void printNowSet() {
    	for(int i=1;i<=N;i++) {
    		if(subset[i]) {
    			System.out.print(i+" ");
    		}
    	}
    	System.out.println();
    }
    
    public static void dfs(int node, int cnt, boolean isSubset) {
    	
    	visit[node] = true;
    	for(int i=0;i<G[node].size();i++) {
    		int nextNode = G[node].get(i);
    		if(!visit[nextNode] && subset[nextNode] == isSubset) {
    			dfs(nextNode, cnt+1, isSubset);
    		}
    	}
    }
    
    public static int findStart(boolean isSubset) {
    	for(int i=1;i<=N;i++) {
    		if(subset[i] == isSubset) return i;
    	}
    	return -1;
    }
    
    public static void makeSubset(int index) {
    	if(index == N) {
    		Arrays.fill(visit, false);
    		//한쪽 확인
    		int start = findStart(true);
    		if(start == -1) return;
    		dfs(start, 0, true);
    		int sum = 0;
    		//printNowSet();
    		for(int i=1;i<=N;i++) {
    			if(subset[i] && visit[i]) {
    				sum+=peopleNum[i];
    			}
    			if(subset[i] != visit[i]) return;
    		}
    		
    		//다른쪽 확인
    		start = findStart(false);
    		if(start == -1) return;
    		dfs(start, 0, false);
    		//printNowSet();
    		for(int i=1;i<=N;i++) {
    			if(!subset[i] && !visit[i]) { 
    				return;
    			}
    		}
    		//System.out.println("now: "+Math.abs(sum - (totalNum-sum)));
    		minDiff = Math.min(minDiff, Math.abs(sum - (totalNum-sum)));
    		return;
    	}
    	
    	subset[index] = true;
    	makeSubset(index+1);
    	subset[index] = false;
    	makeSubset(index+1);
    }
    
    public static void main(String[] args) throws Exception {
    	
    	N = Integer.parseInt(br.readLine());

        peopleNum = new int[N+1];
        visit = new boolean[N+1];
        subset = new boolean[N+1];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=1;i<=N;i++) {
        	peopleNum[i] = Integer.parseInt(st.nextToken());
        	totalNum += peopleNum[i];
        }
                
        //System.out.println("totalNum: "+totalNum);
        G = new ArrayList[N+1];        
        for(int i=1;i<=N;i++) {
        	G[i] = new ArrayList<>();
        }
        for(int i=1;i<=N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	int n = Integer.parseInt(st.nextToken());
        	for(int j=0;j<n;j++) {
        		int a = Integer.parseInt(st.nextToken());
        		G[i].add(a);
        		//G[a].add(i);
        	}
        }
        
//        for(int i=1;i<=N;i++) {
//        	Arrays.fill(visit, false);
//        	dfs(i,peopleNum[i],1);
//        }
//        dfs(1,peopleNum[1],1);
//        dfs(1,0,0);
        
        makeSubset(1);
        
        if(minDiff == 1000000) bw.write("-1");
        else bw.write(""+minDiff);	

        bw.close();
    }    

    static class Info{
    	int n;
    	int cnt;
    	int sum;
    	
		public Info(int n, int cnt, int sum) {
			super();
			this.n = n;
			this.cnt = cnt;
			this.sum = sum;
		}
		
		@Override
		public String toString() {
			return "Info [n=" + n + ", cnt=" + cnt + ", sum=" + sum + "]";
		}
    }

}

/**
9
1 2 3 4 5 6 7 8 9
2 2 4
4 1 3 5 4
4 2 5 8 7
4 6 9 1 2
2 2 3
1 4
1 3
1 3
1 4
답: 1(3, 5, 7, 8 / 1, 2, 4, 6, 9)
*/
