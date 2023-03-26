#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, k;
vector<int> trains;
int dp[4][50001];

int kTrains(int k, int i){
    if(i==0) return trains[i+k-1];
    return trains[i+k-1]-trains[i-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, add = 0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a; add+=a;
        trains.push_back(add);
    }
    cin>>k;
    
    dp[1][k-1] = trains[k-1];
    dp[2][2*k-1] = trains[2*k-1];
    dp[3][3*k-1] = trains[3*k-1];
    for(int i=0; i<4; i++){
        for(int j=i*k; j<n; j++){
            if(i==0) dp[i][j] = 0;
            else dp[i][j] = max(dp[i][j-1], kTrains(k, j-k+1)+dp[i-1][j-k]);
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    
    cout<<dp[3][n-1];
    
    return 0;
}
