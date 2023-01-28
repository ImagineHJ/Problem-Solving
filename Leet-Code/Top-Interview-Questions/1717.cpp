//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18

using  namespace std;
int parent[1000001];

int find_parent(int c){
    if (parent[c]==c) return c;
    
    parent[c] = find_parent(parent[c]); // save root
    return parent[c];
}

void do_union(int a, int b){
    int a_p, b_p;
    a_p = find_parent(a);  b_p = find_parent(b);
    if(a_p > b_p) parent[a_p] = parent[b_p];
    else parent[b_p] = parent[a_p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, c, a, b;
    cin>>n>>m;
    
    for(int i=0; i<n+1; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<m; i++){
        cin>>c>>a>>b;
        if(c==0) {
            do_union(a, b); // union a, b
        }
        else { // check if both are in the same set
            if(find_parent(a) == find_parent(b)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    
    return 0;
}
