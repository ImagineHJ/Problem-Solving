#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m; cin>>n>>m;
    unordered_map <string, vector<string>> group;
    unordered_map <string, string> name;
    
    while(n--){
        string team; cin>>team;
        int num; cin>>num;
        
        while(num--){
            string member; cin>>member;
            group[team].push_back(member);
            name.emplace(member, team);
        }
        sort(group[team].begin(), group[team].end());
    }
    
    while(m--){
        string quiz; cin>>quiz;
        
        int type; cin>>type;
        
        if(type==0)
            for(auto &k:group[quiz]) cout<<k<<'\n';
    
        else
            cout<<name[quiz]<<'\n';
    }
    
    return 0;
}

