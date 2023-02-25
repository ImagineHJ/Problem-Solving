#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
struct edge{
    int node;
    int cost;
};

vector<edge> edges[100001];
bool visited[100001];
long long ans = 0;

long long farthest_child_from_root(int root, int parent){
    long long res = 0, max1=0, max2=0; // get two maximum cost
    edge now;
    
    for(int i=0; i<edges[root].size(); i++){
        now = edges[root][i];
        if(now.node == parent) continue; // parent already visited
        res = farthest_child_from_root(now.node, root)+now.cost;
        if(res>max1){
            max2 = max1;
            max1 = res;
        }
        else if(res>max2){
            max2 = res;
        }
    }
    ans = max(ans, max1+max2); // get maximum diameter
    
    return max1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    edge e;
    
    int v, a, b, c;
    cin>>v;
    for(int i=0; i<v; i++){
        cin>>a>>b;
        while(b!=-1){
            cin>>c;
            e.node = b; e.cost = c;
            edges[a].push_back(e);
            cin>>b;
        }
    }
    farthest_child_from_root(a, a);
    cout<<ans;
    
    return 0;
}

