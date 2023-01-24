//
//  main.cpp
//  2-3 Number Card Game
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
    
    int a, n, m, min = 0;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        min = 10000;
        for(int j=0; j<m; j++){
            cin>>a;
            if(min > a) min=a;
        }
        // save the min value in each row
        vec.push_back(min);
    }
    sort(vec.rbegin(), vec.rend());
    
    // print the maximum value
    std::cout << vec[0] << endl;
    return 0;
}

