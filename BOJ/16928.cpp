#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;

int snakeLadder[101];
vector<int> dp(101, INF);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    int a, b;
    for(int i=0; i<n+m; i++){
        cin>>a>>b;
        snakeLadder[a] = b;
    }
    
    int jump;
    dp[1] = 0;
    for(int i=1; i<=100; i++){
        jump = snakeLadder[i];
        if(jump>0) dp[jump] = min(dp[jump], dp[i]);
        else{
            for(int j=1; j<=6; j++){
                if(i+j<=100) dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
    }
    for(int i=1; i<=100; i++){
        jump = snakeLadder[i];
        if(jump>0) dp[jump] = min(dp[jump], dp[i]);
        else{
            for(int j=1; j<=6; j++){
                if(i+j<=100) dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
    }
    cout<<dp[100];
    
    return 0;
}
