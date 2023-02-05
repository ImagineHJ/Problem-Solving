//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int _time[16];
int _pay[16];
int dp[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, b;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        _time[i] = a; _pay[i] = b;
    }
    dp[n+1] = 0;
    for(int i=n; i>0; i--){
        if(i+_time[i]<=(n+1)){ // if available to do work starting on the ith day
            dp[i] = _pay[i] + dp[i+_time[i]]; // calculate the max pay when bj does work starting from ith day
        }
        dp[i] = max(dp[i], dp[i+1]); // max payment
    }
    cout<<dp[1];
    
    return 0;
}
