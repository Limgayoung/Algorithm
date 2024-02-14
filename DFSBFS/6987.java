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

public class Main {
    
    /**
     * 승/패 : 서로 상쇄
     * 무 : 같은 수 나와야 함
     */
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int win, lose, draw, total;
    static int[][] arr;    
    static int[] cnts = {5,4,3,2,1,0};
    static boolean flag;

    //현재 나라가 다른 나라들과 각각 경기한 후에 0이 되어야 함
    public static void dfs(int cnt, int nowIndex, int nextIndex) {   
    	//System.out.println("nowIndex: "+nowIndex+" nextIndex: "+nextIndex+" cnt: "+cnt);
        if(nowIndex>5 || nextIndex>6 || flag) return;         
        if(cnt == cnts[nowIndex]) {//경기 종료
            if(arr[nowIndex][0] == 0 && arr[nowIndex][1] == 0 && arr[nowIndex][2] == 0) {
                if(nowIndex == 4) {
                    flag = true;
                }
                dfs(0,nowIndex+1,nowIndex+2);
            }            
            return;            
        }
        
        //nowIndex, nextIndex와 경기
        //1. 이김
        if(arr[nowIndex][0] > 0 && arr[nextIndex][2] > 0) {
            arr[nowIndex][0]--;
            arr[nextIndex][2]--;
            dfs(cnt+1, nowIndex, nextIndex+1);
            arr[nowIndex][0]++;
            arr[nextIndex][2]++;
        }
        
        //2. 비김
        if(arr[nowIndex][1] > 0 && arr[nextIndex][1] > 0) {
            arr[nowIndex][1]--;
            arr[nextIndex][1]--;
            dfs(cnt+1, nowIndex, nextIndex+1);
            arr[nowIndex][1]++;
            arr[nextIndex][1]++;
        }
        
        //3. 짐
        if(arr[nowIndex][2] > 0 && arr[nextIndex][0] > 0) {
            arr[nowIndex][2]--;
            arr[nextIndex][0]--;
            dfs(cnt+1, nowIndex, nextIndex+1);
            arr[nowIndex][2]++;
            arr[nextIndex][0]++;
        }
                
    }


    public static void main(String[] args) throws Exception {                                                    
        
        for(int t=0;t<4;t++) {
            flag = false;
            boolean isGoodInput = true;
            win = 0;
            lose = 0;
            draw = 0;
            total = 0;
            
            arr = new int[6][3];
            st = new StringTokenizer(br.readLine(), " ");
            //입력받기
            for(int i=0;i<6;i++) {                
                arr[i][0] = Integer.parseInt(st.nextToken());
                arr[i][1] = Integer.parseInt(st.nextToken());
                arr[i][2] = Integer.parseInt(st.nextToken());
                
                int w = arr[i][0];
                int d = arr[i][1];
                int l = arr[i][2];

                total += (w+d+l);
                if(w+d+l!=5) {
                    isGoodInput = false;                    
                    break;
                }                
            }
            
            if(total != 30) isGoodInput = false;
            
            if(isGoodInput) dfs(0,0,1);                        
            if(flag) bw.write(1+" ");
            else bw.write(0+" ");
        }
        
        bw.close();
    }             
}

/*
3 3 3

*/
