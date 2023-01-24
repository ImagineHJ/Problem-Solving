//
//  main.cpp
//  2-2 Big Number
//
//  Created by JinnyLim on 2023/01/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    vector<int> vec;
    
    int a, n, m, k, ans = 0;
    cin>>n>>m>>k;
    
    // input
    for(int i=0; i<n; i++){
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.rbegin(), vec.rend());
    
    int cnt = 0;
    
    for(int i=0; i<m; i++){
        // add the largest number
        if(cnt < k){
            ans += vec[0];
            cnt ++;
        }
        // add the second largest number
        else{
            ans += vec[1];
            cnt = 0;
        }
    }
    
    /*
     // faster version
     cnt = ( m / (k+1)) * k;
     cnt += m % (k+1);
     
     ans += cnt * vec[0];
     ans += (m-cnt) * vec[1];
    */
    
    std::cout << ans << endl;
    return 0;
}
