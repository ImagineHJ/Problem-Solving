#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
vector<int> graph[1001];
int indegree[1001];

int toInt(string s){
    int ret = 0, digit = 1;
    
    for(int i=s.size()-1; i>=0; i--){
        ret += (s[i]-'0')*digit;
        digit *= 10;
    }
    return ret;
}

void makeGraph(string s){
    vector<int> v;
    int start = 0;
    
    // turn string into int vector
    for(int j=0; j<s.size(); j++){
        if(s[j]==' '){
            v.push_back(toInt(s.substr(start, j-start)));
            start = j+1;
        }
    }
    v.push_back(toInt(s.substr(start, s.size()-start)));
    
    if(v.size()<2) return;
    
    // make graph
    int now, prev = v[1];
    for(int j=2; j<v.size(); j++){
        now = v[j];
        graph[prev].push_back(now);
        indegree[now]++;
        prev = now;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    cin.ignore();
    
    string s;
    for(int i=0; i<m; i++){
        getline(cin, s);
        makeGraph(s);
    }
    
    // topological sort
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }
    int now;
    while(!q.empty()){
        now = q.front(); q.pop();
        ans.push_back(now);
        for(int i=0; i<graph[now].size(); i++){
            indegree[graph[now][i]]--;
            if(indegree[graph[now][i]]==0) q.push(graph[now][i]);
        }
    }
    if(ans.size()!=n) cout<<0;
    else{
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<'\n';
        }
    }
    
    return 0;
}
