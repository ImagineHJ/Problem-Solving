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

int root[201];

int find_root(int a){
    int ret;
    if(root[a]==a) return a;
    
    ret = find_root(root[a]);
    root[a] = ret;
    return ret;
}

void do_union(int a, int b){
    int a_r, b_r;
    a_r = find_root(a);
    b_r = find_root(b);
    if(a_r > b_r) root[a_r] = root[b_r];
    else root[b_r] = root[a_r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a, prev, flag;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++) root[i]=i;

    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            if(a==1){
                do_union(i, j);
            }
        }
    }
    
    flag = 1;
    for(int i=0; i<m; i++){
        cin>>a;
        if(i!=0 && find_root(prev)!=find_root(a)){ // not in same set == not connected
            flag = 0;
            break;
        }
        prev = a;
    }
    
    
    if(flag == 0) cout<<"NO";
    else cout<<"YES";
    return 0;
}
