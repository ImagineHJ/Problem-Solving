//
//  main.cpp
//  2-4 Until it becomes 1
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
    
    int n, k, cnt = 0;
    cin>>n>>k;
    
    while(n>1 && n>k){
        // count process number 1
        cnt += n - ((n/k) * k);
        
        // count process number 2
        cnt ++;
        
        // value after process 1 and 2
        n = n/k;
    }
    
    // when n is smaller than k, count process number 1
    cnt += (n-1);
    std::cout << cnt << endl;
    return 0;
}
