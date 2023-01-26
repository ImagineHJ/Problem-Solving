//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/26.
//  rice_cake -> wood

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

vector<int> rice_cake;
int n, k, a;

long long left_over(int len){
    long long sum=0;
    for(int i=0; i<n; i++){
        if(rice_cake[i]<=len) break;
        sum+=(rice_cake[i]-len);
    }
    return sum;
}

int cut(){
    int start, end, mid, ret = 0;
    long long sum;
    start = 0; end = rice_cake[0];
    while(start<=end){
        mid = (start+end)/2; sum = left_over(mid);
        if(sum == k) return mid;
        else if(sum>k) { ret = mid; start = mid+1;}
        else if(sum<k) end = mid-1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a;
        rice_cake.push_back(a);
    }
    sort(rice_cake.begin(),rice_cake.end(),greater<int>());
    
    cout<<cut()<<endl;
    
    return 0;
}
