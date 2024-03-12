#include <iostream>
#include <queue>

using namespace std;

char map[251][251];
int sheep=0, wolf=0;
int r, c;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    int curx, cury, nextx, nexty;
    int sheep_cnt=0, wolf_cnt=0;
    
    q.push({i, j});
    if(map[i][j]=='.') map[i][j]='X';
    if(map[i][j]=='v') map[i][j]='V';
    if(map[i][j]=='k') map[i][j]='K';
    
    while(!q.empty()){
        curx = q.front().first;
        cury = q.front().second;
        q.pop();
        if(map[curx][cury]=='V'){
            wolf_cnt++;
        }
        else if(map[curx][cury]=='K'){
            sheep_cnt++;
        }
        for(int k=0; k<4; k++){
            nextx = curx + dx[k];
            nexty = cury + dy[k];
            if(nextx<0 || nexty<0 || nextx>=r || nexty>=c) continue;
            if(map[nextx][nexty]=='.' || map[nextx][nexty]=='v' || map[nextx][nexty]=='k'){
                q.push({nextx, nexty});
                if(map[nextx][nexty]=='.') map[nextx][nexty]='X'; // mark visited
                if(map[nextx][nexty]=='v') map[nextx][nexty]='V';
                if(map[nextx][nexty]=='k') map[nextx][nexty]='K';
            }
        }
    }
    // count left sheep&wolves
    if(sheep_cnt>wolf_cnt){
        sheep += sheep_cnt;
    }
    else{
        wolf += wolf_cnt;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster

    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j]=='.' || map[i][j]=='v' || map[i][j]=='k'){
                bfs(i, j);
            }
        }
    }
    cout<<sheep<<" "<<wolf;
    
}
