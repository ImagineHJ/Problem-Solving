#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
struct location{
    int x; int y; int dist;
};
int map[20][20];
bool visited[20][20];
int shark_size=2, shark_ate = 0;
int shark_x, shark_y;
int time_passed = 0;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n;

bool eat_fish(){
    int min_dist = INF, fish_x, fish_y;
    location nowloc, newloc;
    
    bool found = false;
    queue<location> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false; // initialize
        }
    }
    nowloc.x = shark_x; nowloc.y = shark_y; nowloc.dist = 0;
    q.push(nowloc);
    visited[nowloc.x][nowloc.y] = true;
    while(!q.empty()){ // BFS
        nowloc = q.front();q.pop();
        
        if(found){
            if(nowloc.dist>=min_dist) break; // no need to search for further distance
        }
        
        for(int i=0; i<4; i++){
            newloc.x = nowloc.x + dx[i]; newloc.y = nowloc.y + dy[i]; newloc.dist = nowloc.dist + 1;
            
            if(newloc.x<0||newloc.x>=n ||newloc.y<0||newloc.y>=n) continue; // out of the map
            if(visited[newloc.x][newloc.y]) continue;
            
            if(map[newloc.x][newloc.y]!=0 && map[newloc.x][newloc.y]<shark_size){ // found eatable fish
                found = true;
                if(newloc.dist<min_dist){
                    min_dist = newloc.dist;
                    fish_x = newloc.x; fish_y = newloc.y;
                }
                else if(newloc.dist==min_dist){
                    if(newloc.x<fish_x){
                        fish_x = newloc.x; fish_y = newloc.y;
                    }
                    else if(newloc.x==fish_x && newloc.y<fish_y){
                        fish_x = newloc.x; fish_y = newloc.y;
                    }
                }
                
            }
            else if(map[newloc.x][newloc.y]==0 || map[newloc.x][newloc.y]==shark_size){ // no fish or same size fish -> can pass
                visited[newloc.x][newloc.y] = true;
                q.push(newloc);
            }
        }
    }
    
    if(!found) return false; // no more eatable fish
    
    shark_x = fish_x; shark_y = fish_y; // move to fish
    map[fish_x][fish_y] = 0; // fish is gone
    time_passed+=min_dist; // time to get to the fish
    shark_ate++; // count fishes eaten
    
    if(shark_ate==shark_size){ // eat enough fish -> size increase
        shark_size++;
        shark_ate = 0;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            if(a==9){
                shark_x = i; shark_y = j;
                map[i][j] = 0;
            }else{
                map[i][j] = a;
            }
        }
    }
    while(eat_fish()){
    }
    cout<<time_passed;
    
    return 0;
}
