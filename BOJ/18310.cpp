//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int num[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    long long n, a, b, dist, prev, min_dist=0, min_house=0 ;
    vector<long long> house;
    cin>>n;
    for(int i=0; i <n; i++){
        cin>> a;
        house.push_back(a);
        num[a]++;
    }
    sort(house.begin(), house.end());
    
    cout<<house[(n-1) /2];
    
    /* calculating all the distances
    for(int i=1; i<n; i++){
        min_dist += house[i]-house[0];
    }
    prev = min_dist;
    for(int i=1; i<n; i++){
        a = num[house[i]]; b= num[house[i-1]];
        dist = prev +(-a+b+i-b-(n-i-a))*(house[i]-house[i-1]);
        if(dist<min_dist){
            min_dist = dist;
            min_house = i;
        }
        prev = dist;
    }
    cout<<house[min_house];
    */
    
    return 0;
}
