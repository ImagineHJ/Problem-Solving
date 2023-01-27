//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, k, a, min, coin;
    vector<int> coins;
    int dp[10001];
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        cin>>a;
        coins.push_back(a);
    }
    sort(coins.begin(),coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end()); // remove duplicate
    
    dp[0]=0;
    for(int i=1; i<k+1; i++){
        min = 10001;
        for(int j=0; j<coins.size(); j++){
            coin = coins[j];
            if(i>=coin && dp[i-coin]!=-1 && min>dp[i-coin] + 1) min = dp[i-coin] + 1;
        }
        if(min == 10001) dp[i]=-1; // no way
        else dp[i]  = min;
    }
    
    cout<<dp[k]<<endl;
    
    return 0;
}
