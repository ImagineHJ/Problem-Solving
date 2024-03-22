#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, m;

struct edge{
    int v;
    int cost;
};
vector<edge> graph[1001];


struct comp{
    bool operator()(edge x, edge y){
        return x.cost>y.cost;
    }
};

long long dijkstra(int a, int b){
    long long dist[1001];
    
    for(int i=1; i<=n; i++) dist[i]=INT_MAX;
    
    priority_queue<edge, vector<edge>, comp> pq;
    
    int cur, curcost, next, nextcost;
    dist[a] = 0;
    pq.push({a, 0});
    while(!pq.empty()){
        cur = pq.top().v;
        curcost = pq.top().cost;
        pq.pop();
        if(cur==b) return dist[b];
        for(int i=0; i<graph[cur].size(); i++){
            next = graph[cur][i].v;
            nextcost = graph[cur][i].cost + curcost;
            if(dist[next]<=nextcost) continue; //visited
            dist[next] = nextcost;
            pq.push({next, nextcost});
        }
    }
    return dist[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    int a, b, c, d, e;
    for(int i=0; i<m; i++){
        cin>>c>>d>>e;
        graph[c].push_back({d, e});
        graph[d].push_back({c, e});
    }
    cin>>a>>b;
    
    long long A, B, C;
    A = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, n);
    B = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, n);
    C = min(A, B);
    if(C>=INT_MAX) cout<<-1;
    else cout<<C;
}
