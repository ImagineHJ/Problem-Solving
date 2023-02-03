//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
long long triangle[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    long long n, a, ret=0;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>a;
            triangle[i][j] = a;
        }
    }
    ret = triangle[0][0]; // when n==1
    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0) triangle[i][j] += triangle[i-1][j];
            else if(j==i) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]); // choose the largest sum
            ret = max(ret, triangle[i][j]);
        }
    }
    
    cout<<ret;
    return 0;
}
