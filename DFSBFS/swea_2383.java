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


public class Solution {
	
	/**
	 * 1. 사람 위치, 계단 위치 저장
	 * 2. 각 사람 위치부터 해당 계단까지 걸리는 시간 계산
	 * 3. 계단 선택하는 모든 조합 구하기
	 * 4. 각 조합에서 걸리는 시간 계산 (구현)
	 * 		
	 */
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int K, W, H;

    static int N, M;
    static int[][] map;
    static ArrayList<Point> people;
    static ArrayList<Stair> stair;
    static int[][] dist;
    static int[] selectStair;
    static int minTime;
    static int peopleNum;
    
    public static void calDist() { //각 사람~계단 거리 구하기
    	for(int i=0;i<people.size();i++) {
    		for(int j=0;j<2;j++) {
    			dist[i][j] = Math.abs(people.get(i).x - stair.get(j).x) + Math.abs(people.get(i).y - stair.get(j).y);
    		}
    	}
    }
    
    public static int downStair(ArrayList<Integer> s, int length) { //계단 내려가기
    	Queue<Integer> q = new LinkedList<>(); //들어온 시점 저장
    	if(s.isEmpty()) return 0;
    	int time = s.get(0);
    	
    	for(int i=0;i<s.size();i++) {
    		if(q.size()<3) { //도착하고 1분 뒤에 계단 들어가기 가능
    			if(time < s.get(i)+1) {
    				time = s.get(i)+1;
    			}
    			q.add(time);
    		}
    		else { //맨 앞의 사람이 나가야 들어가기 가능
    			if(time >= q.peek()+length) {
    				q.poll();    				
    			}
    			else {
    				time = q.peek()+length;
    				q.poll();
    			}
    			i--;
    			continue;
    		}
    	}
    	
    	while(!q.isEmpty()) {
    		time = q.poll()+length;
    	}
    	//System.out.println("time: "+time);
    	return time;
    }
    
    /**
     * 1. 계단 입구까지 이동 시간 -> dist
     * 2. 계단 내려가는 시간 -> stair.length
     * 계단은 동시에 3명까지 오를 수 있다. -> queue 사용해야 함
     * 
     */
    public static int calTime() {
    	//selectStair를 보면서 각 계단의 이동거리 분리 후 각각 오름차순 정렬
    	ArrayList<Integer> s1, s2;
    	s1 = new ArrayList<>();
    	s2 = new ArrayList<>();
    	for(int i=0;i<peopleNum;i++) {
    		if(selectStair[i] == 0) {
    			s1.add(dist[i][0]);
    		}
    		else {
    			s2.add(dist[i][1]);
    		}
    	}
    	//System.out.println(Arrays.toString(selectStair));
    	
    	s1.sort((a,b) -> Integer.compare(a, b));
    	s2.sort((a,b) -> Integer.compare(a, b));
    	    	
    	//System.out.println(s1.toString());
    	//System.out.println(s2.toString());
    	//System.out.println();
    	
    	//계단 내려가기
    	int time = Math.max(downStair(s1, stair.get(0).length), downStair(s2, stair.get(1).length));
    	//System.out.println("time: "+time);
    	return time;
    	
//    	return 0;
    }
    
    public static void dfs(int index) { //사람들이 계단 이용하는 조합 구하기
//    	System.out.println("index: "+index);
    	if(index == peopleNum) {
    		minTime = Math.min(minTime, calTime());
    		return;
    	}    
    	
    	selectStair[index] = 0;
    	dfs(index+1);
    	selectStair[index] = 1;
    	dfs(index+1);
    	
//    	for(int i=0;i<2;i++) { //계단
//    		selectStair[index] = i;
//    		dfs(index+1);
//    	}
    }
    
    public static void main(String[] args) throws Exception {    	
    	
    	int T = Integer.parseInt(br.readLine());
//    	int T = 1;
    	
    	for(int t=1;t<=T;t++) {
    		N = Integer.parseInt(br.readLine());
    		
    		map = new int[N][N];
    		people = new ArrayList<>();
    		stair = new ArrayList<>();
    		
    		for(int i=0;i<N;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			for(int j=0;j<N;j++) {
    				map[i][j] = Integer.parseInt(st.nextToken());
    				if(map[i][j] == 1) {
    					people.add(new Point(i,j));
    				}
    				else if(map[i][j] >=2) {//계단
    					stair.add(new Stair(i,j,map[i][j]));
    				}
    			}
    		}
    		peopleNum = people.size();
    		
    		dist = new int[peopleNum][2];
    		selectStair = new int[peopleNum];
    		minTime = 987654321;

    		calDist();
    		dfs(0);
    		bw.write("#"+t+" "+minTime+"\n");
    	}


        bw.close();
    }    
    
    static class Stair{
    	int x;
    	int y;
    	int length;
    	
		public Stair(int x, int y, int length) {
			super();
			this.x = x;
			this.y = y;
			this.length = length;
		}
		
		@Override
		public String toString() {
			return "Stair [x=" + x + ", y=" + y + ", length=" + length + "]";
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


 */
