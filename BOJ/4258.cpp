#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    cout.precision(4); cout<<fixed;
    
    map<string, int> trees;
    int total=0;
    string name;
    
    while(getline(cin, name)){
        if(cin.eof()) break;
        total++;
        if(trees.find(name)!=trees.end()) trees[name]++;
        else trees.emplace(name, 1);
    }
    
    for(auto &k:trees){
        cout<<k.first<<' '<< k.second/double(total)*100 <<'\n';
    }
    
    return 0;
}

/*
#include <iostream>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    unordered_map<string, int> trees;
    set<string> n;
    int total=0;
    string name;
    
    while(getline(cin, name)){
        if(cin.eof()) break;
        total++;
        if(trees.find(name)!=trees.end()) trees[name]++;
        else trees.emplace(name, 1);
    }
    
    for(auto &k:trees)
        n.insert(k.first);
    for(auto &k:n){
        double percent=(trees[k]/double(total)*100);
        cout.precision(4); cout<<fixed;
        cout<<k<<' '<< round(percent*10000)/10000 <<'\n';
        
    }
    
    return 0;
}
*/


