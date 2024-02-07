import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class swea {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N,M;
    static int[][] arr;
    static int[][] visit;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    
    static class Room{
    	int x;
    	int y;
    	int cnt;
    	
		public Room(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
    	
    }
        
    public static int findCnt(int x, int y) {
    	PriorityQueue<Room> pq = new PriorityQueue<>((a,b) -> a.cnt - b.cnt);
    	
    	pq.offer(new Room(x, y, 1));
    	int maxCnt = 1;
    	
    	while(!pq.isEmpty()) {
    		Room nowRoom = pq.poll();
    		int nowNum = arr[nowRoom.x][nowRoom.y];    	
    		visit[nowRoom.x][nowRoom.y] = 1;
    		maxCnt = Math.max(nowRoom.cnt, maxCnt);
    		
    		for(int i=0;i<4;i++) {
    			int nx = nowRoom.x + dx[i];
    			int ny = nowRoom.y + dy[i];
    			
    			if(nx>=0 && nx<N && ny>=0 && ny<N && arr[nx][ny]-nowNum==1) {
    				if(visit[nx][ny]==0) {
    					pq.offer(new Room(nx,ny,nowRoom.cnt+1));
    				}
    				else {
    					return visit[nx][ny]+nowRoom.cnt;
    				}
    				
    			}
    			
    		}
    	}
    	return maxCnt;
    }

    public static void main(String[] args) throws Exception {
    	//st = new StringTokenizer(br.readLine(), " ");
    	
    	int T = Integer.parseInt(br.readLine());    	
    	
    	for(int t = 1;t<=T;t++) {
    		int answer = 1;
    		int answerRoomNum = 0;
    		N = Integer.parseInt(br.readLine());
    		arr = new int[N][N];
    		visit = new int[N][N];
    		
    		for(int i=0;i<N;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			for(int j=0;j<N;j++) {
    				arr[i][j] = Integer.parseInt(st.nextToken());
    			}
    		}
    		
    		for(int i=0;i<N;i++) {
    			for(int j=0;j<N;j++) {
    				if(visit[i][j]!=0) continue;
    				int nowMaxCnt = findCnt(i,j);
    				if(answer < nowMaxCnt) {
    					answer = nowMaxCnt;
    					answerRoomNum = arr[i][j];
    				}
    				else if(answer == nowMaxCnt) {
    					if(answerRoomNum > arr[i][j]) {
    						answerRoomNum = arr[i][j];
    					}
    				}
    				visit[i][j] = nowMaxCnt;
    			}
    		}
    		
    		bw.write("#"+t+" "+answerRoomNum+" "+answer+"\n");
    	}

        bw.close();
    }             
    
    

    
}

/*

*/
