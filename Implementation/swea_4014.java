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

각 행/열에 활주로 설치 가능한지 검사 -> 가능하면 cnt++

높이가 바뀌는 곳부터 경사로 설치
	바뀌는 높이의 차이는 1이어야 함
	X개만큼 높이가 같아야 함
	X가 범위를 벗어나면 안됨
	설치하는 시점부터 높이는 바뀌는 높이로 저장(이것과 비교)
	경사로 설치 시점부터 X는 X-1, X가 0이 되면 해당 경사로는 제대로 완성한 것
	
	높아짐 : 그전까지 같은 높이 개수 > X면 설치 가능
	낮아짐 : 지금부터 개수 X개면 설치 가능

*/

public class swea_4014 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int N, X;
	static int[][] map;
	
	public static boolean canBuild(int n, int dir) { //dir이 0이면 행, 1이면 열

		int[] arr = new int[N];		
		
		if(dir == 0) {
			for(int j=0;j<N;j++) {
				arr[j] = map[n][j];
			}
		}
		else {
			for(int i=0;i<N;i++) {
				arr[i] = map[i][n];
			}
		}
		
		//System.out.println(Arrays.toString(arr));
		
		int nowHeight = arr[0];
		int x = 0;
		int cnt = 1;
		for(int i=1;i<N;i++) {
			if(x == 0 && arr[i] != nowHeight) { //경사로 시작 위치
				int diff = nowHeight - arr[i];
				if(Math.abs(diff) > 1) return false; //차이가 1 이상 나면 안됨
				if(diff == -1) { // 높아짐
					//System.out.println(cnt);
					if(cnt < X) return false;
					nowHeight = arr[i];
					cnt = 1;
				}
				else { //낮아짐
					x = X-1;
					nowHeight = arr[i];
					cnt = 0;
				}
			}
			else if(x>0) { //경사로 설치 중
				if(arr[i] != nowHeight) return false; //설치 중에 높이가 다르면 안됨
				x--;
			}
			else if(x==0 && arr[i] == nowHeight){
				cnt++;
			}
			else return false;
		}
		if(x>0) { //경사로가 범위를 벗어남
			return false;
		}
//		System.out.println(n+" "+dir);
		return true;
	}

	public static void main(String[] args) throws Exception {					
		int T = Integer.parseInt(br.readLine());
//		int T = 1;
		
		for(int t=1;t<=T;t++) {
			st = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			
			map = new int[N][N];
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int answer = 0;
			
			for(int i=0;i<N;i++) { //각 행/열 검사
//				System.out.println(i+" 검사 시작!!=========");
				if(canBuild(i,0)) answer++;
//				System.out.println("----------------");
				if(canBuild(i,1)) answer++;
//				System.out.println("----------------");
			}
			
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
