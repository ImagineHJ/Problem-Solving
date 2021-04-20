#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    map<int, string> num;
    unordered_map<string, int> name;
    
    int n, l; cin>>n>>l;
    
    for(int i=1; i<=l; i++){
        string stu; cin>>stu;
        num.emplace(i, stu);
        
        if(name.find(stu)==name.end()) name.emplace(stu, i);
        else name[stu]=i;
    }
    
    int cnt=0;
    for(auto &k:num){
        if(cnt>=n) break;
        int n=k.first; string s=k.second;
        if(n==name[s]) {cout<<s<<'\n'; cnt++;}
    }
    
    return 0;
}
