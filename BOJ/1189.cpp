#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[6][6];
int r, c, k;
bool visited[6][6];

int numOfWays(int x, int y, int k){
    int nx, ny, ret=0;
    if(k<1) return 0;
    if(k==1){
        if(x==0 && y==c-1) return 1;
        else return 0;
    }
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        nx = x+dx[i]; ny = y+dy[i];
        if(nx<0 || nx>r-1 || ny<0 || ny>c-1 || map[nx][ny]=='T' || visited[nx][ny]) continue;
        ret+=numOfWays(nx, ny, k-1);;
    }
    visited[x][y] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>r>>c>>k;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>map[i][j];
        }
    }
    
    cout<<numOfWays(r-1, 0, k);
    
    return 0;
}
