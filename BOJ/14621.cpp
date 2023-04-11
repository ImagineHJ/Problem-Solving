#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

struct road{
    int u; int v; int d;
};

struct comp{
    bool operator()(road a, road b){
        return a.d>b.d;
    }
};

int n, m;
int parent[1001];
char gender[1001];
priority_queue<road, vector<road>, comp> pq;

int getParent(int a){
    int ret;
    if(parent[a]==a) return a;
    ret = getParent(parent[a]);
    parent[a] = ret;
    return ret;
}

void doUnion(int a, int b){
    int ap = getParent(a), bp = getParent(b);
    
    if(ap>bp) parent[ap] = bp;
    else parent[bp] = ap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>gender[i];
        parent[i] = i; //init
    }
    
    road r;
    for(int i=0; i<m; i++){
        cin>>r.u>>r.v>>r.d;
        if(gender[r.u]==gender[r.v]) continue; // roads connecting same gender -> ignore
        pq.push(r);
    }
    
    int ans = 0, cnt = 0;
    while(!pq.empty() && cnt<n-1){ // MST
        r = pq.top(); pq.pop(); // get the min road
        if(getParent(r.u)!=getParent(r.v)){
            ans += r.d; cnt++;
            doUnion(r.u, r.v);
        }
    }
    if(cnt<n-1) cout<<-1;
    else cout<<ans;
    
    return 0;
}
