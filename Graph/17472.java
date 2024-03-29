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
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * 1. dfs로 섬 번호 지정, 테두리 저장 
 * 2. 섬에서 다른 섬까지의 다리 길이 구하기, 한 섬에서 다른 섬까지는 최솟값만 저장
 * 		- 한 섬의 테두리 모든 곳에서 다른 모든 섬까지의 길이 구해야 함
 * 		- 상하좌우 일직선으로 탐색, 섬 만나면 길이 갱신 (4 * 30 * 10) * 6
 * 3. 크루스칼 이용해서 모든 섬을 연결하는 최단거리 구하기
 * 		- 다리 길이가 edge와 같음
 * 		- 다리 길이를 sort한 후에 크루스칼 진행 
 */

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int INF = 123456789;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	static int N,M;
	static int[][] map;
	static int[][] islandMap; //섬 번호가 찍혀 있음
	static int islandCnt=0; //섬의 총 개수
	static List<ArrayList<Point>> islandBoundary;
	//static List<Edge> edge = new ArrayList<>();
	static PriorityQueue<Edge> edge;
	static int[] parent;
	
	public static void printIslandMap() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(islandMap[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static boolean isInside(int x, int y) {
		if(x>=0 && x<N && y>=0 && y<M) return true;
		return false;
	}
		
	public static void dfs(int x, int y, int n) {
		//System.out.println(x+" "+y);
		boolean isBoundary = false;
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(isInside(nx,ny) && islandMap[nx][ny] == 0) {
				if(map[nx][ny] == 0) {
					isBoundary = true;
				}
				else {
					islandMap[nx][ny] = n;
					dfs(nx,ny,n);
				}
			}			
		}
		if(isBoundary) {
			//System.out.println("boundary!  "+x+" "+y);
			islandBoundary.get(n).add(new Point(x,y));
		}
	}
	
	public static void makeEdge(int n) { //n번째 섬에서 다른 섬까지의 최소 거리 구하기 (다리 길이)		
		ArrayList<Point> list = islandBoundary.get(n);
		int[] length = new int[islandCnt+1];
		Arrays.fill(length, INF);
		for(int i=0;i<list.size();i++) {
			//상하좌우로 탐색해서 섬이 나온다면 가능한 것, 해당 섬까지의 다리 길이 갱신
			for(int j=0;j<4;j++) {
				int l = 0;
				int x = list.get(i).x;
				int y = list.get(i).y;
				while(true) {
					int nx = x+dx[j];
					int ny = y+dy[j];
					
					if(!isInside(nx, ny)) break;
					if(islandMap[nx][ny] == n) break; //방향 잘못됨
					if(islandMap[nx][ny] != 0) { //섬 찾음
						if(l > 1) //거리가 1보다 커야 가능
							length[islandMap[nx][ny]] = Math.min(length[islandMap[nx][ny]], l);
						break;
					}
					l++;
					x = nx;
					y = ny;
				}
				
				
			}
		}
		for(int i=1;i<=islandCnt;i++) {
			if(length[i] != INF) { //edge!			
				edge.add(new Edge(n,i,length[i]));
			}
		}
	}
	
	public static int findParent(int a) {
		if(parent[a] == a) return a;
		
		return parent[a] = findParent(parent[a]);
	}
	
	public static void makeUnion(int a, int b) {
		int pa = findParent(a);
		int pb = findParent(b);
		
		parent[pb] = pa;
	}

	public static void main(String[] args) throws Exception {
				
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int [N][M];
		islandMap = new int [N][M];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		islandBoundary = new ArrayList<>();
		islandBoundary.add(new ArrayList<>());
		
		//1. dfs로 섬 번호 지정, 테두리 저장 
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 1 && islandMap[i][j] == 0) { //아직 갱신 안된 섬
					islandCnt++;
					islandBoundary.add(new ArrayList<>());
					islandMap[i][j] = islandCnt;
					dfs(i,j,islandCnt);
//					for(int k=0;k<islandBoundary.get(islandCnt).size();k++) {
//						Point p = islandBoundary.get(islandCnt).get(k);
//						System.out.println(islandCnt+"번 섬 "+p.x+" "+p.y);
//					}
//					System.out.println();
				}
			}
		}
		//printIslandMap();
		
		edge = new PriorityQueue<>(new Comparator<Edge>() {

			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.w, o2.w);
			}
		});
		//2. 섬에서 다른 섬까지의 다리 길이 구하기, 한 섬에서 다른 섬까지는 최솟값만 저장
		for(int i=1;i<=islandCnt;i++) {
			makeEdge(i);
		}
		
		//System.out.println(edge.toString());
		
		//3. 크루스칼 이용해서 모든 섬을 연결하는 최단거리 구하기
		parent = new int[islandCnt+1];
		for(int i=1;i<=islandCnt;i++) {
			parent[i] = i;
		}

		
		
		int answer = 0;
		while(!edge.isEmpty()) {
			Edge e = edge.poll();
			int a = e.a;
			int b = e.b;
			if(findParent(a) == findParent(b)) continue;
			
			makeUnion(a,b);
			answer+=e.w;
		}		
		
		boolean flag = true;
		int groupN = findParent(1);
		for(int i=2;i<=islandCnt;i++) {
			if(groupN != findParent(i)) {
				flag = false;
				break;
			}
		}
		
		if(flag) bw.write(answer+"");
		else bw.write("-1");
		
	    bw.close();
	
	}
	
	static class Edge implements Comparator<Edge>{
		int a;
		int b;
		int w;
		
		public Edge(int a, int b, int w) {
			super();
			this.a = a;
			this.b = b;
			this.w = w;
		}

		@Override
		public String toString() {
			return "Edge [a=" + a + ", b=" + b + ", w=" + w + "]";
		}

		@Override
		public int compare(Edge o1, Edge o2) {
			return Integer.compare(o1.w, o2.w);
		}
		
		
	}
	
/**
8 8
1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1
1 0 0 1 1 0 0 1
1 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1
 */
	
}
