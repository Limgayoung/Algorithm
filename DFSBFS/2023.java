import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 2023 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;      
    
    public static boolean isPrime(int prime) {    	
    	for(int i=2;i<=Math.sqrt(prime);i++) {   
    		if(prime%i == 0) return false;
    	}
    	return true;
    }
    
    public static void makePrime(String prime) throws Exception {
    	if(!isPrime(Integer.parseInt(prime))) return;
    	if(prime.length() == N) {
    		bw.write(prime+"\n");
    		return;
    	}

    	
    	//System.out.println("nowPrime: "+prime);
    				
    	for(int i=0;i<=9;i++) {
    		String nextNumStr = prime+String.valueOf(i);
    		int nextNum = Integer.parseInt(nextNumStr);
    		
    		//System.out.println("nextNum: "+nextNum);
    		if(nextNumStr.length() <= N && isPrime(nextNum)) {
    			makePrime(String.valueOf(nextNumStr));
    		}
    	}		
    }

    public static void main(String[] args) throws Exception {

    	N = Integer.parseInt(br.readLine());

    	
    	makePrime("2");  
    	makePrime("3");  
    	makePrime("5");  
    	makePrime("7");  
    	
    	    	    
    	
    	bw.close();
    }             
    

}
