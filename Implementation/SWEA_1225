
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class swea {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;     

    public static void main(String[] args) throws Exception {

    	for(int t = 1;t<=10;t++) {
    		   	
    		int test_case = Integer.parseInt(br.readLine());
    		st = new StringTokenizer(br.readLine(), " ");
    		
    		int[] nums = new int[8];
    		for(int i=0;i<8;i++) {
    			nums[i] = Integer.parseInt(st.nextToken());
    		}
    		
    		bw.write("#"+test_case+" ");
    		int i = 0;
    		int j = 1;
    		while(true) {
    			if(nums[i] - j <= 0) {
    				nums[i] = 0;
    				break;
    			}
    			nums[i] -= j;
    			
    			i++;
    			j++;
    			if(j>5) {
    				j=1;
    			}
    			if(i>=8) {
    				i = 0;
    				//j = 1;
    			}
				
    		}
    		
    		i++;
    		i%=8;
    		for(j=0;j<8;j++) {
    			bw.write(nums[(i+j)%8]+" ");
    		}
    		bw.write("\n");
    	}    	
    	
    	bw.close();
    }             
    
}

/*
1
10 6 12 8 9 4 1 3 

*/
