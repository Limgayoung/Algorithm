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


public class Code {
	
	/**
	 * 모든 코어에서 4방향으로 완탐 해보기, 다 꽂았다면 min 값 갱신
	 */
	
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N;
    static int[][] map;
    static ArrayList<Point> maxi;
    static int minLength = 987654321;
    static int maxCnt = 0;
    
    //상하좌우
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    
    public static void printVisit(boolean[][] visit) {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			if(visit[i][j]) System.out.print("1 ");
    			else System.out.print("0 ");
    		}
    		System.out.println();
    	}
    	System.out.println();
    }
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<N && y>=0 && y<N) return true;
    	return false;
    }
    
    public static boolean canConnect(int index, int dir, boolean[][] visit) {
    	int x = maxi.get(index).x;
    	int y = maxi.get(index).y;
    	
    	boolean flag = true;
    	
    	while(true) {
    		int nx = x+dx[dir];
    		int ny = y+dy[dir];
    		
    		if(isInside(nx,ny)) {
    			if(map[nx][ny] == 1 || visit[nx][ny]) {
    				flag = false;
    				break;
    			}
    		}
    		else break;
    		
    		x = nx;
    		y = ny;
    	}
    	
    	return flag;
    }
    
    public static void dfs(int index, boolean[][] visit, int cnt, int length) {
    	if(index == maxi.size()) {
    		//if(cnt == 7)
    			//System.out.println("cnt: "+cnt+" length: "+length);
    		//printVisit(visit);
    		if(cnt < maxCnt) return;
    		if(cnt > maxCnt) {
    			maxCnt = cnt;
    			minLength = length;
    		}
    		else if(cnt == maxCnt) {
    			minLength = Math.min(minLength, length);
    		}
//    		System.out.println("cnt: "+cnt+" length: "+length);
//    		System.out.println("maxCnt: "+maxCnt+" minLength: "+minLength);
    		
    		return;
    	}
    	if(cnt + maxi.size() - index < maxCnt) return;
    	
    	//현재 index인 maxi를 4방향 직선으로 전원 연결해보기
    	for(int i=0;i<4;i++) {
    		if(canConnect(index, i, visit)) {
    			boolean[][] temp = new boolean[N][N];
    			for(int j=0;j<N;j++) {
    				for(int k=0;k<N;k++) {
    					temp[j][k] = visit[j][k];
    				}
    			}
    			
    			int x = maxi.get(index).x;
    	    	int y = maxi.get(index).y;
    	    	int l = 0;
    	    	
    	    	while(true) {
    	    		int nx = x+dx[i];
    	    		int ny = y+dy[i];
    	    		
    	    		if(!isInside(nx,ny)) {
    	    			break;
    	    		}
    	    		temp[nx][ny] = true;
    	    		x = nx;
    	    		y = ny;
    	    		l++;
    	    	}
    	    	
    	    	dfs(index+1, temp, cnt+1, length+l);
    		}
    		else dfs(index+1, visit, cnt, length);
    		
    	}
    }

    public static void main(String[] args) throws Exception {
    	
    	int T = Integer.parseInt(br.readLine());
//    	int T = 1;
    	
    	for(int t=1;t<=T;t++) {
    		N = Integer.parseInt(br.readLine());
    		map = new int[N][N];
    		minLength = 987654321;
    		maxCnt = 0;
    		 maxi = new ArrayList<>();

    		for(int i=0;i<N;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			for(int j=0;j<N;j++) {
    				map[i][j] = Integer.parseInt(st.nextToken());
    				if(map[i][j] == 1) {
    					maxi.add(new Point(i,j));
    				}
    			}
    		}
    		dfs(0,new boolean[N][N],0,0);
        	bw.write("#"+t+" "+minLength+"\n");    
    	}    	

        bw.close();
    }        
}

/**
3
7
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
 */
