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
vector<int> v;

int fix_point_search(int start, int end){
    int mid;
    
    while(start<=end){
        mid = (start+end)/2;
        if(mid == v[mid]) return mid; // found fixed point
        else if(mid>v[mid]) start=mid+1;
        else if(mid<v[mid]) end = mid-1;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    
    int n, a;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }

    cout<<fix_point_search(0, v.size()-1);
    return 0;
}
