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

/**
 * 
 */

public class Code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[][] arr;
    static boolean[] visit;
    static int[] player; //선수 순서
    static int maxScore = 0;
    static boolean[] loo;
    
    public static int changeLoo(int result) {
    	int outNum = 0;
    	boolean[] resultLoo = new boolean[4];    	
    	
    	for(int i=0;i<4;i++) {
    		if(!loo[i]) continue;
    		int index = i+result;
    		if(index > 3) { //나감
    			outNum++;
    		}
    		else {
    			resultLoo[index] = true;
    		}
    	}
    	  	
    	for(int i=0;i<4;i++) {
    		loo[i] = resultLoo[i];
    	}

    	return outNum;
    }
    
    public static int playGame() {
    	loo = new boolean[4];
    	int score = 0;
    	int out = 0;
    	int index = 0;
    	
    	for(int i=0;i<N;i++) { //각 이닝 진행
    		out = 0;
    		Arrays.fill(loo, false);
    		
    		while(true) { //3아웃 전까지 계속 진행
    			if(out>2) break;
    			int nowPlayer = player[index];
    			int nowResult = arr[i][nowPlayer];
    			if(nowResult == 0) { //아웃
    				out++;
    			}
    			else {
    				loo[0] = true;
    				score += changeLoo(nowResult);
    			}    			
    			index++;
    			index%=9;
    		}
    	}
    	return score;
    }
    
    public static void makePer(int index, int cnt) {
    	if(cnt > 8) {
    		int nowScore = playGame();
    		//System.out.println(nowScore);
    		//System.out.println(Arrays.toString(player));
    		maxScore = Math.max(maxScore, nowScore);
    		return;
    	}
    	
    	if(cnt == 3) {    		
    		player[cnt] = 0;
    		makePer(index, cnt+1);
    	}
    	else {
	    	for(int i=1;i<9;i++) {
	    		if(!visit[i]) {
		    		visit[i] = true;
		    		player[cnt] = i;
		    		makePer(i+1, cnt+1);
		    		visit[i] = false;
	    		}
	    	}
    	}
    }

    public static void main(String[] args) throws Exception {
    	
        N = Integer.parseInt(br.readLine());
        arr = new int[N][9];       
        
        for(int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=0;j<9;j++) {
        		arr[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        
        visit = new boolean[9];
        visit[0] = true;
        player = new int[9];
        player[3] = 0;
        makePer(0,0);
        bw.write(maxScore+"");	

        bw.close();
    }    

}

/**
10
2
0 0
0 100
1.0
*/
