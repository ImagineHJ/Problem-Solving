#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
bool visited[501][501][4];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;

int nextDir(int d, char c){
    if(c=='S') return d;
    if(c=='L'){
        if(d==0) return 2;
        if(d==1) return 3;
        if(d==2) return 1;
        if(d==3) return 0;
    }
    if(c=='R'){
        if(d==0) return 3;
        if(d==1) return 2;
        if(d==2) return 0;
        if(d==3) return 1;
    }
    return -1;
}

void findCycle(int x, int y, int d, int cnt, vector<string> &grid){
    int nx, ny, nd;
    
    //cout<<x<<" "<<y<<" "<<d<<endl;
    visited[x][y][d] = true;
    
    nx = x+dx[d]; 
    if(nx<0) nx = N-1;
    else if(nx>=N) nx = 0;
    
    ny = y+dy[d];
    if(ny<0) ny = M-1;
    else if(ny>=M) ny = 0;
    
    nd = nextDir(d, grid[nx][ny]);
    if(!visited[nx][ny][nd]) findCycle(nx, ny, nd, cnt+1, grid);
    else ans.push_back(cnt+1);
}

vector<int> solution(vector<string> grid) {
    N = grid.size();
    M = grid[0].size();
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int d=0; d<4; d++){
                if(!visited[i][j][d]) findCycle(i, j, d, 0, grid);
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    return ans;
}
