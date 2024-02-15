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

public class Solution {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int M,A;
    static int[] userA, userB;
    static APInfo[] apInfos;
    static int answer = 0;
    static Point[][] map;
    static int[][] apNumMap; //각 위치의 제일 성능이 좋은 ap num 저장
    
    //이동x, 상우하좌
    static int dx[] = {0,0,1,0,-1};
    static int dy[] = {0,-1,0,1,0};
    
    public static void printMap() {
    	for(int i=0;i<10;i++) {
    		for(int j=0;j<10;j++) {
//    			System.out.print("("+map[i][j].x+" "+map[i][j].y+") ");
    			System.out.printf("%3d ",map[i][j].x);
    		}
    		System.out.println();
    	}
    	
    	System.out.println();
    	for(int i=0;i<10;i++) {
    		for(int j=0;j<10;j++) {
//    			System.out.print("("+map[i][j].x+" "+map[i][j].y+") ");
    			System.out.printf("%3d ",apNumMap[i][j]);
    		}
    		System.out.println();
    	}
    }
    
    public static int calDist(Point a, Point b) {
    	return Math.abs(a.x-b.x) + Math.abs(a.y-b.y);
    }
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<10 && y>=0 && y<10) return true;
    	return false;
    }
    
    //현재 위치에서 충전 가능한 AP 중 상위 2개까지 저장, 성능만 저장
    public static void initMap() {
    	
    	for(int i=0;i<10;i++) {
    		for(int j=0;j<10;j++) {
    			map[i][j] = new Point(0,0);
    		}
    	}
    	
    	for(int a=0;a<A;a++) {
    		int starty = apInfos[a].x;
    		int startx = apInfos[a].y;
    		int c = apInfos[a].c;
    		
    		for(int i=startx-c;i<=startx+c;i++) {
    			for(int j=starty-c;j<=starty+c;j++) {
    				if(!isInside(i,j)) continue;
    				//범위 안이면 충전 가능
    				if(calDist(new Point(startx, starty), new Point(i,j)) <= c) {
    					//항상 x가 가장 크게 만들어야 함
    					if(map[i][j].x == 0) {
    						map[i][j].x = apInfos[a].p;
    						apNumMap[i][j] = a+1;
    					}
    					else if(map[i][j].y == 0) {
    						if(map[i][j].x > apInfos[a].p)
    							map[i][j].y = apInfos[a].p;
    						else {
    							map[i][j].y = map[i][j].x;
    							map[i][j].x = apInfos[a].p;   
    							apNumMap[i][j] = a+1;
    						}
    							
    					}
    					else { //비교해서 저장 필요
    						if(map[i][j].y == 0) {
        						if(map[i][j].x > apInfos[a].p)
        							map[i][j].y = apInfos[a].p;
        						else {
        							map[i][j].y = map[i][j].x;
        							map[i][j].x = apInfos[a].p;    	
        							apNumMap[i][j] = a+1;
        						}
    						}
    						else {
	    						if(map[i][j].x > apInfos[a].p) {
	    							if(map[i][j].y < apInfos[a].p) {
	    								map[i][j].y = apInfos[a].p;
	    							}
	    						}
	    						else { //x가 p보다 작으면 p>x>y 순서	    							
	    							map[i][j].y = map[i][j].x;
	    							map[i][j].x = apInfos[a].p;
	    							apNumMap[i][j] = a+1;
	    						}
    						}
    					}
    				}
    			}
    		}
    		
    	}
    }
    
    public static void calMaxCharge() {
    	Point a = new Point(0,0);
    	Point b = new Point(9,9);
    	
    	for(int i=0;i<=M;i++) {
    		Point na = new Point(a.x+dx[userA[i]], a.y+dy[userA[i]]);
    		Point nb = new Point(b.x+dx[userB[i]], b.y+dy[userB[i]]);
    		//System.out.println("now dir: "+userA[i]+" "+userB[i]);
    		//System.out.printf("userA 위치: %d %d nuserB위치: %d %d\n",na.x, na.y, nb.x, nb.y);
    		//같은 구역이면 한 위치의 x,y 더하기
    		if(apNumMap[na.y][na.x]== apNumMap[nb.y][nb.x] ) {
    			//System.out.println("a: "+map[na.y][na.x].x+" b: "+map[na.y][na.x].y);    			
    			answer += map[na.y][na.x].x;
    			answer += Math.max(map[na.y][na.x].y, map[nb.y][nb.x].y);
//    			answer += map[na.y][na.x].y;
    		}
    		else { //각자 위치의 x 더하기
    			//System.out.println("a: "+map[na.y][na.x].x+" b: "+map[nb.y][nb.x].x);
    			answer += map[na.y][na.x].x;
    			answer += map[nb.y][nb.x].x;
    		}
    		a = na;
    		b = nb;
    	}
    }
   
    public static void main(String[] args) throws Exception {    	    	    	    	    	    	    
    	
    	int T = Integer.parseInt(br.readLine());
//    	int T = 1;
    	  
    	for(int t=1;t<=T;t++) {
    		answer = 0;
    		st = new StringTokenizer(br.readLine(), " ");
    		M = Integer.parseInt(st.nextToken());
    		A = Integer.parseInt(st.nextToken());
    		
    		userA = new int[M+1];
    		userB = new int[M+1];
    		apInfos = new APInfo[A];
    		map = new Point[10][10];
    		apNumMap = new int[10][10];
    		
    		//사용자 정보 입력
    		userA[0] = 0;
    		userB[0] = 0;
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int i=1;i<=M;i++) {
    			userA[i] = Integer.parseInt(st.nextToken());
    		}
    		st = new StringTokenizer(br.readLine(), " ");
			for(int i=1;i<=M;i++) {
				userB[i] = Integer.parseInt(st.nextToken());
    		}
			
    		
    		//AP 정보 입력			
    		for(int i=0;i<A;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			apInfos[i] = new APInfo(Integer.parseInt(st.nextToken()),
    					Integer.parseInt(st.nextToken()),
    					Integer.parseInt(st.nextToken()),
    					Integer.parseInt(st.nextToken()));
    			apInfos[i].x--;
    			apInfos[i].y--;
    			
    		}
    		
    		initMap();
    		//printMap();
    		calMaxCharge();
    		
	    	bw.write("#"+t+" "+answer+"\n");
    	}
        bw.close();
    }         
    
    static class APInfo{
    	int x;
    	int y;
    	int c;
    	int p;
    	
		public APInfo(int x, int y, int c, int p) {
			super();
			this.x = x;
			this.y = y;
			this.c = c;
			this.p = p;
		}    	    	
    }
}

/*


*/
