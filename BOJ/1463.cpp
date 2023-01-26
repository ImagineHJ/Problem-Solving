//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int dp[1000001];


int make_one(int x){
    int cnt;
    
    if(x==1) return 0;
    if(dp[x]!=0) return dp[x];
    
    cnt = 1 + make_one(x-1);
    
    // if(x%5 == 0 && cnt > 1 + make_one(x/5)) cnt = 1 + make_one(x/5);
    
    if (x%3 == 0 && cnt > 1 + make_one(x/3)) cnt = 1 + make_one(x/3);
    
    if (x%2 == 0 && cnt > 1 + make_one(x/2)) cnt = 1 + make_one(x/2);
    
    dp[x] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int x;
    cin>>x;
    cout<<make_one(x)<<endl;
    
    return 0;
}
