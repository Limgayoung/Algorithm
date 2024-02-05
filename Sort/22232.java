package com.day2.perm;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;


public class sweq {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M;     
    static Set<String> extensions = new HashSet<>();
    static List<File> files = new ArrayList<>();

    public static void main(String[] args) throws Exception {

    	st = new StringTokenizer(br.readLine(), " ");
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine(), ".");
    		files.add(new File(st.nextToken(), st.nextToken()));
    	}
    	
    	for(int i=0;i<M;i++) {
    		extensions.add(br.readLine());
    	}
    	
    	Collections.sort(files);
    	
    	for(int i=0;i<N;i++) {
    		System.out.println(files.get(i));
    	}

    	bw.close();
    }             
    
    static class File implements Comparable<File>{
    	String fileName;
    	String extension;

		public File(String fileName, String extension) {
			super();
			this.fileName = fileName;
			this.extension = extension;
		}
				
		@Override
		public String toString() {
			return fileName + "." + extension;
		}

		@Override
		public int compareTo(File o) {
	    	//fileName 순 정렬
	    	//확장자 존재 여부 정렬
	    	//확장자 사전순 정렬			
			if(this.fileName.compareTo(o.fileName) == 0) {
				if(extensions.contains(this.extension) && extensions.contains(o.extension)) {
					return this.extension.compareTo(o.extension);
				}
				if(!extensions.contains(this.extension) && !extensions.contains(o.extension)) {
					return this.extension.compareTo(o.extension);
				}
				return extensions.contains(this.extension) ? -1 : 1;
			}
			return this.fileName.compareTo(o.fileName);
		}
    }
    
}

/*
10 3
abc.jpeg
abc.cpp
abc.cppp
foo.yolo
bar.cpp
abc.jpg
bar.maltise
aa.sdf
bar.jpg
foo.jpg
jpg
cpp
maltise
*/
