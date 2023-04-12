#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ix, iy, ans=500;

void colorMap(int x1, int y1, int x2, int y2){
    for(int x=x1; x<x2; x++){
        for(int y=y1; y<y2; y++){
            map[x][y] = 1;
        }
    }
}

bool canMove(int x, int y, int i){
    if(i==0){ // right
        return map[x][y-1]!=map[x][y];
    }
    if(i==1){ // left
        return map[x-1][y-1]!=map[x-1][y];
    }
    if(i==2){ // up
       return map[x][y]!=map[x-1][y];
    }
    if(i==3){ // down
        return map[x][y-1]!=map[x-1][y-1];
    }
    return false;
}


void dfs(int x, int y, int px, int py, int len){
    int nx, ny;
    
    if (x==ix && y==iy){
        ans = min(ans, len);
        return;
    }
    
    for(int i=0; i<4; i++){
        nx = x+dx[i]; ny = y+dy[i];
        if(nx==px && ny==py) continue;
        if(canMove(x, y, i)){
            dfs(nx, ny, x, y, len+1);
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for(int i=0; i<rectangle.size(); i++){
        colorMap(rectangle[i][0], rectangle[i][1], rectangle[i][2], rectangle[i][3]);
    }
    ix = itemX; iy = itemY;
    
    dfs(characterX, characterY, -1, -1, 0);
    answer = ans;
    
    return answer;
}
