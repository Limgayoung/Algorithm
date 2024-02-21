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

/**
 * 
 */

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static boolean[] visit;
    static ArrayList<Integer>[] G;
    
    static int N, M;    
    static boolean isExist = false;
    
    public static void dfs(int index, int cnt) {
    	if(cnt >= 4) { //친구 관계 만족!
    		isExist = true;
    		return;
    	}    	
		visit[index] = true;  
    	for(int i=0;i<G[index].size();i++) {
    		if(isExist) return;
    		int nextNode = G[index].get(i);
    		if(!visit[nextNode]) {
    			dfs(nextNode, cnt+1);
    			visit[nextNode] = false;
    		}
    	}
    	
    }
    
    
	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		G = new ArrayList[N];
		visit = new boolean[N];
		
		for(int i=0;i<N;i++) {
			G[i] = new ArrayList<Integer>();
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			G[a].add(b);
			G[b].add(a);
		}
		
		for(int i=0;i<N;i++) {
			if(isExist) break;
			Arrays.fill(visit, false);
			dfs(i,0);
		}

		if(isExist) bw.write("1");
		else bw.write("0");

		
		

		bw.close();
	}	

}

/**

6 6
0 1
0 2
0 3
0 4
0 5
5 1
*/
