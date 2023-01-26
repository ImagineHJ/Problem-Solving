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
    
    int a, n;
    vector<int> stock;
    int dp[10000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        stock.push_back(a);
    }
    
    dp[0] = stock[0];
    dp[1] = stock[0]+stock[1];
    for(int i=2; i<n; i++){
        dp[i] = max({dp[i-1], dp[i-2]+stock[i], dp[i-3]+stock[i-1]+stock[i]});
    }
    
    cout<<dp[n-1]<<endl;
    
    return 0;
}
