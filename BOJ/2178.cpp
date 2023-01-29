//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

int map[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int bfs(int x, int y){
    int now_x, now_y, new_x, new_y;
    queue<pair<int, int>> q;
    
    q.push({x, y});
    while(!q.empty()){
        now_x = q.front().first; now_y = q.front().second;
        q.pop();
        if(now_x==n && now_y==m) return map[now_x][now_y]; // found destination
        for(int i=0; i<4; i++){
            new_x = now_x+dx[i]; new_y = now_y+dy[i]; // connected way
            if(0<new_x && new_x<n+1 && 0<new_y && new_y<m+1 && (new_y!=y || new_x!=x) &&map[new_x][new_y]==1){
                q.push({new_x, new_y});
                map[new_x][new_y] = map[now_x][now_y]+1; // save min cost in map
            }
        }
    }
    return map[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string l;
    cin>>n>>m;
    for(int i=1; i<n+1; i++){
        cin>>l;
        for(int j=1; j<m+1; j++){
            map[i][j] = l[j-1]-'0'; // string to int
        }
    }
    cout<<bfs(1,1);
    
    return 0;
}
