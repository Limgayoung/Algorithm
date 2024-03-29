import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int[] pi;
	static String p;
	static int cnt = 0;
	static ArrayList<Integer> index = new ArrayList<>();
	
	public static void makePi() {
		pi[0] = 0;
		int j=0;
		for(int i=1;i<p.length();i++) {
			//길이가 i인 부분문자열에서 접두사와 접미사가 같은 최대 길이 찾기

			//현재 i와 j번째 문자가 다르다면 j 값을 갱신해 줘야 함
			//갱신할 때 현재 i와 j가 다르다면 j를 pi[j-1]로 갱신
			//j가 0보다 크고 i,j 문자가 같기 전까지 반복 - 같다면 j 갱신 완료된 것임
			while(j>0 && p.charAt(i) != p.charAt(j)) {
				j=pi[j-1];
			}
			if(p.charAt(i) == p.charAt(j)) j++;
			pi[i] = j;
		}
	}
	
	public static void checkStr(String str) {
		
		int j=0;
		for(int i=0;i<str.length();i++) {
			//System.out.println(i);
			while(j>0 && str.charAt(i) != p.charAt(j)) {
				j=pi[j-1];
			}
			if(str.charAt(i) == p.charAt(j)) j++;
			if(j==p.length()) { //찾음!
				//System.out.println("strSumIndex: "+strSumIndex+" i: "+i);
				
				int nowStartIndex = i-p.length()+2;
				
				//j 갱신 필요
				j=pi[p.length()-1];
				
				cnt++;
				index.add(nowStartIndex); //0부터 시작해서 2 더해야함
				//System.out.println(pi[p.length()-1]+" "+i);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
				
		String t = br.readLine();
		p = br.readLine();
		pi = new int[p.length()];

		makePi();
		
		checkStr(t);
		
		bw.write(cnt+"\n");
		for(int len:index) {
			bw.write(len+" ");
		}
		
	    bw.close();
	
	}
	
/**
abababab abababab
abab

abcabcabcab
abcab

aabbaabbaabbaabbaa
aabbaa
 */
	
}
