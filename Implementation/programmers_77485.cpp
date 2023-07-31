#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;

void printMap(int row, int col){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int rotation(vector<int> query){
    int t;
    int min = 100000;
    int beforeNum;
    
    int maxX, maxY, startX, startY, x, y;
    
    startX = query[0]; //행
    startY = query[1]; //열
    maxX = query[2];
    maxY = query[3];
    x = startX;
    y = startY+1;
    beforeNum = map[startX][startY];

    while(1){        
        t = map[x][y];
        map[x][y] = beforeNum;
        beforeNum = t;
        //printf("%d ",map[x][y]);
        if(map[x][y] < min) min = map[x][y];
        
        if(x == startX && y == startY){ //종료 조건
            printf("\n");
            return min;
        }
        
        else if(x == startX){ //→
            if(y == maxY){
                x++;
            }
            else y++;
        }
        else if(y == maxY){ //↑
            if(x == maxX){
                y--;
            }
            else x++;
                
        }
        else if(x == maxX){ //←
            if(y == startY){
                x--;
            }
            else y--;
        }
        else if(y == startY){ //↓
            x--;
        }        
    }
    return 1;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> mmap(rows+1, vector<int>(columns+1));
    int i,j,k;
    int querySize = queries.size();
    
    //make map
    k=1;
    for(i=1;i<=rows;i++){
        for(j=1;j<=columns;j++){
            mmap[i][j] = k;   
            k++;
        }
    }
    map = mmap;

    //rotation
    for(i=0;i<querySize;i++){
        answer.push_back(rotation(queries[i]));
    }
    
    return answer;
}
