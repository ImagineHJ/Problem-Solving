#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

int m, n, k;
int map[50][50];
int visited[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool outOfRange(int x, int y){
    return x<0 || y<0 || x>=m || y>=n;
}

void dfs(int x, int y){
    int nx, ny;
    
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        nx = x+dx[i]; ny = y+dy[i];
        if(outOfRange(nx, ny) ||  visited[nx][ny] || map[nx][ny]==0) continue;
        dfs(nx, ny);
    }
}

int solve(){
    int ret = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]==1 && !visited[i][j]){
                dfs(i, j);
                ret ++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int T, a, b;
    cin>>T;
    
    for(int t=0; t<T; t++){
        cin>>m>>n>>k;
        init();
        
        for(int i=0; i<k; i++){
            cin>>a>>b;
            map[a][b] = 1;
        }
        
        cout<<solve()<<'\n';
    }
    
    return 0;
}
