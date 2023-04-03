#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

struct cctv{
    int n;
    int x;
    int y;
};

int map[9][9];
vector<cctv> cctvs;
int n, m, minAns = 40;
vector<vector<vector<int>>> dir{
    {{}, {}, {}, {}},
    {{1}, {2}, {3}, {4}},
    {{1, 3}, {2, 4}},
    {{1, 2}, {2, 3}, {3, 4}, {4, 1}},
    {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}},
    {{1, 2, 3, 4}}
};

void checkMap(int idx, int x, int y, int d){
    int num = idx+10;
    if(d==1){
        for(int i=x+1; i<n; i++){
            if(map[i][y]==6) break;
            if(map[i][y]==0){
                map[i][y] = num;
            }
        }
    }
    if(d==2){
        for(int i=y-1; i>=0; i--){
            if(map[x][i]==6) break;
            if(map[x][i]==0){
                map[x][i] = num;
            }
        }
    }
    if(d==3){
        for(int i=x-1; i>=0; i--){
            if(map[i][y]==6) break;
            if(map[i][y]==0){
                map[i][y] = num;
            }
        }
    }
    if(d==4){
        for(int i=y+1; i<m; i++){
            if(map[x][i]==6) break;
            if(map[x][i]==0){
                map[x][i] = num;
            }
        }
    }
}

void uncheckMap(int idx, int x, int y, int d){
    int num = idx+10;
    if(d==1){
        for(int i=x+1; i<n; i++){
            if(map[i][y]==6) break;
            if(map[i][y]==num){
                map[i][y] = 0;
            }
        }
    }
    if(d==2){
        for(int i=y-1; i>=0; i--){
            if(map[x][i]==6) break;
            if(map[x][i]==num){
                map[x][i] = 0;
            }
        }
    }
    if(d==3){
        for(int i=x-1; i>=0; i--){
            if(map[i][y]==6) break;
            if(map[i][y]==num){
                map[i][y] = 0;
            }
        }
    }
    if(d==4){
        for(int i=y+1; i<m; i++){
            if(map[x][i]==6) break;
            if(map[x][i]==num){
                map[x][i] = 0;
            }
        }
    }
}

void check(int i){
    int cnt=0;
    if(i==cctvs.size()){
        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                if(map[a][b]==0) cnt++;
            }
        }
        minAns = min(minAns, cnt);
        return;
    }
    
    int x = cctvs[i].x, y= cctvs[i].y, num= cctvs[i].n;
    
    for(int a=0; a<dir[num].size(); a++){
        for(int b=0; b<dir[num][a].size(); b++){
            checkMap(i, x, y, dir[num][a][b]);
        }
        check(i+1);
        for(int b=0; b<dir[num][a].size(); b++){
            uncheckMap(i, x, y, dir[num][a][b]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    cctv c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j]>0 && map[i][j]<6){
                c.n = map[i][j]; c.x = i; c.y = j;
                cctvs.push_back(c);
            }
        }
    }
    
    check(0);
    cout<<minAns;
    
    return 0;
}
