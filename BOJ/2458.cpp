//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int map[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a, b, inf_flag, cnt=0;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) map[i][j]=0;
            else map[i][j]=INF;
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        map[a][b] = 1;
    }
    
    // floyed warshall
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
            }
        }
    }
    
    // check if one node is connected to all the other nodes
    // if some nodes can go to node i, and i node can reach the rest -> node i is connected to all nodes
    for(int i=1; i<=n; i++){
        inf_flag = 0;
        for(int j=1; j<=n; j++){
            if(map[i][j]==INF && map[j][i]==INF){
                inf_flag = 1;
                break;
            }
        }
        if(!inf_flag) cnt++;
    }
    cout<<cnt;
    
    return 0;
}
