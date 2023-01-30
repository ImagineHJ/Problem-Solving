//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

int dx[] = { 1, -1, 0, 0};
int dy[] = { 0, 0, 1, -1};

int map[8][8];
int map_temp[8][8];
int m, n;

void dfs(int x, int y){
    int new_x, new_y;
    map[x][y] = 3;
    for(int i=0; i<4; i++){
        new_x = x+dx[i]; new_y = y+dy[i];
        if(0<=new_x && new_x<n && 0<=new_y && new_y<m && map[new_x][new_y]==0){
            dfs(new_x, new_y);
        }
    }
}

int safe_zone(int x1, int y1, int x2, int y2, int x3, int y3){
    int cnt = 0;
    map[x1][y1] =  map[x2][y2] =  map[x3][y3] = 1; // build 3 walls
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==2) dfs(i, j); // dfs from virus zone
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]==0) cnt++; // count the safe zones
            map[i][j] = map_temp[i][j]; // clean map
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, ret = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a;
            map[i][j] = a;
            map_temp[i][j] = a;
        }
    }
    // brute-force
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                for(int l=0; l<m; l++){
                    for(int o=0; o<n; o++){
                        for(int p=0; p<m; p++){
                            if( (i!=k || j!=l) && (i!=o || j!=p) && ( k!=o|| l!=p) && map[i][j]==0 && map[k][l]==0 && map[o][p]==0){
                                ret = max(ret, safe_zone(i, j, k, l, o, p));
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ret;
    
    
    return 0;
}
