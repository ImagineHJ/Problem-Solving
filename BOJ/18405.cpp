//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int map[201][201];
pair<int, int> virus[201][201];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;

void bfs(int x, int y){
    int new_x, new_y, vir, time;
    queue<pair<int, int>> q;
    
    q.push({x, y});
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        q.pop();
        vir = virus[x][y].first; time = virus[x][y].second;
        for(int i=0; i<4; i++){
            new_x = x+dx[i]; new_y = y+dy[i];
            if(new_x<=0 || new_x>n || new_y<=0 || new_y>n) continue; // out of bound
            if(virus[new_x][new_y].second>time+1 || (virus[new_x][new_y].second==time+1 && virus[new_x][new_y].first>vir)) {
                // if other virus can reach here earlier
                // if the time is same, then virus with smaller number will reach first
                virus[new_x][new_y] = {vir, time+1};
                q.push({new_x, new_y});
            };
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, k, s, x, y;
    
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            map[i][j] = a;
            if(a==0) virus[i][j] = {a, INF};
            else virus[i][j] = {a, 0};
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]!=0) bfs(i, j); // virus start point
        }
    }
    
    cin>>s>>x>>y;
    
    if(virus[x][y].second > s) cout<<0;
    else cout<<virus[x][y].first;
    
    
    return 0;
}
