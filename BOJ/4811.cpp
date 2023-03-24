#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n;
long long dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    dp[0][0] = 1;
    for(int i=0; i<=30; i++){
        for(int j=0; j<=30; j++){
            if(i==0 && j!=0) dp[i][j] = dp[i][j-1];
            else if(i!=0 && j==0) dp[i][j] = dp[i-1][j+1];
            else if(i!=0 && j!=0)dp[i][j] = dp[i-1][j+1] + dp[i][j-1];
        }
    }
    cin>>n;
    while(n!=0){
        cout<<dp[n][0]<<'\n';
        cin>>n;
    }
    
    return 0;
}
