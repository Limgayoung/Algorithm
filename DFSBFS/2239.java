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

/**
위부터 set 3개 (칸,행,열) 체크해서 없는 숫자 집어넣고 set에 체킹

 */ 

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int[][] sudoku = new int[9][9];
	static Set<Integer>[] kan = new Set[9];
	static Set<Integer>[] row = new Set[9];
	static Set<Integer>[] col = new Set[9];
	static boolean flag = false;
	
	public static void printSudoku() {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				System.out.print(sudoku[i][j]);				
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static void dfs(int x, int y) {
		if(x == 9) {
			//printSudoku();
			flag = true;
			return;
		}
		if(flag) return;
		
		//System.out.println(x+" "+y);
		
		if(sudoku[x][y] == 0) { //채워야 함
			int kanIndex = (x/3)*3 + (y/3);
			for(int i=1;i<=9;i++) {
				if(!row[x].contains(i) && !col[y].contains(i) && !kan[kanIndex].contains(i)) {
					sudoku[x][y] = i;
					row[x].add(i);
					col[y].add(i);
					kan[kanIndex].add(i);
					if(y == 8) dfs(x+1, 0);
					else dfs(x,y+1);
					if(flag) break;
					sudoku[x][y] = 0;
					row[x].remove(i);
					col[y].remove(i);
					kan[kanIndex].remove(i);
				}
			}	
		}
		else { //이미 채워져 있는 부분
			if(y == 8) dfs(x+1, 0);
			else dfs(x,y+1);
		}
	
		
	}
	
	public static void main(String[] args) throws Exception {
				
		for(int i=0;i<9;i++) {
			kan[i] = new HashSet<Integer>();
			row[i] = new HashSet<Integer>();
			col[i] = new HashSet<Integer>();
		}
		
		for(int i=0;i<9;i++) {
			String str = br.readLine();
			
			for(int j=0;j<9;j++) {
				sudoku[i][j] = str.charAt(j)-'0';
				
				if(sudoku[i][j] != 0) {
					row[i].add(sudoku[i][j]);
					col[j].add(sudoku[i][j]);
					
					int kanIndex = (i/3)*3 + (j/3);
					kan[kanIndex].add(sudoku[i][j]);
				}
			}			
		}
	
		dfs(0,0);
		
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				bw.write(sudoku[i][j]+"");
			}
			bw.write("\n");
		}
		    
	    bw.close();
	
	}
	
	
}
