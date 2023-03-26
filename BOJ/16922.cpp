#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define INF 1e9
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    set<int> ans;
    cin>>n;
    
    for(int i=0; i<=n; i++){
        for(int v=0; v<=n-i; v++){
            for(int x=0; x<=n-i-v; x++){
                ans.insert(i*1+v*5+x*10+(n-i-v-x)*50);
            }
        }
    }
    cout<<ans.size();
    
    return 0;
}
