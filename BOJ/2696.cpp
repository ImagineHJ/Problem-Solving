#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define INF 1e9
using namespace std;

int mid;
priority_queue<int> large;
priority_queue<int, vector<int>, greater<int>> small;

void add(int n){
    if(mid<=n) small.push(n); // smaller or same value to mid
    else large.push(n); // larger value to mid
  
    if(small.size()>large.size()){ // small values are more than large values -> mid need to be small
        large.push(mid);
        mid = small.top(); small.pop();
    }
    else if(large.size()-small.size()>1){ // large values are more than small values(1 difference if okay if large values are more) -> mid need to be large
        small.push(mid);
        mid = large.top(); large.pop();
    }
}

void init(){
    while(!small.empty()) small.pop();
    while(!large.empty()) large.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int test, m, a;
    cin>>test;
    vector<int> res;
    for(int t=0; t<test; t++){
        init();
        cin>>m;
        cin>>a; mid = a; res.push_back(mid);
        for(int i=2; i<=m; i++){
            cin>>a; add(a);
            if(i%2==1) res.push_back(mid);
        }
        // print result
        cout<<res.size()<<'\n';
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
            if(i%10==9) cout<<'\n';
        }
        cout<<'\n';
        res.clear();
    }
    
}
