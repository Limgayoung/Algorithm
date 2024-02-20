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
 * 마지막에 남은 치즈 부분 개수와 치즈가 없어지는데 걸리는 시간 구하기
 * queue에 {좌표 정보, 현재 레벨} 넣기
 * 현재 레벨이 달라졌을 때의 queue size가 현재 시점의 치즈 개수  
 */

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N, M;
    static int[][] map;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static boolean[][] visit;    
    static Queue<Info> q = new LinkedList<>();
    static int hour, cnt;
    static boolean flag;
    
    public static void printVisit() {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			if(visit[i][j]) {
    				System.out.print(1+ " ");
    			}
    			else {
    				System.out.print(0+ " ");
    			}
    		}
    		System.out.println();
    	}
    	System.out.println();
    }
    
    public static void printMap() {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			System.out.print(map[i][j]+" ");
    		}
    		System.out.println();
    	}
    	System.out.println();
    }
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<N && y>=0 && y<M) return true;
    	return false;
    }

    
    public static void dfs(int x, int y) {
    	visit[x][y] = true;
    	
    	for(int i=0;i<4;i++) {
    		int nx = x+dx[i];
    		int ny = y+dy[i];
    		
    		if(isInside(nx, ny)) {
    			if(!visit[nx][ny] && map[nx][ny] == 0) {
        			dfs(nx,ny);
        		}
        		else {
        			if(!visit[nx][ny]) {
        				q.offer(new Info(nx,ny,1));
        				flag = false;
        				visit[nx][ny] = true;
        			}        			
        		}
    		}
    		
    	}
    }
    
    public static void changeCheeseStatus() {
    	while(!q.isEmpty()) {
    		map[q.peek().x][q.peek().y] = 0;
    		q.poll();
    	}
    }
    
	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int[N][M];
		visit = new boolean[N][M];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		while(true) {
			flag = true;
			visit = new boolean[N][M];
			
			dfs(0,0);	
//			printVisit();

			if(q.size() == 0) { //변화 없음, 마지막
				//System.out.println("qsize: "+q.size());
				break;
			}

			cnt = q.size();			
			hour++;
			
			changeCheeseStatus();
			//printMap();
			//System.out.println("cnt: "+cnt+" hour: "+hour);
		}	
		
		bw.write(hour+"\n"+cnt);
		bw.close();
	}
	
	static class Info{
		int x;
		int y;
		int level;
		
		public Info(int x, int y, int level) {
			this.x = x;
			this.y = y;
			this.level = level;
		}
		@Override
		public String toString() {
			return "info [x=" + x + ", y=" + y + ", level=" + level + "]";
		}
	}

}
