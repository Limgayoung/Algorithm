import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

/*



*/

public class swea_1249 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int N;
	static int[][] arr;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static boolean[][] visit;
	static int answer;
	
	private static boolean isInside(int nx, int ny) {
		if(nx>=0 && nx<N && ny>=0 && ny<N) return true;
		return false;
	}
	
	public static void bfs() {
		PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return Integer.compare(o1.cnt, o2.cnt);
			}
		});
		
		pq.add(new Info(0,0,0));
		
		while(!pq.isEmpty()) {
			Info nowInfo = pq.poll();
			int x = nowInfo.x;
			int y = nowInfo.y;
			int cnt = nowInfo.cnt;
			
			if(x == N-1 && y == N-1) {
				answer = cnt;
				break;
			}
			
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if(!isInside(nx,ny) || visit[nx][ny]) continue;
				visit[nx][ny] = true;
				pq.add(new Info(nx,ny,cnt+arr[nx][ny]));
			}
		}
	}

	public static void main(String[] args) throws Exception {					
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++) {
			N = Integer.parseInt(br.readLine());	
			arr = new int[N][N];
			visit = new boolean[N][N];
			answer = -1;
			
			for(int i=0;i<N;i++) {
				String str = br.readLine();
				for(int j=0;j<N;j++) {
					arr[i][j] = str.charAt(j)-'0';
				}
			}
			
			bfs();
			bw.write("#"+t+" "+answer+"\n");
			
		}
		
		
	    bw.close();
	}
	
	public static class Info{
		int x;
		int y;
		int cnt;
		public Info(int x, int y, int cnt) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
		@Override
		public String toString() {
			return "Info [x=" + x + ", y=" + y + ", cnt=" + cnt + "]";
		}
		
		
	}

/*


 */
	
}
