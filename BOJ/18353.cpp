//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/07.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using namespace std;
int dp[2001];
vector<int> soldiers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, max_dp = 0;
    cin>>n;
    soldiers.push_back(0);
    for(int i=0; i<n; i++){
        cin>>a;
        soldiers.push_back(a);
        dp[i] = 1;
    }
    dp[0] = 0;
    dp[1] = 1; max_dp = 1;
    for(int i=2; i<=n; i++){
        for(int j=i-1; j>=1; j--){
            if(soldiers[j]>soldiers[i]){
                dp[i] = max(dp[i], dp[j]+1); // find the maximum value
            }
        }
        max_dp = max(max_dp, dp[i]);
    }
    cout<<n-max_dp;
    
    return 0;
}
