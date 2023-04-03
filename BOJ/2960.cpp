#include <iostream>
#include <set>
#include <algorithm>
#define INF 1e9
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    set<int> s;
    int n, k, cnt=0, now, ans;
    
    cin>>n>>k;
    for(int i=2; i<=n; i++) s.insert(i);
    
    while(s.size()>0 || cnt<k){
        now = *s.begin(); // smallest num remaining
        s.erase(now);
        cnt++;
        if(cnt==k) {ans=now;break;}
        for(int i=now*2; i<=n; i+=now){ // delete multiples of now
            if(s.find(i)!=s.end()){
                s.erase(i);
                cnt++;
                if(cnt==k) {ans = i; break;}
            }
        }
    }
    
    cout<<ans;
    
    return 0;
}
