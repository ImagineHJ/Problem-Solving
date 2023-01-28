//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using  namespace std;

int route[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a, b, c;
    cin>>n>>m;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==j) route[i][j]=0;
            else route[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(route[a][b]>c) route[a][b] = c; // save the smallest cost
    }
    
    // floyed warshall
    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            for(int k=1; k<n+1; k++)
                route[j][k] = min(route[j][k], route[j][i]+route[i][k]);
            
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if (route[i][j]==INF) cout<<0<<" "; // no path
            else cout<<route[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    
    return 0;
}
