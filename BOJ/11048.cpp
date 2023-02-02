//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18
using namespace std;

int map[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            cin>>a;
            map[i][j] = a;
        }
    }

    for(int i=1; i<n; i++) map[i][0] += map[i-1][0];
    for(int j=1; j<m; j++) map[0][j] += map[0][j-1];
    
    for(int i=1; i<n; i++){
        for(int j=1;j<m; j++){
            map[i][j] += max({map[i-1][j], map[i][j-1], map[i-1][j-1]});
        }
    }
    cout<<map[n-1][m-1];
    
    return 0;
}
