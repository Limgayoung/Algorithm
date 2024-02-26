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
 * 완탐
 * 모든 지점에서 다 dfs 돌리기
 */

public class Code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int R,C;
    static char[][] map;
    static boolean[] visit = new boolean[26];
    
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    
    static int maxDist = 0;
    
    public static void dfs(int x, int y, int cnt) {
//    	System.out.println("x: "+x+" y: "+y+" cnt: "+cnt);
//    	System.out.println("now map: "+map[x][y]);
    	visit[map[x][y]-'A'] = true;
    	
    	for(int i=0;i<4;i++) {
    		int nx = x+dx[i];
    		int ny = y+dy[i];
    		
    		if(nx>=0&&nx<R&&ny>=0&&ny<C) {
    			if(!visit[map[nx][ny]-'A']) {
    				visit[map[nx][ny]-'A'] = true;
    				dfs(nx,ny,cnt+1);
    				visit[map[nx][ny]-'A'] = false;
    			}
    			else { //다음 방문할 곳이 중복 알파벳 -> 종료
    				maxDist = Math.max(maxDist, cnt);
    			}
    		}
    		else { //다음 방문할 곳이 바깥 -> 종료
				maxDist = Math.max(maxDist, cnt);
			}
    	}
    }

    public static void main(String[] args) throws Exception {
    	st = new StringTokenizer(br.readLine(), " ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        
        map = new char[R][C];        
        
        for(int i=0;i<R;i++) {
        	String str = br.readLine();
        	for(int j=0;j<C;j++) {
        		map[i][j] = str.charAt(j);        				
        	}
        }
        
        dfs(0,0,1);
        
        bw.write(maxDist+"");	

        bw.close();
    }    

}

/**
*/
