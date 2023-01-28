//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e18

using  namespace std;
vector<pair<int, int>> graph[10001];
long long cost[10001];
int visited[10001];
int cnt;

struct cmp {
  bool operator()(pair<int, long long> a, pair<int, long long> b) {
      return a.second > b.second;
  }
};

long long dijkstra(int start){
    priority_queue <pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
    long long now,now_cost, new_cost, max=0;
    
    cnt = 0 ;
    pq.push(make_pair(start, 0));
    while(!pq.empty()){
        now = pq.top().first;
        now_cost = pq.top().second;
        pq.pop();
        
        // cout<<now<<" "<<now_cost<<endl;
        
        if (visited[now]!=0) continue;
        
        visited[now] = 1; cnt++;
        for(int i=0; i<graph[now].size(); i++){
            new_cost = now_cost + graph[now][i].second;
            // cout<<graph[now][i].first<<"&"<<graph[now][i].second<<"&"<<new_cost<<"&"<<cost[graph[now][i].first]<<" ";
            if( cost[graph[now][i].first] > new_cost){
                cost[graph[now][i].first] = new_cost;
                pq.push(make_pair(graph[now][i].first, new_cost));
            }
        }
        max = cost[now];
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, d, c, a, b, s, test;
    long long ret;
    cin>>test;
    
    for(int t=0; t<test; t++){

        cin>>n>>d>>c;
        
        for(int i=1; i<n+1; i++) graph[i].clear();
        
        for(int i=0; i<d; i++){
            cin>>a>>b>>s;
            graph[b].push_back(make_pair(a, s));
        }
        
        // initialize
        for(int i=1; i<n+1; i++){
            cost[i] = INF;
            visited[i] = 0;
        }
        cost[c] = 0;
        
        ret = dijkstra(c);
        cout<<cnt<<" "<<ret<<'\n';
    }
    return 0;
}
