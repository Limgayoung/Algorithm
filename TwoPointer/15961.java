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
    static int N,d,k,c;
    static int[] foods;
    static int[] eatCnt;
    static boolean flag = false;
    
    public static void printArr(int l, int r) {
    	for(int i=l;i<=r;i++) {
    		System.out.print(foods[i]+" ");
    	}
    	System.out.println();
    }

    public static void main(String[] args) throws Exception {
    	
    	st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        
        int maxLength = 0;        
        
        foods = new int[N];
        eatCnt = new int[3001];
        
        for(int i=0;i<N;i++) {
        	foods[i] = Integer.parseInt(br.readLine());
        }
        
        //처음 윈도우 초기화
        int l = 0;
        int r = k-1;
        int nowCnt = 0;
        for(int i=0;i<k;i++) {
        	if(eatCnt[foods[i]] == 0) { //한 번도 먹은 적 없음
        		nowCnt++;
        	}
        	eatCnt[foods[i]]++;
        }
        
        if(eatCnt[c] == 0) { //쿠폰 사용 안함
    		maxLength = Math.max(maxLength, nowCnt+1);
    	}
    	else {
    		maxLength = Math.max(maxLength, nowCnt);
    	}
        
        //윈도우 1칸씩 밀어가며 확인
        for(int i=1;i<N;i++) {
        	eatCnt[foods[l]]--;
        	if(eatCnt[foods[l]] == 0) { //중복 아니었음
        		nowCnt--;
        	}
        	l++;
        	l%=N;        
        	
        	r++;
        	r%=N;
        	eatCnt[foods[r]]++;
        	if(eatCnt[foods[r]] == 1) { //처음 먹음
        		nowCnt++;
        	}
        	
        	if(eatCnt[c] == 0) { //쿠폰 사용 안함
        		maxLength = Math.max(maxLength, nowCnt+1);
        	}
        	else {
        		maxLength = Math.max(maxLength, nowCnt);
        	}
        }

        bw.write(maxLength+"");	

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
