import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 */

public class Code {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int[][] map;
    static ArrayList<Point> cctv = new ArrayList<>();
    static ArrayList<Point> dir[] = new ArrayList[6];
    static int minCnt = 1000000;
    static int groundSize = 0;

    static int N, M;

    public static void printMap() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static Point rotationDir(Point p, int cnt) { //90도 방향 회전
        Point result = new Point(p.x, p.y);

        for(int i=0;i<cnt;i++) {
            if(result.x == 0) {
                if(result.y==1) {
                    result.x = 1;
                    result.y = 0;
                }
                else {
                    result.x = -1;
                    result.y = 0;
                }
            }
            else if(result.x == -1) {
                result.x = 0;
                result.y = 1;
            }
            else { //x==1
                result.x = 0;
                result.y = -1;
            }
        }
        return result;
    }

    public static void initDir() {

        for(int i=0;i<6;i++) {
            dir[i] = new ArrayList<>();
        }

        //1번 좌
        dir[1].add(new Point(0,1));

        //2번 좌우
        dir[2].add(new Point(0,-1));
        dir[2].add(new Point(0,1));

        //3번 상우
        dir[3].add(new Point(-1,0));
        dir[3].add(new Point(0,1));

        //4번 좌상우
        dir[4].add(new Point(0,-1));
        dir[4].add(new Point(-1,0));
        dir[4].add(new Point(0,1));

        //5번 상하좌우
        dir[5].add(new Point(0,-1));
        dir[5].add(new Point(0,1));
        dir[5].add(new Point(-1,0));
        dir[5].add(new Point(1,0));
    }

    public static int calZeroCnt(int[][] arr) {
        int cnt = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(arr[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static int changeMap(int x, int y, int dx, int dy, int[][] temp) {
        int cnt = 0;
        while(true) {
            int nx = x+dx;
            int ny = y+dy;

            if(nx>=0 && nx<N && ny>=0 && ny<M) {
                if(temp[nx][ny] == 6) break;
                else if(temp[nx][ny] == 0) {
                    temp[nx][ny] = 7;
                    cnt++;
                }
            }
            else break;

            x = nx;
            y = ny;
        }
        return cnt;
    }

    public static int[][] copyMap(int [][] arr){
        int[][] result = new int[N][M];

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                result[i][j] = arr[i][j];
            }
        }
        return result;
    }

    public static void dfs(int index, int cnt, int[][] arr) {
        if(index >= cctv.size()) {
            int nowCnt = calZeroCnt(arr);
            if(minCnt > nowCnt) {
                minCnt = nowCnt;
            }
            return;
        }

        //현재 cctv가 보는 대로 map 변경, 90도씩 회전 가능
        Point nowCctvPosition = cctv.get(index);
        int nowCctvNum = map[nowCctvPosition.x][nowCctvPosition.y];
        int rotationCnt = 4;
        if(nowCctvNum == 2) rotationCnt = 2;
        else if(nowCctvNum == 5) rotationCnt = 1;

        for(int i=0;i<rotationCnt;i++) { //회전
            int nowCnt = 0;

            int [][] temp = copyMap(arr);
            for(int j=0;j<dir[nowCctvNum].size();j++) { //각 cctv의 방향
                Point nowDir = rotationDir(dir[nowCctvNum].get(j), i);
                nowCnt += changeMap(nowCctvPosition.x, nowCctvPosition.y, nowDir.x, nowDir.y, temp);
            }
            dfs(index+1, cnt+nowCnt, temp);
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for(int j=0;j<M;j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 0) groundSize++;
                if(map[i][j] != 0 && map[i][j] != 6) {
                    cctv.add(new Point(i,j));
                }
            }
        }
        initDir();
        dfs(0,0, map);

        bw.write(""+minCnt);

        bw.close();
    }

}

/**
 4 6
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 3 0 0 0
 0 0 0 0 0 0
 13

 */
