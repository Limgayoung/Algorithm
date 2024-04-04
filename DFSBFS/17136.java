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

1. init
	1인 곳을 list에 저장하기
	색종이 배열 만들기 [5], 초기 값은 모두 5, i+1이 색종이 크기
2. dfs
	tempMap, 현재 검사할 1인 곳 index, 남은 1인 곳 개수, 사용한 색종이 수를 인자로
	1인 곳이 없을 때 minCnt 갱신
	해당 i인 곳에 가능 한 경우 - 1~5 색종이 붙이기 or 안붙이기
	색종이 붙일 때에는 범위 안인지, 다른 색종이와 겹치는지, 0인 칸과 겹치는지 확인 필요
	색종이 붙인 곳은 2로 표기 (0,1과 구분이 필요하기 때문에)

*/

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static ArrayList<Point> list = new ArrayList<>();	
	static int[] colorPaper = {5,5,5,5,5};
	static int minCnt = 987654321;
	
	
	//해당 m의 p 위치를 왼쪽 상단 끝으로 하는 size 크기의 색종이 붙일 수 있는지 확인
	public static boolean canUse(int[][] m, Point p, int size) {
		//범위 안인지, 다른 색종이와 겹치는지, 0인 칸과 겹치는지 확인 필요
		
		for(int i=p.x;i<p.x+size;i++) {
			for(int j=p.y;j<p.y+size;j++) {
				if(i<0 || i>=10 || j<0 || j>=10) return false;
				if(m[i][j] == 0 || m[i][j] == 2) return false;
			}
		}
				
		return true;
	}
	
	public static int[][] copyMap(int[][] m){
		int[][] result = new int[10][10];
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				result[i][j] = m[i][j];
			}
		}
		return result;
	}
	
	public static int attach(int [][]m, Point p, int size) {
		int cnt = 0;
		for(int i=p.x;i<p.x+size;i++) {
			for(int j=p.y;j<p.y+size;j++) {
				if(m[i][j] == 1) {
					m[i][j] = 2;
					cnt++;
				}
				
			}
		}
		return cnt;
	}
	
	public static void dfs(int[][] m, int index, int remainCnt, int useCnt) {
		//System.out.println(index);
		if(remainCnt == 0) {
			minCnt = Math.min(minCnt, useCnt);
			return;
		}
		if(index == list.size()) return;
		if(minCnt < useCnt) return;
		
		//이미 붙인 곳이면 바로 다음으로 넘어가기
		if(m[list.get(index).x][list.get(index).y] == 2) {
			dfs(m,index+1, remainCnt, useCnt);
		}
		else {
		//색종이 붙이기
			for(int i=4;i>=0;i--) {
				if(m[list.get(index).x][list.get(index).y] == 2) break;
				
				if(colorPaper[i] == 0) continue; //다씀
				
				//해당 map에 붙일 수 있는지  확인			
				if(!canUse(m,list.get(index), i+1)) continue;
				
				//m을 copy해서 붙이기
				int[][] copyM = copyMap(m);
				int attachCnt = attach(copyM, list.get(index), i+1);
				colorPaper[i]--;
				dfs(copyM, index+1, remainCnt-attachCnt, useCnt+1);
				colorPaper[i]++;			
			}
		}
	}
	
	
	public static void main(String[] args) throws Exception {					
		
		int[][] map = new int[10][10];
		
		//input
		for(int i=0;i<10;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<10;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) {
					list.add(new Point(i,j));
				}
			}
		}
		
		if(list.size() == 0) {
			bw.write("0");
			bw.close();
			return;
		}
		
		dfs(map, 0,list.size(), 0);
		
		if(minCnt == 987654321) bw.write("-1");
		else bw.write(minCnt+"");
		
	    bw.close();
	}

/*


 */
	
}
