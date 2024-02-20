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

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N;
    static char[][] map;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static boolean[][] visit;    
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<N && y>=0 && y<N) return true;
    	return false;
    }
    
    public static boolean isSameColor(char a, char b) {
    	if(a == b) return true;
    	if(a == 'R' && b == 'G') return true;
    	if(a == 'G' && b == 'R') return true;
    	return false;
    }
    
    public static void redGreenBlindnessDfs(int x, int y, char nowColor) {
    	visit[x][y] = true;
    	
    	for(int i=0;i<4;i++) {
    		int nx = x+dx[i];
    		int ny = y+dy[i];
    		
    		if(isInside(nx,ny) && !visit[nx][ny] && isSameColor(nowColor, map[nx][ny])) {
    			redGreenBlindnessDfs(nx,ny, map[nx][ny]);
    		}
    	}
    }
    
    public static void dfs(int x, int y, char nowColor) {
    	visit[x][y] = true;
    	
    	for(int i=0;i<4;i++) {
    		int nx = x+dx[i];
    		int ny = y+dy[i];
    		
    		if(isInside(nx,ny) && !visit[nx][ny] && nowColor == map[nx][ny]) {
    			dfs(nx,ny, map[nx][ny]);
    		}
    	}
    }

	public static void main(String[] args) throws Exception {
		
		int cnt, colorCnt;
		cnt = colorCnt = 0;
		N = Integer.parseInt(br.readLine());		
		
		map = new char[N][N];
		visit = new boolean[N][N];
		
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<N;j++) {
				map[i][j] = s.charAt(j);
			}
		}		
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(!visit[i][j]) { 
					dfs(i,j,map[i][j]);
					cnt++;
				}				
			}
		}

		visit = new boolean[N][N];
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(!visit[i][j]) { 
					redGreenBlindnessDfs(i,j,map[i][j]);
					colorCnt++;
				}	
			}
		}
		
		bw.write(cnt+" "+colorCnt);
		bw.close();
	}

}
