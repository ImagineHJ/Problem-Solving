#include <iostream>
#include <queue>

using namespace std;

char map[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;

int bfs(int x, int y){
    queue<pair<int, int>> q;
    
    q.push({x, y});
    int curx, cury, nextx, nexty;
    while(!q.empty()){
        curx = q.front().first;
        cury = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            nextx = curx + dx[i];
            nexty = cury + dy[i];
            if(nextx<0 || nexty<0 || nextx>m || nexty>n || map[nextx][nexty]!='0' ) continue;
            if(nextx == m-1) return 1;
            q.push({nextx, nexty});
            map[nextx][nexty]='2';
        }
    }
    return 0;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s, ans="NO";
    cin>>m>>n;
        
    for(int i=0; i<m; i++){
        cin>>s;
        for(int j=0; j<n; j++){
            map[i][j] = s[j];
        }
    }
    for(int i=0; i<n; i++){
        if(map[0][i]=='0' && bfs(0, i)) ans = "YES";
    }
    
    cout<<ans;
    
    return 0;
    
}
