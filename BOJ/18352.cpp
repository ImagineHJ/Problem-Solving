//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/25.
//

#include <iostream>
#include <vector>
#include <queue>
using  namespace std;
# define MAX 300001


vector<int> adj[MAX];
int length[MAX];
int n, m, k, x, a, b;

void bfs(int start){
    int parent, child;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        parent = q.front(); q.pop();
        for(int i=0; i<adj[parent].size(); i++){ // for each child node
            child = adj[parent][i];
            // when not visited
            if((child!=x && length[child]==0)) {
                length[child] = length[parent] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m>>k>>x;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    length[x] = 0;
    bfs(x);
    
    // output
    bool out = false;
    for(int i=1; i<n+1; i++){
        if(length[i]==k) {
            cout << i << endl;
            out = true;
        }
    }
    if(!out) {cout << -1 << endl;}
    return 0;
}
