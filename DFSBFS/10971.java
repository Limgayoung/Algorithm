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
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;

import javax.print.StreamPrintService;


public class Main {
	
	/**
	 * 		
	 */
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N;
    static int[][] arr;
    static boolean[] visit;
    static int minSum;
    static int startN;

    public static void dfs(int cnt, int index, int sum) {
    	//System.out.println("cnt: "+cnt+" index: "+index+" sum: "+sum);
    	if(cnt == N-1) {
    		//System.out.println("sum: "+sum);
    		if(arr[index][startN] == 0) return;
    		minSum = Math.min(minSum, sum+arr[index][startN]);
    		return;
    	}
    	
    	for(int i=0;i<N;i++) {
    		if(!visit[i] && arr[index][i] != 0) {
    			visit[i] = true;    			
    			dfs(cnt+1, i, sum+arr[index][i]);
    			visit[i] = false;
    		}
    	}
    }
    
    public static void main(String[] args) throws Exception {    	
    	
    	N = Integer.parseInt(br.readLine());
    	arr = new int[N][N];
    	
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=0;j<N;j++) {
    			arr[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	visit = new boolean[N];
    	minSum = 987654321;
    	
    	for(int i=0;i<N;i++) {
    		Arrays.fill(visit, false);
    		visit[i] = true;
    		startN = i;
    		dfs(0,i,0);
    	}

    	bw.write(minSum+"");
        bw.close();
    }    

}



/**
1
4 4
0 0 0 0
0 0 0 0
0 0 1 1
0 0 1 0


 */
