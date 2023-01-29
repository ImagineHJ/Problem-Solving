//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

int map[50][50];
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int w, h;

void dfs(int x, int y){
    int new_x, new_y;
    map[x][y] = 0; // visit
    for(int i=0; i<8; i++){
        new_x = x+dx[i]; new_y = y+dy[i];
        if ( 0<=new_x && new_x<h && 0<=new_y && new_y<w && map[new_x][new_y]==1) {
            dfs(new_x, new_y); // another connected land
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, cnt;
    
    while(true){
        cnt = 0;
        cin>>w>>h;
        if(w==0 && h==0) break; // end of test case
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>a;
                map[i][j] = a;
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]==1) {
                    dfs(i, j);
                    cnt++; // count number of new island
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
