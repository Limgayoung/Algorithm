import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
 
public class Solution {
 
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
 
    static long[] arr;
    static long[] result;
     
    public static void main(String[] args) throws Exception {
         
        int T = Integer.parseInt(br.readLine());
         
        for(int t=1;t<=T;t++) {
            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), " ");
             
            result = new long[N];
            arr = new long[N];
            for(int i=0;i<N;i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
             
            //lis 만들기
            int max = 0;
            for(int i=0;i<N;i++) {
                //맨 뒷 값보다 크면 max+1 반환됨
                //중간에 들어간다면 들어갈 자리+1 반환됨 (이분탐색 해서)
                int posi = Arrays.binarySearch(result, 0,max,arr[i]); //들어갈 위치 찾기
                posi = Math.abs(posi)-1;
                result[posi] = arr[i];
                if(posi == max)
                    max++;
                //System.out.println(Arrays.toString(result));
            }
             
            bw.write("#"+t+" "+max+"\n");
        }
         
         
         
         
             
        bw.close();
     
    }
     
}
