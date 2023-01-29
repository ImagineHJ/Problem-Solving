//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

vector<int> graph[501];
int cost[501];
int pointing_me[501];
int total_cost[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, b, now, now_next;
    queue<int> q;
    cin>>n;
    
    for(int i=1; i<n+1; i++){
        cin>>a;
        cost[i]=a;
        while(true){
            cin>>b;
            if(b==-1) break;
            graph[b].push_back(i);
            pointing_me[i]++;
        }
    }
    
    for(int i=1; i<n+1; i++){
        if(pointing_me[i]==0){ // for building without prerequisites
            q.push(i);
            total_cost[i] = cost[i];
        }
    }
    while(!q.empty()){ // topological sorting
        now = q.front(); q.pop();
        for(int i=0; i<graph[now].size(); i++){
            now_next = graph[now][i];
            pointing_me[now_next]--; // delete edge
            total_cost[now_next] = max(total_cost[now_next], total_cost[now]); // save max of total cost for the previos building
            if(pointing_me[now_next] == 0){
                q.push(now_next);
                total_cost[now_next] += + cost[now_next]; // calculate the final total cost
            }
        }
    }
    for(int i=1; i<n+1; i++){
        cout<<total_cost[i]<<'\n';
    }
    
    return 0;
}
