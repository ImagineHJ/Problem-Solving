//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<long long> house;
long long a, n, c;

// check if we can install the wifi with minimum m distance
bool check_install(long long m){
    long long cnt=1, prev;
    prev = house[0];
    for(int i=1; i<n; i++){
        if(house[i]-prev>=m){
            cnt++; // install here
            prev = house[i];
        }
    }
    if(cnt>=c) return true;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    cin>>n>>c;
    
    for(int i=0; i<n; i++){
        cin>>a;
        house.push_back(a);
    }
    sort(house.begin(), house.end());
    
    long long start, end, mid, dist=1;
    start = 1; // smallest distance possible
    end = house[house.size()-1]-house[0]; // largest distance possible
    while(start<=end){
        mid = (start+end)/2; // find the most appropriate mid distance
        if(check_install(mid)){
            dist = mid; // save the distance that worked for c num of houses
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    cout<<dist;
    
    return 0;
}
