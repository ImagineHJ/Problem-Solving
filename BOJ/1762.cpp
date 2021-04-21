#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, b=0; cin>>n>>m;
    set<string> see, seehear;
    
    while(n--){
        string name; cin>>name;
        see.insert(name);
    }
    while(m--){
        string name; cin>>name;
        if(see.find(name)!=see.end()){
            seehear.insert(name);
            b++;
        }
    }
    cout<<b<<'\n';
    for(auto &k:seehear){
        cout<<k<<'\n';
    }
    
    return 0;
}
