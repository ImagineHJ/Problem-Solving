#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

vector<int> tree[1000001];
bool isEarlyAdapter[1000001];
int ans = 0;

// dfs
void choose(int root, int par){
    int child;
    bool childNeedEarlyAdapter = false;
    for(int i=0; i<tree[root].size(); i++){
        child = tree[root][i];
        if(child!=par){
            choose(child, root);
            if(!isEarlyAdapter[child]) childNeedEarlyAdapter = true;
        }
    }
    if(childNeedEarlyAdapter) {
        isEarlyAdapter[root] = true;
        ans++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, b;
    cin>>n;
    
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    choose(1, -1);
    cout<<ans;
    
    return 0;
}
