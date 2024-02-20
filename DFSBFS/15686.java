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
 * 
 */

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N, M;
    static int[][] map;    
    static ArrayList<Point> home = new ArrayList<>();
    static ArrayList<Point> chicken = new ArrayList<>();
    static int[] chickenDist;
    static boolean[] isClose;
    static int answer = 1000000;
    
    public static void printHome() {
    	for(int i=0;i<home.size();i++) {
    		System.out.println(home.get(i).x + " "+home.get(i).y);
    	}
    	System.out.println();
    }
    public static void printChicken() {
    	for(int i=0;i<chicken.size();i++) {
    		System.out.println(chicken.get(i).x + " "+chicken.get(i).y);
    	}
    	System.out.println();
    }
    
    public static int calChickenDist() {
    	int sum = 0;
    	for(int i=0;i<home.size();i++) {
    		int index = 0;
    		for(int j=0;j<chicken.size();j++) {
    			if(isClose[j]) continue;
    			int nowDist = Math.abs(home.get(i).x - chicken.get(j).x) + Math.abs(home.get(i).y - chicken.get(j).y);
    			//System.out.println("nowDist: "+nowDist);
    			if(chickenDist[i] > nowDist) {
    				chickenDist[i] = nowDist;
    				index = j;
    			}
    		}
    		sum+= chickenDist[i];
    		if(sum >= answer) break;
    	}
    	//System.out.println("sum: "+sum);
    	return sum;
    }
    
    public static void dfs(int cnt, int index) {
    	if(cnt == chicken.size() - M) { //M개를 제외하고 모두 폐업
    		//치킨 거리 계산, min 갱신
    		Arrays.fill(chickenDist, 1000);
    		int nowDist = calChickenDist();
    		answer= Math.min(nowDist, answer);
    		return;
    	}
    	
    	for(int i=index;i<chicken.size();i++) { //하나씩 폐업해보기
    		if(!isClose[i]) {
    			isClose[i] = true;
    			dfs(cnt+1, i+1);
    			isClose[i] = false;
    		}    		
    	}
    }
    
    public static void openDfs(int cnt, int index) {
    	if(cnt == M) { //M개 설치
    		//치킨 거리 계산, min 갱신
    		Arrays.fill(chickenDist, 1000);
    		int nowDist = calChickenDist();
    		answer= Math.min(nowDist, answer);
    		return;
    	}
    	
    	for(int i=index;i<chicken.size();i++) { //하나씩 설치해보기
    		if(isClose[i]) {
    			isClose[i] = false;
    			openDfs(cnt+1, i+1);
    			isClose[i] = true;
    		}    		
    	}
    }

	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new int[N+1][N+1];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=1;j<=N;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) {
					home.add(new Point(i,j));
				} else if(map[i][j] == 2) {
					chicken.add(new Point(i,j));
				}				
			}
		}
		
		chickenDist = new int[home.size()];
		isClose = new boolean[chicken.size()];
		Arrays.fill(chickenDist, 1000);
		calChickenDist();
		
		//dfs(0);
		if(chicken.size() - M > M) { //M개 폐업보다 M개 설치가 더 좋은 경우
			Arrays.fill(isClose, true);
			openDfs(0, 0);
		}
		else { //폐업
			dfs(0, 0);
		}	
		
		bw.write(answer+"");
		bw.close();
	}	

}
