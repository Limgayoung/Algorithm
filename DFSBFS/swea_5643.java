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
1. in, out 그래프 만들기
	나가는 애들 저장 (원래 그래프) / 들어오는 애들 저장 (반대 그래프) 그래프 만들기
2. in, out 구하기
	모든 노드마다 dfs 돌리기
	탐색  횟수가 해당 노드의 in/out 개수
	out -> out 개수   in -> in 개수
3. in+out-1=1 == N인 노드 개수 세기
	해당 노드는 자신의 키가 몇 번째인지 알 수 있음	
*/

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int N,M;
	//나가는 애들 저장(원래 그래프), 들어오는 애들 저장 (반대 그래프)
	static List<Integer> outG[], inG[];
	static int[] out, in;
	static boolean[] visit;
	static int nowCnt;
	
	public static void dfs(List<Integer>[] G, int n) {
		nowCnt++;
		visit[n] = true;
		
		for(int i=0;i<G[n].size();i++) {
			int nextNode = G[n].get(i);
			if(!visit[nextNode]) {
				dfs(G, nextNode);
			}
		}
	}
	
	public static void makeCnt(boolean isIn) {
		int[] result;
		List<Integer>[] G;
		if(isIn) {
			result = in;
			G = inG;
		}
		else {
			result = out;
			G = outG;
		}
		
		for(int i=1;i<=N;i++) {
			nowCnt = 0;
			Arrays.fill(visit, false);
			dfs(G, i);
			result[i] = nowCnt;
		}
		
	}

	public static void main(String[] args) throws Exception {					
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++) {
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			inG = new List[N+1];
			outG = new List[N+1];
			in = new int[N+1];
			out = new int[N+1];
			visit = new boolean[N+1];
			
			for(int i=0;i<=N;i++) {
				inG[i] = new ArrayList<>();
				outG[i] = new ArrayList<>();
			}
			
			// 1. in, out 그래프 만들기
			for(int i=0;i<M;i++) {
				int a, b;
				st = new StringTokenizer(br.readLine(), " ");
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				outG[a].add(b);
				inG[b].add(a);
			}
			
			// 2. in, out 구하기
			//dfs(outG, 1, 0);
			//System.out.println(nowCnt);
			
			
			makeCnt(true);
			makeCnt(false);
			
			// 3. in+out-1=1 == N인 노드 개수 세기
			int answer = 0;
			for(int i=1;i<=N;i++) {
				//System.out.println(in[i]+" "+out[i]);
				if(in[i] + out[i] -1 == N) answer++;
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
