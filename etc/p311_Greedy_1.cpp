//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    vector<int> explorer;
    int n, a, cnt, ret=0 ;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;
        explorer.push_back(a);
    }
    sort(explorer.begin(), explorer.end());

    cnt = 0;
    for(int i=0; i<explorer.size(); i++){
        cnt++;
        if(cnt >= explorer[i]) { // group made
            ret ++;
            cnt = 0;        }
    }
    cout<<ret;
    
    return 0;
}
