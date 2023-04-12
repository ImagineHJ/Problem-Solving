#include <iostream>
#include <vector>
#define INF 1e9
using  namespace std;

int n, amount=0;
vector<pair<int, int>> coins;

int solve(int half){
    int dp[half+1];
    for(int i=0; i<=half; i++) dp[i]=0;
    dp[0] = 1;
    
    int coin, num;
    for(int i=0; i<n; i++){
        coin = coins[i].first; num = coins[i].second;
        for(int j=half; j>=0; j--){
            if(dp[j]==1){
                for(int k=1; k<=num; k++){
                    if(j+coin*k<=half) dp[j+coin*k]=1;
                }
            }
        }
    }
    if(dp[half]==1) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, b, ans;
    for(int t=0; t<3; t++){
        // init
        amount = 0; coins.clear();
        
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            amount += a*b;
            coins.push_back({a, b});
        }
        
        if(amount%2==1) ans = 0;
        else ans = solve(amount/2);
        cout<<ans<<'\n';
    }
    
    return 0;
}
