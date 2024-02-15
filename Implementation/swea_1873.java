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

public class Solution {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int H,W;
    static char[][] map;
    static Point p;
    static int nowDir;
    
    //상하좌우
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    
    public static void printMap() throws Exception {
    	for(int i=0;i<H;i++) {
    		for(int j=0;j<W;j++) {
    			bw.write(map[i][j]+"");
    		}
    		bw.write("\n");
    	}
    }
    
    public static boolean isTank(char c) {
    	if(c == '^' || c == 'v' || c == '<' || c == '>') return true;
    	return false;
    }
    
    public static int nowOperToInt(char oper) {
    	if(oper == 'U') return 0;
    	else if(oper == 'D') return 1;
    	else if(oper == 'L') return 2;
    	else return 3;
    }    
    
    public static boolean isInside(int x, int y) {
    	if(x>=0 && x<H && y>=0 && y<W) return true;
    	return false;
    }    
    
    public static char nowTankShape(int dir) {
    	if(dir == 0) return '^';
    	else if(dir == 1) return 'v';
    	else if(dir == 2) return '<';
    	else return '>';
    }
    
    public static int nowTankDir(char dir) {
    	if(dir ==  '^') return 0;
    	else if(dir == 'v') return 1;
    	else if(dir == '<') return 2;
    	else return 3;
    }
    
    public static void shoot() {
    	int dir = nowTankDir(map[p.x][p.y]);
    	
    	int x = p.x;
    	int y = p.y;
    	
    	while(true) {
    		int nx = x + dx[dir];
    		int ny = y + dy[dir];
    		
    		if(!isInside(nx,ny)) break;
    		char nextChar = map[nx][ny];
    		if(nextChar == '#') break;
    		if(nextChar == '*') { //파괴 가능
    			map[nx][ny] = '.';
    			break;
    		}
    		x = nx;
    		y = ny;
    	}
    	
    }
    
    public static void runOper(char oper) {    	
    	if(oper == 'S') {
    		shoot();
    	}
    	else { //전차 움직이는 명령
    		int dir = nowOperToInt(oper);
    		
    		int nx = p.x + dx[dir];
    		int ny = p.y + dy[dir];
    		
    		if(isInside(nx,ny)) {
    			if(map[nx][ny] == '.') { //이동 가능
    				map[p.x][p.y] = '.';
        			map[nx][ny] = nowTankShape(dir);
        			p.x = nx;
        			p.y = ny;
    			}
    			else { //방향 전환만 가능
    				map[p.x][p.y] = nowTankShape(dir);
    			}
    		}
    		else {
    			map[p.x][p.y] = nowTankShape(dir);
    		}
    		
    		
    	}
    }

    public static void main(String[] args) throws Exception {    	    	    	    	    	    	    
    	
    	int T = Integer.parseInt(br.readLine());
//    	int T = 1;
    	  
    	for(int t=1;t<=T;t++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		
    		nowDir = -1; 
    		H = Integer.parseInt(st.nextToken());
    		W = Integer.parseInt(st.nextToken());
    		
    		map = new char[H][W];
    		
    		for(int i=0;i<H;i++) {
    			String s = br.readLine();
    			for(int j=0;j<W;j++) {
    				map[i][j] = s.charAt(j);
    				if(isTank(map[i][j])) {
    					p = new Point(i,j);
    				}
    			}
    		}
    		
    		int N = Integer.parseInt(br.readLine());
    		String s = br.readLine();
    		for(int i=0;i<s.length();i++) {
    			char oper = s.charAt(i);    	
    			runOper(oper);
    		}    		
    		
    		//printMap();
	    	bw.write("#"+t+" ");
	    	printMap();
    	}
        bw.close();
    }         

}

/*


*/
