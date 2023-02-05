//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int parent[200001];

struct road{
    int x;
    int y;
    int len;
};

bool comp(road a, road b){
    return a.len<b.len;
}

int find(int a){
    int ret;
    
    if(parent[a]==a) return a;
    ret = find(parent[a]);
    parent[a] = ret;
    return ret;
}

void do_union(int a_p, int b_p){
    if(a_p>b_p) parent[a_p] = b_p;
    else parent[b_p] = a_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    vector<road> v;
    int m, n, x, y, l, x_p, y_p, cnt=0;
    long long total_len = 0, min_len = 0;
    road r;
    
    while(1){
        
        v.clear();
        cnt = 0; total_len = 0; min_len = 0;
        
        cin>>m>>n;
        
        if(m==0 && n==0) break;
        
        for(int i=0; i<n; i++){
            cin>>x>>y>>l;
            r.x=x; r.y=y; r.len=l;
            v.push_back(r);
            total_len += l;
        }
        for(int i=0; i<m; i++) parent[i] = i;
        
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<n; i++){
            x = v[i].x; y = v[i].y; l = v[i].len;
            x_p = find(x); y_p = find(y);
            if(x_p!=y_p){ // not connected
                min_len+=l;
                cnt++;
                do_union(x_p, y_p);
            }
            if(cnt == m-1) break;
        }
        cout<<total_len-min_len<<'\n';
    }
    return 0;
}
