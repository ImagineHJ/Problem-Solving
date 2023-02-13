#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 1e18
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    unordered_map<int, bool> um;
    int n, m, a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        um[a] = true; // hash map
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>a;
        if(um[a]) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}
