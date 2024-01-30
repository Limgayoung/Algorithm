import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[] arr = new int[101];
        
    public static void main(String[] args) throws IOException {

    	N = Integer.parseInt(br.readLine());
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=1;i<=N;i++) {
    		int a = Integer.parseInt(st.nextToken());
    		arr[i] = a;
    	}
    	
    	int studentNum = Integer.parseInt(br.readLine());
    	int gender;
    	int switchNum;
    	
    	for(int i=0;i<studentNum;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		gender = Integer.parseInt(st.nextToken());
    		switchNum = Integer.parseInt(st.nextToken());
    		changeSwitch(gender, switchNum);
    	}
    	
    	for(int i=1;i<=N;i++) {
    		System.out.print(arr[i]+" ");
    		if(i%20 == 0) System.out.println();
    	}
    }
    
    public static void changeSwitch(int gender, int switchNum) {
    	if(gender == 1) { //남자    		
    		for(int i=switchNum;i<=N;i+=switchNum) {
    			changeSwitchValue(i);
    		}
    	}
    	else { //여자
    		int l = switchNum;
    		int r = switchNum;
    		
    		changeSwitchValue(switchNum);
    		while(arr[l] == arr[r]) {
    			changeSwitchValue(l);
    			changeSwitchValue(r);
    			if(l-1 > 0 && r+1 <= N && arr[l-1] == arr[r+1]) {
    					l--;
    	    			r++;
    			}
    			else break;
    		}
    	}
    }
        
    public static void changeSwitchValue(int index) {
    	if(arr[index] == 0) arr[index] = 1;
    	else arr[index] = 0;
    }      
}
