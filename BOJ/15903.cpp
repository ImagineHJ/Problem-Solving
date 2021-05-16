#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    int n, m;
    long long ans=0;
    cin>>n>>m;;
    
    while(n--){
        int num; cin>>num;
        pq.push(num);
    }
    while(m--){
        long long x, y, sum;
        x=pq.top(); pq.pop();
        y=pq.top(); pq.pop();
        sum=x+y;
        pq.push(sum); pq.push(sum);
    }
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
    
    return 0;
}
