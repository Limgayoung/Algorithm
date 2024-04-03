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
톱니바퀴를 돌렸을 때 맞닿은 톱니바퀴들의 자석이 다르면 반대 방향으로 회전, 같으면 멈추기
N극이 0, S극이 1
시계방향이 1 반시계 방향이 -1 -> 1일 때 i-1, -1일 때 i+1

1. 톱니바퀴 배열 만들기
	각 톱니바퀴마다 빨간 화살표 위치를 저장 - i가 화살표, i+2가 오른쪽, i+6이 왼쪽
	돌릴 때마다 화살표 위치 i를 변경할 것
2. 톱니바퀴 돌리기
	왼쪽, 오른쪽 보면서 돌릴 톱니바퀴, 방향 ArrayList에 저장


	방향대로 한 칸 돌리기
3. 붙어있는 톱니바퀴 확인
	해당 톱니바퀴 ~ 왼쪽 / 톱니바퀴 ~ 오른쪽 확인
	왼쪽 톱니바퀴라면 돌아가지 않을 때까지 왼쪽으로 이동 (오른쪽도 동일)
	이때 -1 방향으로 돌렸다면 좌/우 톱니바퀴는 1 방향으로 돌려야함
	맞닿은 방향이 반대 방향이라면 톱니바퀴 돌아가고 해당 톱니바퀴의 왼/오른쪽 톱니바퀴 확인 반복
4. 톱니바퀴 점수 계산	
*/

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int[][] gear;
	static int[] gearIndex; //빨간 화살표 위치
	static ArrayList<Point> turnGearNum; //돌릴 톱니바퀴 정보 번호, 방향
	
	public static void printGear() {
		//System.out.println("=====================");
		for(int i=0;i<4;i++) {
			System.out.print(gearIndex[i]+" ");
		}
		System.out.println();
		System.out.println("====================");
	}
	
	public static void findTrunGear(int index, int dir, int turnDir){
		int d;
		int nowCheckIndex;
		int nextCheckIndex;
		if(dir == -1) { //왼쪽으로
			nowCheckIndex = 6;
			nextCheckIndex = 2;
		}
		else { //오른쪽으로
			nowCheckIndex = 2;
			nextCheckIndex = 6;
		}
		
		int i = index;
		int nowGear = i;
		int nowDir = -turnDir;
		while(true) {
			int nextGear = nowGear+dir;
			if(nextGear<0 || nextGear>=4) break; //범위 벗어남
			
			//같으면 멈추기
			if(gear[nowGear][(gearIndex[nowGear]+nowCheckIndex)%8] == gear[nextGear][(gearIndex[nextGear]+nextCheckIndex)%8]) break;
			
			//다르면 돌려야함
			turnGearNum.add(new Point(nextGear, nowDir));
			
			nowGear = nextGear;			
			nowDir = -nowDir;
		}
	}

	public static void main(String[] args) throws Exception {					
		int T = Integer.parseInt(br.readLine());
		//int T = 1;
		for(int t=1;t<=T;t++) {
			int K = Integer.parseInt(br.readLine());
			
			gear = new int[4][8];
			gearIndex = new int[4]; //처음에는 모두 0
			
			// 1. 톱니바퀴 배열 만들기
			for(int i=0;i<4;i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for(int j=0;j<8;j++) {
					gear[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			// 2. 톱니바퀴 돌리기
			for(int k=0;k<K;k++) {
				st = new StringTokenizer(br.readLine(), " ");
				int num = Integer.parseInt(st.nextToken())-1;				
				int dir = Integer.parseInt(st.nextToken());
				
				//돌릴 톱니바퀴 찾기
				turnGearNum = new ArrayList<>();
				findTrunGear(num, 1, dir); //오른쪽
				findTrunGear(num, -1, dir); //왼쪽
				turnGearNum.add(new Point(num, dir));
				
				//돌리기
				for(int i=0;i<turnGearNum.size();i++) {
					int gearNum = turnGearNum.get(i).x;
					int turnDir = turnGearNum.get(i).y;
					if(gearIndex[gearNum]-turnDir<0) gearIndex[gearNum]=7;
					else gearIndex[gearNum] = (gearIndex[gearNum]-turnDir)%8;
				}
				
				//printGear();
			}
			
			// 3. 톱니바퀴 점수 계산
			int answer = 0;
			for(int i=0;i<4;i++) {
				answer += (Math.pow(2, i)*gear[i][gearIndex[i]]);
			}			
			
			bw.write("#"+t+" "+answer+"\n");
			
		}
		
		
	    bw.close();
	}

/*


1
6
6
1 5
3 4
5 4
4 2
4 6
5 2

 */
	
}
