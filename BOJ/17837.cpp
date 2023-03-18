#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

struct player{
    int dir; int x; int y; int floor;
};
player players[11];
int map[13][13];
int maxFloor[13][13];
int n, k, turn=0;
bool over = false;

int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

int oppositeDir(int d){
    if (d==1) return 2;
    if (d==2) return 1;
    if (d==3) return 4;
    if (d==4) return 3;
    return 0;
}

void getToTop(int i, int x, int y){
    maxFloor[players[i].x][players[i].y]--;
    players[i].x = x; players[i].y = y;
    maxFloor[x][y]++; players[i].floor = maxFloor[x][y];
    if(maxFloor[x][y]>=4) over = true;
}

void allToTop(int i, int x, int y){
    int cnt = 0;
    int old_x = players[i].x, old_y = players[i].y, old_floor = players[i].floor;
    
    maxFloor[old_x][old_y] = old_floor-1;
    for(int j=1; j<=k; j++){
        if(players[j].x==old_x && players[j].y==old_y && players[j].floor>=old_floor){
            players[j].x = x; players[j].y = y;
            players[j].floor = maxFloor[x][y]+1+players[j].floor-old_floor;
            cnt++;
        }
    }
    maxFloor[x][y]+=cnt;
    if(maxFloor[x][y]>=4) over = true;
}

void allToTopReverse(int i, int x, int y){
    int cnt = 0;
    int base = maxFloor[players[i].x][players[i].y], old_x = players[i].x, old_y = players[i].y, old_floor = players[i].floor;
    maxFloor[old_x][old_y] = old_floor-1;
    for(int j=1; j<=k; j++){
        if(players[j].x==old_x && players[j].y==old_y && players[j].floor>=old_floor){
            players[j].x = x; players[j].y = y;
            players[j].floor = maxFloor[x][y]+1+base-players[j].floor; // reverse the floor
            cnt++;
        }
    }
    maxFloor[x][y]+=cnt;
    if(maxFloor[x][y]>=4) over = true;
}

void move(int i){
    int new_x = players[i].x+dx[players[i].dir], new_y = players[i].y+dy[players[i].dir];
    bool move = true;
    // move to blue or out of map
    if(new_x<=0 || new_x>n || new_y<=0 || new_y>n || map[new_x][new_y]==2){
        move = false;
        players[i].dir = oppositeDir(players[i].dir); // change direction
        new_x = players[i].x+dx[players[i].dir]; new_y = players[i].y+dy[players[i].dir];
        if(new_x>0 && new_x<=n && new_y>0 && new_y<=n && map[new_x][new_y]!=2) move = true; // change direction and check if possible to move
    }
    if(move){
        // move to white
        if(map[new_x][new_y]==0){
            if(maxFloor[players[i].x][players[i].y]==players[i].floor) getToTop(i, new_x, new_y);
            else allToTop(i, new_x, new_y);
        }
        // move to red
        if(map[new_x][new_y]==1){
            if(maxFloor[players[i].x][players[i].y]==players[i].floor) getToTop(i, new_x, new_y);
            else allToTopReverse(i, new_x, new_y);
        }
    }
}

void doTurn(){
    for(int i=1; i<=k; i++){
        move(i);
        if(over) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
            maxFloor[i][j] = 0;
        }
    }
    
    player p; p.floor = 1;
    for(int i=1; i<=k; i++){
        cin>>p.x>>p.y>>p.dir;
        players[i] = p;
        maxFloor[p.x][p.y] = 1;
    }
    
    while(!over && turn<1000){
        turn++;
        doTurn();
    }
    if (turn>=1000) cout<<-1;
    else cout<<turn;
}
