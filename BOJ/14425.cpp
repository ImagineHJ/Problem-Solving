#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    unordered_set<string> s;
    int n, m, ans=0; cin>>n>>m;
    while(n--){
        string st; cin>>st;
        s.insert(st);
    }
    while(m--){
        string st; cin>>st;
        if(s.find(st)!=s.end()) ans++;
    }
    cout<<ans;
    return 0;
}

