//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18
using namespace std;
vector<int> num;
int n;


long long max_res(int i, int add, int sub, int mul, int div){
    long long add_res, sub_res, mul_res, div_res;
    add_res = sub_res = mul_res = div_res = -INF;
    
    if(i==1){ // only two numbers left
        if(add==1) return num[i-1]+num[i];
        if(sub==1) return num[i-1]-num[i];
        if(mul==1) return num[i-1]*num[i];
        if(div==1) return num[i-1]/num[i];
    }
    if(add>0) add_res = max_res(i-1, add-1, sub, mul, div)+num[i];
    if(sub>0) sub_res = max_res(i-1, add, sub-1, mul, div)-num[i];
    if(mul>0) mul_res = max_res(i-1, add, sub, mul-1, div)*num[i];
    if(div>0) div_res = max_res(i-1, add, sub, mul, div-1)/num[i];
    return max({add_res, sub_res, mul_res, div_res}); // return the max result of all 4 cases
}

long long min_res(int i, int add, int sub, int mul, int div){
    long long add_res, sub_res, mul_res, div_res;
    add_res = sub_res = mul_res = div_res = INF;
    
    if(i==1){ // only two numbers left
        if(add==1) return num[i-1]+num[i];
        if(sub==1) return num[i-1]-num[i];
        if(mul==1) return num[i-1]*num[i];
        if(div==1) return num[i-1]/num[i];
    }
    if(add>0) add_res = min_res(i-1, add-1, sub, mul, div)+num[i];
    if(sub>0) sub_res = min_res(i-1, add, sub-1, mul, div)-num[i];
    if(mul>0) mul_res = min_res(i-1, add, sub, mul-1, div)*num[i];
    if(div>0) div_res = min_res(i-1, add, sub, mul, div-1)/num[i];
    return min({add_res, sub_res, mul_res, div_res}); // return the min result of all 4 cases
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int a, add, sub, mul, div;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        num.push_back(a);
    }
    cin>>add>>sub>>mul>>div;
    
    cout<<max_res(n-1, add, sub, mul, div)<<'\n';
    cout<<min_res(n-1, add, sub, mul, div);
    

    return 0;
}
