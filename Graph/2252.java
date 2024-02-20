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

/**
 * 
 */

public class code {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N, M;
    static int[] in;
    static ArrayList<Integer> G[];
    static Queue<Integer> q = new LinkedList<>();

	public static void main(String[] args) throws Exception {
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		in = new int[N+1];
		G = new ArrayList[N+1];
		for(int i=0;i<=N;i++) {
			G[i] = new ArrayList<Integer>();
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			G[a].add(b);
			in[b]++;
		}
		
		for(int i=1;i<=N;i++) {
			if(in[i] == 0) {
				q.offer(i);
			}
		}
		
		while(!q.isEmpty()) {
			int nowNode = q.poll();
			bw.write(nowNode+" ");
			for(int i=0;i<G[nowNode].size();i++) {
				int nextNode = G[nowNode].get(i);
				
				in[nextNode]--;
				
				if(in[nextNode] == 0) {
					q.add(nextNode);
				}
			}
		}
		
		bw.write("\n");
		bw.close();
	}	

}
