#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    vector<int> node[MAX+1];
    int visited[MAX+1]={0,};
    int parent[MAX+1];
    int n; cin>>n;
    
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    queue<int> q;
    
    q.push(1);
    
    while(!q.empty()){
        int n;
        
        n=q.front();
        q.pop();
        visited[n]=1;
        for(int i=0; i<node[n].size(); i++){
            if(visited[node[n][i]]==0){
                parent[node[n][i]]=n;
                q.push(node[n][i]);
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
    
    return 0;
}

