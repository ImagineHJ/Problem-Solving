#include <iostream>
#include <stack>

using  namespace std;
int n, m, v;
int vis[1001];
int adj[1001][1001];

void dfs(int v){
    stack<int> st;
    st.push(v);
    vis[v]=1;
    cout<<v<<" ";
    
    while(!st.empty()){
        int now=st.top();
        bool can_go=false;
        for(int i=0; i<=n; i++){
            if( (vis[i]==0) && (adj[now][i]==1)){
                vis[i]=1;
                can_go=true;
                st.push(i);
                cout<<i<<" ";
                break;
            }
        }
        if(!can_go) st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m>>v;
    
    
    return 0;
}
