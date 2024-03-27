import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static char[][] map;
	static Point start;
	static int[] dx= {-1,1,0,0};
	static int[] dy= {0,0,-1,1};
	static boolean[][][] visit;
	static int minCount = -1;
	static int N, M;
	//2500 size, 

	public static void findMinDist() {
		PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return Integer.compare(o1.count, o2.count);
			}
		});
		
		pq.add(new Info(start.x, start.y, 0, 0));
		
		while(!pq.isEmpty()) {
			Info nowInfo = pq.poll();
			int x = nowInfo.x;
			int y = nowInfo.y;
			int count = nowInfo.count;
			int nowKey = nowInfo.key;
			
			//System.out.print(map[x][y]+" ");
			//System.out.println(nowInfo);
			//System.out.println("x: "+x+" y: "+y+" count: "+count+" char: "+map[x][y]+" setSize: "+nowKey.size());
			if(map[x][y] == '1') {
				minCount = count;
				break;
			}
			
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if(nx>=0 && nx<N && ny>=0 && ny<M && map[nx][ny]!='#' && !visit[nowKey][nx][ny]) {
					char nextChar = map[nx][ny];
					int nextKey = nowKey;
                      
					if(nextChar >= 'A' && nextChar <= 'Z') { //키 있어야 지나갈 수 있음
						//System.out.println(nextChar-'A');
						if((nextKey & (1<<(nextChar-'A'))) != (1<<(nextChar-'A'))) {
							continue;	
						}																		
						//System.out.println("통과!");
					}
					if(nextChar >= 'a' && nextChar <= 'z') { //열쇠 줍기 가능, 주우면 visit 초기화
						if((nextKey & (1<<(nextChar-'a'))) != (1<<(nextChar-'a'))) { //이미 주운 열쇠
							nextKey |= (1<<(nextChar-'a'));
							//System.out.println("key!");
						}
						else {
							
						}													
					}
					visit[nextKey][nx][ny] = true;
					pq.add(new Info(nx,ny,nextKey,count+1));
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new char[N][M];
		visit = new boolean[64][N][M];
		start = new Point(-1,-1);
		
		for(int i=0;i<N;i++) {
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = str.charAt(j);
				if(map[i][j] == '0') {
					start = new Point(i,j);
				}
			}
		}
		//System.out.println("입력 완료");
		findMinDist();
		
		//System.out.println((char)('B'-'A'+'a'));

		bw.write(minCount+"\n");
		    
	    bw.close();
	
	}
	
	public static class Info{
		int x;
		int y;	
		int key;
		int count;
		
		public Info(int x, int y, int key, int count) {
			super();
			this.x = x;
			this.y = y;
			this.key = key;
			this.count = count;
		}
		@Override
		public String toString() {
			return "Info x=" + x + ", y=" + y + ", key=" + Integer.toBinaryString(key) + ", count=" + count;
		}
		
					
		
	}
	
}
