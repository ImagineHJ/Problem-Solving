#include <iostream>
using  namespace std;

int k, n, f;
int graph[901][901];
bool visited[901];
bool found = false;

bool allfriends(int a){
    for(int i=1; i<=n; i++){
        if(visited[i]==1 && graph[i][a]==0) return false;
    }
    return true;
}

void dfs(int start, int cnt){

    // include
    visited[start] = true;
    
    if(!found && cnt+1==k){ // found
        found = true;
        return;
    }
    
    for(int i=start+1; i<=n; i++){
        if(allfriends(i)){
            dfs(i, cnt+1);
            if(found) return;
            break;
        }
    }
    visited[start] = false;
    // exclude
    for(int i=start+1; i<=n; i++){
        if(allfriends(i)){
            dfs(i, cnt);
            if(found) return;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>k>>n>>f;
    int a, b;
    for(int i=0; i<f; i++){
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    dfs(1, 0);
    
    if(found){
        for(int i=1; i<=n; i++){
            if(visited[i]==1) cout<<i<<'\n';
        }
    }
    else{
        cout<<-1;
    }
    
    return 0;
}
