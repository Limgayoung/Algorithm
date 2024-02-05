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
import java.util.Stack;
import java.util.StringTokenizer;

public class sweq {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;   
    static List<String> opers = new ArrayList<>();
    static Stack<Integer> s = new Stack<>();
    
    static boolean calOpers(int num) {
    	s.clear();
    	s.add(num);
    	
    	for(String oper:opers) {
    		if(oper.contains("NUM")) { //유일하게 숫자 달린 연산
    			s.add(Integer.parseInt(oper.split(" ")[1]));
    		}
    		else if(oper.equals("POP")) {
    			if(s.empty()) return false;
    			s.pop();
    		}
    		else if(oper.equals("INV")) {
    			if(s.empty()) return false;
    			s.add(-s.pop());
    		}
    		else if(oper.equals("DUP")) {
    			if(s.empty()) return false;
    			s.add(s.peek());
    		}
    		else{
    			if(s.size() < 2) return false;
    			int a = s.pop();
				int b = s.pop();
    			if(oper.equals("SWP")) {    				
    				s.add(a);
    				s.add(b);    				
    			}
    			else if(oper.equals("ADD")) {
    				if(Math.abs((long)(a)+b) > 1000000000L) return false;
    				s.add(a+b);
    			}
    			else if(oper.equals("SUB")) {
    				if(Math.abs((long)(b)-a) > 1000000000L) return false;
    				s.add(b-a);
    			}
    			else if(oper.equals("MUL")) {
    				if(Math.abs((long)(a)*b) > 1000000000L) return false;
    				s.add(a*b);
    			}
    			else if(oper.equals("DIV")) {
    				if(a == 0) return false;
    				int result = Math.abs(b)/Math.abs(a);
    				if((b<0 && a<0) || (b>=0 && a>0)) s.add(result);
    				else s.add(-result);
    			}
    			else if(oper.equals("MOD")) {
    				if(a == 0) return false;
    				int result = Math.abs(b)%Math.abs(a);
    				if(b>=0) s.add(result);
    				else s.add(-result);
    			}
    		}    		
    	}
    	if(s.size()!=1) return false;
    	return true;
    }

    public static void main(String[] args) throws Exception {


    	all: while(true) {
    		opers.clear();
    		
    		while(true) {
    			String oper = br.readLine();
    			if(oper.equals("QUIT")) break all;
    			if(oper.equals("END")) break;
    			opers.add(oper);
    		}
    		
    		//System.out.println(opers.toString());
    		
    		int N = Integer.parseInt(br.readLine());
    		for(int i=0;i<N;i++) {
    			if(calOpers(Integer.parseInt(br.readLine()))) {
    				bw.write(s.peek()+"\n");
    			}
    			else bw.write("ERROR\n");
    		}
    		bw.write("\n");
    		String buffer = br.readLine();
    	}

        bw.close();
    }             
    

    
}

/*
1
7
4 10 2 20 30 1 3
*/
