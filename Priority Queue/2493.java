import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Swea {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;     
    
    static class Info implements Comparable<Info>{
    	int index;
    	int height;    	    	
    	
		public Info(int index, int height) {
			this.index = index;
			this.height = height;
		}

		@Override
		public int compareTo(Info o) {
			if(this.height > o.height) return 1;
			return -1;
		}
    }

    public static void main(String[] args) throws Exception {

    	N = Integer.parseInt(br.readLine());
    	
    	st = new StringTokenizer(br.readLine(), " ");
    	
    	int[] tops = new int[N+1];
    	int[] result = new int[N+1];
    	for(int i=1;i<=N;i++) {
    		tops[i] = Integer.parseInt(st.nextToken()); 
    	}

    	//왼쪽에 자신보다 큰 탑이 나오기 전까지 수신 불가능함
    	//정렬 할 수 없음
    	
    	PriorityQueue<Info> pq = new PriorityQueue<>();
    	
    	for(int i=N;i>=1;i--) {
    			
    		int nowHeight = tops[i];
    		
    		while(true) {
    			if(!pq.isEmpty() && pq.peek().height <= nowHeight) {
    				Info info = pq.poll();
    				result[info.index] = i;
    			}
    			else break;
    		}
    		
    		//현재 것과 앞의 것 비교    	
    		if(i == 1) break;
    		if(nowHeight <= tops[i-1]) {
    			result[i] = i-1;
    		}
    		else {
    			pq.add(new Info(i,nowHeight));
    		}
    	}
	
    	for(int i=1;i<=N;i++) {
    		bw.write(result[i]+" ");
    	}
   
    	bw.close();
    }             
    
}

/*

*/
