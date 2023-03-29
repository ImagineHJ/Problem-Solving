#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

bool visit[10001];
vector<int> graph[10001];
int n, m;

int howMany(int i){
    int ret=1;
    visit[i] = true;
    for(int j=0; j<graph[i].size(); j++){
        if(!visit[graph[i][j]]) ret += howMany(graph[i][j]);
    }
    return ret;
}

void initVisit(){
    for(int i=1; i<=n; i++) visit[i]=false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[b].push_back(a);
    }
    
    vector<int> ans;
    int v, maxV = 0;
    
    for(int i=1; i<=n; i++){
        initVisit();
        v = howMany(i);
        if(v>maxV){
            ans.clear();
            ans.push_back(i);
            maxV = v;
        }
        else if(v==maxV){
            ans.push_back(i);
        }
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    
    return 0;
}
