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

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int L,C;
    static char[] arr;
    static boolean[] visit;
    
    public static boolean isMo(char c) {
    	if(c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u') return true;
    	return false;
    }
    
    public static void dfs(int index, int moCnt, int zaCnt, String str) throws Exception {
    	//System.out.println(str);
    	if(str.length() >= L) {
    		if(moCnt>=1 && zaCnt>=2) {
    			bw.write(str+"\n");
    		}
    		return;
    	}
    	//visit[index] = true;
    	for(int i=index;i<C;i++) {
    		if(!visit[i]) {
	    		visit[i] = true;
	    		if(isMo(arr[i])) dfs(i+1, moCnt+1, zaCnt, str+arr[i]);
	    		else dfs(i+1, moCnt, zaCnt+1, str+arr[i]);
	    		visit[i] = false;
    		}
    	}
    }

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine(), " ");
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		arr = new char[C];
		visit = new boolean[C];
		
		st = new StringTokenizer(br.readLine(), " ");
		
		for(int i=0;i<C;i++) {
			arr[i] = st.nextToken().charAt(0);
		}
		
		Arrays.sort(arr);
		//System.out.println(Arrays.toString(arr));
		dfs(0,0,0,"");
		
		bw.write("");

		bw.close();
	}	

}

/**
4 6
0 0 0 0 0 0
3 0 0 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0
13

*/
