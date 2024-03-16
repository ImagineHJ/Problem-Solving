#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[500001];
int visited[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    long long n, w;
    int a, b, child=0;
    
    cin>>n>>w;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    int cur, has_child;
    
    while(!q.empty()){ // BFS to find leaf node
        cur = q.front();
        q.pop();
        visited[cur]=1;
        has_child=0;
        for(int i=0; i<graph[cur].size(); i++){
            if(!visited[graph[cur][i]]){
                q.push(graph[cur][i]);
                has_child=1;
            }
        }
        if(has_child==0) child++; // leaf node
    }
    double ans = (double)w/child;
    cout.precision(10);
    cout<<ans;

    
}
