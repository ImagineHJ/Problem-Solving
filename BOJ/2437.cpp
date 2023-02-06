//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, min_num;
vector<int> num, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int a;
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    
    sum.push_back(0);
    min_num = 1;
    for(int i=0; i<n; i++){
        if(min_num<num[i]) break;
        min_num += num[i];
    }
    cout<<min_num;
    
    return 0;
}
