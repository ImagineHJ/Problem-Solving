#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using  namespace std;

struct comp{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.second<b.second;
    }
};

int n, m, s, e, ans = 0;
int road[100001];
vector<pair<int, int>> graph[100001];

int dijkstra(){
    // init
    for(int i=1; i<=n; i++) road[s] = 0;
    road[s] = INF;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    
    for(int i=0; i<graph[s].size(); i++){
        road[graph[s][i].first] = graph[s][i].second;
        pq.push(graph[s][i]);
    }
    
    // dijkstra
    int now, nowc, next, nextc;
    while(!pq.empty()){
        now = pq.top().first; nowc = pq.top().second; pq.pop();
        if(now==e) return nowc; // found answer
        if(road[now]>nowc) continue; // already visited
        
        road[now] = nowc;
        for(int i=0; i<graph[now].size(); i++){
            next = graph[now][i].first; nextc = min(nowc, graph[now][i].second);
            if(road[next]<nextc){
                road[next]=nextc;
                pq.push({next, nextc});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin>>s>>e;
    
    int ans = dijkstra();
    cout<<ans;
    
    return 0;
}
