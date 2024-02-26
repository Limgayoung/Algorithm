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

/**
 * 궁수는 맨 밑에 3명 배치 가능함
 * 궁수 배치 조합에 따라 게임 결과 달라짐 -> 이때 제거 가능한 최대 수
 * 궁수가 공격하는 적은 가장 가까운 적, 같은 거리일 때 왼쪽 적 공격
 */

/**
 * 궁수 조합하기 -> dfs
 * 궁수 3명 배치 완료되면 게임 진행 (게임은 map copy해서 진행)
 * 	게임에서 궁수가 제거할 적: 가장 가까이 있는 적 -> 15*15 다 해보고 최소값 가지는 적으로 제거
 */

public class Code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N,M,D;
    static int[][] map;
    static int[][] gameMap;
    static int[] archer = new int[3];
    static int maxNum = 0;
    
    public static Point findNear(int x, int y, int nowN) { //궁수 위치, 현재 맨 끝
    	int minDist = 987654321;
    	Point e = new Point(16,16);
    	for(int i=nowN;i>=0;i--) {
    		for(int j=0;j<M;j++) { //같은 거리면 왼쪽
    			if(gameMap[i][j] == 0) continue;
    			int nowDist = Math.abs(x-i)+Math.abs(y-j);
    			if(nowDist > D) continue;
    			if(minDist > nowDist) {
    				minDist = nowDist;
    				e.x = i;
    				e.y = j;
    			}
    			else if(minDist == nowDist) {
    				if(e.y > j) {
    					e.x = i;
        				e.y = j;
    				}
    			}
    		}
    	}
    	return e;
    }
    
    public static int playGame() {
    	int cnt = 0;
    	Point[] eList = new Point[3];
    	int eIndex = 0;
    	for(int i=N-1;i>=0;i--) { //한 칸씩 올라감
    		eList = new Point[3];
    		eIndex = 0;
    		for(int j=0;j<3;j++) {
    			Point e = findNear(i+1, archer[j], i);
    			if(e.x == 16 && e.y == 16) continue; //D 안에 제거 가능한 적 없음
    			eList[eIndex] = new Point(e.x, e.y);
    			eIndex++;
    		}
        	for(int j=0;j<eIndex;j++) {
        		if(gameMap[eList[j].x][eList[j].y] == 1) {
        			gameMap[eList[j].x][eList[j].y] = 0; 
        			cnt++;
        		}
        	}
    	}
    	
    	return cnt;
    }

    public static void makePer(int index, int cnt) {
    	if(cnt == 3) { //게임 진행
    		gameMap = new int[N][M];
    		for(int i=0;i<N;i++) {
    			for(int j=0;j<M;j++) {
    				gameMap[i][j] = map[i][j];
    			}
    		}
    		
    		int nowNum = playGame();
    		maxNum = Math.max(nowNum, maxNum);
    		
    		return;
    	}
    	
    	for(int i=index;i<M;i++) {
    		archer[cnt] = i;
    		makePer(i+1, cnt+1);
    	}
    	
    }
    public static void main(String[] args) throws Exception {
    	st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        
        for(int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=0;j<M;j++) {
        		map[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        
        makePer(0,0);
        
        bw.write(""+maxNum);	

        bw.close();
    }    

}
