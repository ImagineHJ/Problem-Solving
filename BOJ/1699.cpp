#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

int dp[100001];

int findSquare(int n){
    if(n==0) return 0;
    if(dp[n]>0) return dp[n];
    
    int minS = (int)sqrt(n), minR = n;
    for(int i=minS; i>0; i--) minR = min(minR, 1+findSquare(n-i*i));
    dp[n] = minR;
    return minR;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    cin>>n;
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    cout<<findSquare(n);
    
    return 0;
}
