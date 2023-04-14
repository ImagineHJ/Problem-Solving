#include <string>
#include <vector>
#include <queue>

using namespace std;
int map[101][101];
int visited[101][101];
int cnt[101][101];
int M, N;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0,-1, 1, 0};

bool out(int x, int y){
    return x<0 || x>=M||y<0 || y>=N;
}

void bfs(){
    queue<pair<int, int>> q;
    int x, y, nx, ny, cost, count;
    
    visited[M-1][N-1] = 1;
    cnt[M-1][N-1] = 1;
    q.push({M-1, N-1});
    while(!q.empty()){
        x = q.front().first; y = q.front().second; q.pop();
        for(int d=2; d<4; d++){
            nx = x+dx[d]; ny=y+dy[d];
            if(!out(nx, ny) && map[nx][ny]==0){
                cnt[x][y]+=cnt[nx][ny];
                cnt[x][y] %= 1000000007;
            }
        }
        for(int d=0; d<2; d++){
            nx = x+dx[d]; ny=y+dy[d];
            if(!out(nx, ny) && visited[nx][ny]==0 && map[nx][ny]==0){
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    N = n; M = m;
    
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][0]-1][puddles[i][1]-1] = 1;
    }
    
    bfs();
    answer = cnt[0][0];
    
    return answer;
}
