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
int cnt[11];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n, m, a, ans=0;
    
    vector<int> balls;
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a;
        balls.push_back(a);
        cnt[a]++;
    }
    for(int i=0; i<n; i++){
        ans += (n - i - cnt[balls[i]]);
        cnt[balls[i]]--; // delete cases already choosed before
    }
    cout<<ans;
    
    return 0;
}
