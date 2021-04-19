#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    priority_queue<int, vector<int>, greater<int>> sub;
    
    int n, m, sum=0, ans=0; cin>>n>>m;;
    
    for(int i=0; i<n; i++){
        priority_queue<int, vector<int>, greater<int>> pq;
        int p, l, cnt; cin>>p>>l;
        cnt=p-l;
        
        while(p--) {
            int m; cin>>m;
            pq.push(m);
        }
        if(cnt<0) {sub.push(1); continue;}
        while(cnt--){
            pq.pop();
        }
        sub.push(pq.top());
    }
    while(ans<n){
        sum+=sub.top();
        if(sum>m) break;
        ans++;
        sub.pop();
    }
    cout<<ans;
    
    return 0;
}
