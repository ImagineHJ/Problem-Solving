#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m; cin>>n>>m;
    string num[100001];
    map<string, int> name;
    
    for(int i=1; i<=n; i++){
        string n; cin>>n;
        name.emplace(n, i);
        num[i]= n;
    }
    
    while(m--){
        string st; cin>>st;
        if('0'<=st[0] && st[0]<='9'){
            int t=stoi(st);
            cout<<num[t]<<'\n';
        }
        else
            cout<<name[st]<<'\n';
    }
    
    return 0;
}
