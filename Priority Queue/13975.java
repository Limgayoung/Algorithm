import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;


public class sweq {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, T;     
    static PriorityQueue<Long> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        
        T = Integer.parseInt(br.readLine());
        
        for(int t=0;t<T;t++) {
            pq.clear();
            N = Integer.parseInt(br.readLine());
            
            st = new StringTokenizer(br.readLine(), " ");
            for(int i=0;i<N;i++) {                
                pq.add(Long.parseLong(st.nextToken()));
            }

            long answer = 0;
            while(!pq.isEmpty()) {
                long a = pq.poll();
                if(pq.isEmpty()) { //마지막
                    break;
                }
                long b = pq.poll();
//                System.out.println("a: "+a+" b: "+b+" add a+b: "+(a+b));                
                answer += a+b;
                pq.add(a+b);
//                System.out.println("answer: "+answer);
            }
            
            bw.write(answer + "\n");
        }
        

        bw.close();
    }             
    

    
}

/*
1
7
4 10 2 20 30 1 3
*/
