#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 1e9
using namespace std;

vector<int> num;
unordered_map<int, int> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, s, a;
    
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>a;
        num.push_back(a);
    }
    
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        v.clear();
        for (auto j : um) {
            v.push_back({j.first+num[i], j.second});
        }
        v.push_back({num[i], 1});
        for(int j=0; j<v.size(); j++) {um[v[j].first]+=v[j].second;}
    }
    cout<<um[s];
    
    return 0;
}
