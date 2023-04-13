#include <iostream>
#include <vector>
#define INF 1e9
using  namespace std;

int n, ans = 500;
char map[51][51];
int visited[51][51][4];
vector<pair<int, int>> doors;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int nextDir(int curDir, int mirror){
    if(curDir==0 && mirror==1) return 3;
    if(curDir==1 && mirror==1) return 2;
    if(curDir==2 && mirror==1) return 1;
    if(curDir==3 && mirror==1) return 0;
    
    if(curDir==0 && mirror==2) return 2;
    if(curDir==1 && mirror==2) return 3;
    if(curDir==2 && mirror==2) return 0;
    if(curDir==3 && mirror==2) return 1;
    return -1;
}

bool outOfRange(int x, int y){
    return x<0 || x>=n ||y<0 || y>=n;
}

void seeDoor(int x, int y, int d, int cnt){
    int nx = x, ny = y;
    
    if(cnt>=ans) return; // cannot be answer
    
    visited[x][y][d] = cnt;
    while(1){
        nx += dx[d]; ny += dy[d];
        if(outOfRange(nx, ny)) break;
        if(map[nx][ny]=='*') break;
        if(visited[nx][ny][d]!=-1 && visited[nx][ny][d]<=cnt) break;
        if(nx==doors[1].first && ny==doors[1].second){ // found door
            ans = min(ans, cnt);
            break;
        }
        // meet mirror
        if(map[nx][ny]=='!'){
            map[nx][ny] = 1; // mirror '/'
            seeDoor(nx, ny, nextDir(d, 1), cnt+1);
            
            map[nx][ny] = 2; // mirror '\'
            seeDoor(nx, ny, nextDir(d, 2), cnt+1);
            
            map[nx][ny] = '.'; // no mirror
            seeDoor(nx, ny, d, cnt);
            
            map[nx][ny] = '!';
            return;
        }
        else if(map[nx][ny]==1) d = nextDir(d, 1);
        else if(map[nx][ny]==2) d = nextDir(d, 2);
        visited[nx][ny][d] = cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            for(int k=0; k<4; k++){
                visited[i][j][k] = -1; // init
            }
        }
    }
    
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<n; j++){
            map[i][j] = s[j];
            if(map[i][j]=='#'){
                doors.push_back({i, j});
            }
        }
    }
    
    for(int d=0; d<4; d++) seeDoor(doors[0].first, doors[0].second, d, 0);
    
    cout<<ans;
    
    return 0;
}

