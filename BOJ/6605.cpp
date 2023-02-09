//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#define INF 1e18
using namespace std;

long long factors[4] = {2, 3, 5, 7};
vector<long long> humble_nums;
priority_queue<long long, vector<long long>, greater<long long>> pq;

string suffix(int n){
    n = n%100;
    if(n==11 || n==12 || n==13) return "th";
    n = n%10;
    if(n==1) return "st";
    if(n==2) return "nd";
    if(n==3) return "rd";
    return "th";
}

void add_humble_num(){
    long long n;
    n = pq.top(); pq.pop();
    if(n<=humble_nums[humble_nums.size()-1]) return;
    
    humble_nums.push_back(n);
    for(int i=0; i<4; i++){
        pq.push(n*factors[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    humble_nums.push_back(1);
    for(int i=0; i<4; i++){
        pq.push(factors[i]);
    }
    
    while(true){
        cin>>n;
        if(n==0) break;
        while(humble_nums.size()<n) add_humble_num();
        cout<<"The "<<n<<suffix(n)<<" humble number is "<<humble_nums[n-1]<<"."<<'\n';
    }
    
    return 0;
}
