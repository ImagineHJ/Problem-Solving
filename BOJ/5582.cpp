#include <iostream>
#define INF 1e18
using namespace std;

int dp[4001][4001];
string s, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int ans = 0;
    
    cin>>s>>w;
    
    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=w.size(); j++){
            if(s[i-1]==w[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout<<ans;
    
    return 0;
}
