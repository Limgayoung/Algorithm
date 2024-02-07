package com.day2.perm;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class sweq {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N,M;    
    static int[][] arr;

    static void upDownReversal() { //1번: 상하 반전
    	//아래쪽을 위로 옮기기
    	int [][] result = new int[N][M];
    	
    	int k=0;
    	for(int i=N-1;i>=0;i--) {
    		for(int j=0;j<M;j++) {
    			result[k][j] = arr[i][j];
    		}
    		k++;
    	}
    	arr = result;
    }

    static void leftRightReversal() { //2번: 좌우 반전
    	//오른쪽을 왼쪽으로 옮기기
    	int [][] result = new int[N][M];
    	
    	int k=0;
    	for(int i=0;i<N;i++) {
    		k=0;
    		for(int j=M-1;j>=0;j--) {
    			result[i][k] = arr[i][j];
    			k++;
    		}    		
    	}
    	arr = result;
    }
    
    static void rightRotation() { //3번: 오른쪽 90도 회전
    	//왼쪽 밑에서부터 읽어서 왼쪽 위에부터 붙이기
    	//N,M 바뀌어야 함
    	int [][] result = new int[M][N];
    	
    	int ri = 0;
    	int rj = 0;
    	
    	for(int j=0;j<M;j++) {
    		rj = 0;
    		for(int i=N-1;i>=0;i--) {
    			result[ri][rj] = arr[i][j];
    			rj++;
    		}
    		ri++;
    	}    	

    	int t = N;
    	N = M;
    	M = t;
    	
    	arr = result;
    }
    
    static void leftRotation() { //4번: 왼쪽 90도 회전
    	//오른쪽 위에부터 읽어서 왼쪽 위에 붙이기
    	//N,M 바뀌어야 함
    	int [][] result = new int[M][N];
    	
    	int ri = 0;
    	int rj = 0;
    	
    	for(int j=M-1;j>=0;j--) {
    		rj = 0;
    		for(int i=0;i<N;i++) {
    			result[ri][rj] = arr[i][j];
    			rj++;
    		}
    		ri++;
    	}    	

    	int t = N;
    	N = M;
    	M = t;
    	
    	arr = result;
    }
    
    static int findPart(int i,int j) {
    	if(i<N/2 && j<M/2) return 1;
    	else if(i<N/2 && j>=M/2) return 2;
    	else if(i>=N/2 && j<M/2) return 4;
    	else return 3;
    }
    
    static void rightMovePartialArr() { //5번: 4조각으로 나눠서 시계 방향으로 이동
    	int [][] result = new int[N][M];

    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			int part = findPart(i,j);
    			if(part == 1) {
    				result[i][j+M/2] = arr[i][j];
    			} else if(part == 2) {
    				result[i+N/2][j] = arr[i][j];
    			} else if(part == 3) {
    				result[i][j-M/2] = arr[i][j];
    			} else if(part == 4) {
    				result[i-N/2][j] = arr[i][j];
    			}
    		}
    	}
    	
    	arr = result;
    }

    static void leftMovePartialArr() { //6번: 4조각으로 나눠서 반시계 방향으로 이동
    	int [][] result = new int[N][M];

    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			int part = findPart(i,j);
    			if(part == 1) {
    				result[i+N/2][j] = arr[i][j];
    			} else if(part == 2) {
    				result[i][j-M/2] = arr[i][j];
    			} else if(part == 3) {
    				result[i-N/2][j] = arr[i][j];
    			} else if(part == 4) {
    				result[i][j+M/2] = arr[i][j];
    			}
    		}
    	}
    	
    	arr = result;
    }
    
    static void runOper(int oper) {
    	if(oper == 1) {
    		upDownReversal();
    	} else if(oper == 2) {
    		leftRightReversal();
    	} else if(oper == 3) {
    		rightRotation();
    	} else if(oper == 4) {
    		leftRotation();
    	} else if(oper == 5) {
    		rightMovePartialArr();
    	} else if(oper == 6) {
    		leftMovePartialArr();
    	}
    }
    
    public static void main(String[] args) throws Exception {
    	st = new StringTokenizer(br.readLine(), " ");
    	int R;
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	R = Integer.parseInt(st.nextToken());
    	
    	arr = new int[N][M];
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=0;j<M;j++) {
    			arr[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	    
    	int oper;
    	
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=0;i<R;i++) {    	
    		oper = Integer.parseInt(st.nextToken());
    		runOper(oper);
    	}
    	
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			bw.write(arr[i][j]+" ");
    		}
    		bw.write("\n");
    	}

        bw.close();
    }             
    
    

    
}

/*

*/
