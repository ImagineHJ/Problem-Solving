//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int parent[100001];

int find_root(int a){
    int ret;
    if(parent[a]==a) return a;
    ret = find_root(parent[a]);
    parent[a] = ret;
    
    return ret;
}

void do_union(int a, int b){
    int a_p, b_p;
    
    a_p = find_root(a); b_p = find_root(b);
    if(a_p>b_p) parent[a_p] = b_p;
    else parent[b_p] = a_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int a, g, p, a_p, cnt=0;
    cin>>g>>p;
    
    for(int i=0; i<=g; i++){
        parent[i] = i;
    }
    
    for(int i=0; i<p; i++){
        cin>>a;
        a_p = find_root(a); // find the largest gate smaller than a
        if(a_p==0) break; // cannot dock
        
        do_union(a_p, a_p-1); // do docking
        cnt++; // count planes
    }
    cout<<cnt;
    
    return 0;
}
