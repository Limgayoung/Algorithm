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
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class sweq {
	
	/**
	 * 4구간으로 나눠서 풀이
	 */
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, r, c;
    static int num = 0;

    public static void main(String[] args) throws Exception {    	
    	    	
    	st = new StringTokenizer(br.readLine(), " ");
    	    	
    	N = Integer.parseInt(st.nextToken());
    	r = Integer.parseInt(st.nextToken());
    	c = Integer.parseInt(st.nextToken());
    	
    	Point start, end;
    	
    	int size = (int)Math.pow(2, N);
    	
    	start = new Point(0,0);
    	end = new Point(size-1, size-1);   
    	
    	int s,e;
    	s = 0;
    	e = size * size -1;
    	int nowSize = size*size;
    	int nowNum;

    	while(start.x <= end.x && start.y <= end.y) {
    		int midx = (start.x + end.x)/2;
    		int midy = (start.y + end.y)/2;    	

    		nowSize /= 4;

    		//현재 위치: mid, nowNum도 mid에 있는 num이어야 함
    		if(s == e) nowNum = s;
    		else nowNum = s + (nowSize-1);
    		if(midx == r && midy == c) {
    			bw.write(nowNum+"");
    			break;
    		}
    		else if(r <= midx && c <= midy) { //1
    			end.x = midx;
    			end.y = midy;
    			e = s+nowSize-1;    			    			
    		}
    		else if(r <= midx && c > midy) { //2
    			start.y = midy+1;
    			end.x = midx;
    			s = s+nowSize;
    			e = e-(nowSize*2);
    		}
    		else if(r > midx && c <= midy) { //3
    			start.x = midx+1;
    			end.y = midy;
    			s = s+(nowSize*2);
    			e = e-(nowSize);
    		}
    		else if(r > midx && c > midy) { //4
    			start.x = midx+1;
    			start.y = midy+1;
    			s = s+(nowSize*3);
    		}
    		
    		
    	}
    	
        bw.close();
    }             

}

/*
3 3 3

*/
