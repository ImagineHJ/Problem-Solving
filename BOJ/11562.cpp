#include <iostream>
#include <vector>
#define INF 1e9
using  namespace std;

int n, m, k;
int map[251][251];
vector<pair<int, int>> roads;

void floyd(){
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            for(int c=1; c<=n; c++){
                map[b][c] = min(map[b][c], map[b][a]+map[a][c]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    
    int u, v, b;
    for(int i=0; i<m; i++){
        cin>>u>>v>>b;
        map[u][v] = 0;
        if(b==1) {map[v][u]=0;}
        else {map[v][u]=1;}
    }
    
    floyd();
    
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>u>>v;
        cout<<map[u][v]<<'\n';
    }
    
    return 0;
}
