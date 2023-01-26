//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    vector<int> stock;
    int dp[10001];
    cin>>n;
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}
