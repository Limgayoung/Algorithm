package com.day2.perm;

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

public class sweq {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[][] g;
    static Point[] positions;
    static boolean[] isVisit;
    static int answer;
    
    public static int calDistance(Point a, Point b) {    
    	return Math.abs(a.x-b.x) + Math.abs(a.y-b.y);     	
    }
    
    //회사와 home, 모든 고객은 모두 연결되어 있어야 함
	//이들의 거리는 |x1-x2| + |y1-y2|
    public static void initGraph() {
    	for(int i=0;i<=N+1;i++) {
    		for(int j=0;j<=N+1;j++) {    			
    			g[i][j] = calDistance(positions[i], positions[j]);
    		}
    	}
    }
    
    // start에서 출발해서 end까지 가는 모든 경우 다 따지기
    public static void dfs(int n, int cnt, int dist) {
    	//System.out.println("n: "+n+" cnt: "+cnt+" dist: "+dist);
    	if(cnt == N) {
    		dist += calDistance(positions[N+1], positions[n]);
			//System.out.println("find!! "+dist);
			answer = Math.min(dist, answer);    		
    		return;
    	}    	    
    	
    	for(int i=1;i<N+1;i++) {
    		if(n == i) continue; //자기자신
    		int nextNode = i;
    		int nextDist = g[n][nextNode];
    		//System.out.println("n: "+n+" cnt: "+cnt+" dist: "+dist);
    		//System.out.println("next: "+nextNode+" nextDist: "+nextDist);
    		if(!isVisit[nextNode]) {
    			isVisit[nextNode] = true;
    			dfs(nextNode, cnt+1, dist+nextDist);
    			isVisit[nextNode] = false;
    		}
    	}
    }

    public static void main(String[] args) throws Exception {    	    	    	    	    	    	    
    	
    	int T = Integer.parseInt(br.readLine());
    	  
    	for(int t=1;t<=T;t++) {
    		answer = 1000000;
	    	N = Integer.parseInt(br.readLine());
	    	st = new StringTokenizer(br.readLine(), " ");
	    	
	    	positions = new Point[N+2];
	    	isVisit = new boolean[N+2];
	    	
	    	g = new int[N+2][N+2];
	    
	    	//회사는 0번 노드, 집은 N+1번 노드, 고객의 집은 1~N 노드
	    	positions[0] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
	    	positions[N+1] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
	    	
	    	for(int i=1;i<=N;i++) {
	    		positions[i] =  new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
	    	}
	    	
	//    	for(int i=0;i<=N+1;i++) {
	//    		System.out.println(positions[i]);
	//    	}
	    	
	    	//그래프 만들기
	    	initGraph();
	    	//printGraph();
	    	dfs(0,0,0);
	    	bw.write("#"+t+" "+answer+"\n");
    	}
        bw.close();
    }             
}

/*


*/
