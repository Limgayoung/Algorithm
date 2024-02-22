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
 * 매 시간마다 물 bfs로 확장, 고슴도치 bfs로 이동
 */

public class Code {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M;
    static char[][] map;
    static Point start, end;
    static Queue<Info> water = new LinkedList<>();
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static boolean isDone = false;
    static int minTime = 0;
    static int beforeTime = 0;
    
    public static void printMap() {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			System.out.print(map[i][j]);
    		}
    		System.out.println();
    	}
    	System.out.println();
    }
    
    public static void floodWater() {
    	while(!water.isEmpty() && water.peek().time == beforeTime) {
    		int x = water.peek().x;
    		int y = water.peek().y;
    		int time = water.peek().time;
    		water.poll();
    		
    		for(int i=0;i<4;i++) {
    			int nx = x+dx[i];
    			int ny = y+dy[i];
    			if(nx>=0 && nx<N && ny>=0 && ny<M) {
    				if(map[nx][ny] =='.') {
    					map[nx][ny] = '*';
    					water.offer(new Info(nx,ny,time+1));
    				}
    			}
    		}
    	}
    }
    
    public static void move() {
    	PriorityQueue<Info> pq = new PriorityQueue<>();
    	pq.offer(new Info(start.x, start.y, 0));
    	
    	while(!pq.isEmpty()) {
    		int x = pq.peek().x;
    		int y = pq.peek().y;
    		int time = pq.peek().time;
    		//System.out.println("x: "+x+" y: "+y+" time: "+time);

    		if(x==end.x && y==end.y) {
    			isDone = true;
    			return;
    		}
    		if(time != beforeTime) { //시간 1초 지남
    			//System.out.println("nowTime: "+time+" beforeTime: "+beforeTime);
    			floodWater();
    			minTime++;
    			beforeTime = time;
    		}	
    		pq.poll();
    		if(map[x][y] != '.' && map[x][y] != 'S') continue;
    		map[x][y] = 'o';

    		//printMap();
    		for(int i=0;i<4;i++) {
    			int nx = x+dx[i];
    			int ny = y+dy[i];
    			
    			if(nx>=0 && nx<N && ny>=0 && ny<M) {
    				if(map[nx][ny] == '.') {
    					pq.offer(new Info(nx,ny,time+1));
    				}
    				else if(map[nx][ny] == 'D') {
    					minTime++;
    					isDone = true;
    					return;
    				}
    			}
    		}
    	}
    }

    public static void main(String[] args) throws Exception {
    	
    	st = new StringTokenizer(br.readLine(), " ");
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	
    	map = new char[N][M];
    	
    	for(int i=0;i<N;i++) {
    		String s = br.readLine();
    		for(int j=0;j<M;j++) {
    			map[i][j] = s.charAt(j);
    			if(map[i][j] == 'S') {
    				start = new Point(i,j);
    			}
    			else if(map[i][j] == 'D') {
    				end = new Point(i,j);    				
    			}
    			else if(map[i][j] == '*') {
    				water.offer(new Info(i,j,0));
    			}
    		}
    	}

    	move();
        
    	if(!isDone) bw.write("KAKTUS");
    	else bw.write(minTime+"");	

        bw.close();
    }    


    static class Info implements Comparable<Info>{
    	int x;
    	int y;
    	int time;
    	
		public Info(int x, int y, int time) {
			super();
			this.x = x;
			this.y = y;
			this.time = time;
		}

		@Override
		public int compareTo(Info o) {
			// TODO Auto-generated method stub
			return this.time - o.time;
		}
    	
    }
}

/**

*/
