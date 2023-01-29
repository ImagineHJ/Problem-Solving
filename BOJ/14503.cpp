//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

int map[500][500];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int left_direction(int d){
    if(d==0) return 3;
    return d-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a, x, y, d, new_x, new_y, new_d, left_cnt=0, cnt = 0;
    
    cin>>n>>m;
    cin>>x>>y>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a;
            map[i][j] = a;
        }
    }
    
    map[x][y]=2; cnt++;
    while(true){
        new_d = left_direction(d);
        new_x = x+dx[new_d]; new_y = y+dy[new_d];
        left_cnt++;
        if(left_cnt==5){
            left_cnt = 0;
            x = x+dx[(d+2)%4]; y = y+dy[(d+2)%4]; // go backwards
            if(map[x][y]==1) break; // cannot go backwards -> end
            else continue;
        }
        if(map[new_x][new_y]==0){
            d=new_d; x=new_x; y=new_y;
            map[new_x][new_y] = 2;
            cnt ++;
            left_cnt = 0;
        }
        else{
            d = new_d;
        }
    }
    
    cout<<cnt;
    
    return 0;
}
