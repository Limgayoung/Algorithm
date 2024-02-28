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
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int K, W, H;
    static int[][] map;
    //static int[][][] dp; //각 위치까지 가기 위해 K번 말처럼 뛰었을 때의 동작 최솟값
    static int[] mdx = {-1,1,0,0};
    static int[] mdy = {0,0,-1,1};
    static int[] hdx = {-2,-2,-1,-1,1,1,2,2};
    static int[] hdy = {-1,1,-2,2,-2,2,-1,1};
    static boolean[][][] visit;
    static int minCnt =  987654321;
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<H && y>=0 && y<W) return true;
    	return false;
    }
    
    public static void bfs() {
    	PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {

			@Override
			public int compare(Info o1, Info o2) {
				return Integer.compare(o1.cnt, o2.cnt);
			}
		});
    	
    	pq.offer(new Info(0,0,0,0)); //x,y,사용한 말  횟수, 동작수
    	
    	while(!pq.isEmpty()) {
    		Info nowInfo = pq.poll();
    		int x = nowInfo.x;
    		int y = nowInfo.y;
    		int k = nowInfo.k;
    		int cnt = nowInfo.cnt;
    		//if(visit[x][y]) continue;
    		//visit[x][y][k] = true;
    		//System.out.println("x: "+x+" y: "+y+" k: "+k+" cnt: "+cnt);
    		if(x == H-1 && y == W-1) {
    			minCnt = cnt;
    			break;
    		}
    		
    		//k가 K보다 작을 경우에 12방향 모두 가능
    		for(int i=0;i<4;i++) {
    			int nx = x+mdx[i];
        		int ny = y+mdy[i];
        		
        		if(isInside(nx, ny) && map[nx][ny] != 1 && !visit[nx][ny][k]) {
        			visit[nx][ny][k] = true;
        			//System.out.println("push!");;
        			pq.offer(new Info(nx,ny,k,cnt+1));
        		}
    		}
    		if(k>=K) continue;
			for(int i=0;i<8;i++) {
    			int nx = x+hdx[i];
        		int ny = y+hdy[i];
        		
        		if(isInside(nx, ny) && map[nx][ny] != 1 && !visit[nx][ny][k+1]) {
        			visit[nx][ny][k+1] = true;
        			//System.out.println("horse push!");
        			pq.offer(new Info(nx,ny,k+1,cnt+1));
        		}
    		}
    		
    	}
    }

    public static void main(String[] args) throws Exception {
    	K = Integer.parseInt(br.readLine());
    	
    	st = new StringTokenizer(br.readLine(), " ");
    	W = Integer.parseInt(st.nextToken());
    	H = Integer.parseInt(st.nextToken());
    	
    	map = new int[H][W];
    	
    	for(int i=0;i<H;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=0;j<W;j++) {
    			map[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	visit = new boolean[H][W][K+1];
    	
    	bfs();
    	
    	if(minCnt != 987654321) bw.write(minCnt+"");
    	else bw.write("-1");    	

        bw.close();
    }    
    
    static class Info implements Comparator<Info>{
    	int x;
    	int y;
    	int k;
    	int cnt;
    	
		public Info(int x, int y, int k, int cnt) {
			this.x = x;
			this.y = y;
			this.k = k;
			this.cnt = cnt;
		}

		@Override
		public String toString() {
			return "Info [x=" + x + ", y=" + y + ", k=" + k + ", cnt=" + cnt + "]";
		}

		@Override
		public int compare(Info o1, Info o2) {
			return Integer.compare(o1.cnt, o2.cnt);
		}
    	
    	
    }

}

/**
1
4 4
0 0 0 0
0 0 0 0
0 0 1 1
0 0 1 0

5 5
0 0 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
1 0 0 0 0

 */
