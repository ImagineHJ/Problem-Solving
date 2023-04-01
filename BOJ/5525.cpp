#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

vector<int> graph[32001];
int indegree[32001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int m, a, b;
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }
    
    int now;
    while(!q.empty()){
        now = q.front(); q.pop();
        cout<<now<<" ";
        for(int i=0; i<graph[now].size(); i++){
            if(--indegree[graph[now][i]] == 0) q.push(graph[now][i]);
        }
    }
    
    return 0;
}
