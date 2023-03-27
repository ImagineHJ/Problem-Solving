#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<int> nums;
vector<int> operators;
long long maxVal = -INF;

long long operatorC(int op, long long n1, long long n2){
    if(op==1) return n1+n2;
    if(op==2) return n1-n2;
    if(op==3) return n1*n2;
    return 0;
}

void calculate(long long val, int b, int i){
    if(b==0){
        for(int j=i; j<nums.size(); j++){
            val = operatorC(operators[j], val, nums[j]);
        }
        maxVal = max(maxVal, val);
        return;
    }
    if(i>=nums.size()-1) return;
    
    long long nextVal1, nextVal2, n;
    n = operatorC(operators[i+1], nums[i], nums[i+1]);
    nextVal1 = operatorC(operators[i], val, nums[i]);
    nextVal2 = operatorC(operators[i], val, n);
    calculate(nextVal1, b, i+1); // no brakets on ith num
    calculate(nextVal2, b-1, i+2); // brakets on i, i+1th num
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    string s;
    cin>>n;
    cin>>s;
    
    operators.push_back(0);
    for(int i=0; i<s.size(); i++){
        if(s[i]=='+') operators.push_back(1);
        else if(s[i]=='-') operators.push_back(2);
        else if(s[i]=='*') operators.push_back(3);
        else nums.push_back(s[i]-'0');
    }
    
    for(int i=0; i<=nums.size()/2; i++){
        calculate(nums[0], i, 1); // i number of brakets
    }
    cout<<maxVal;
    
    return 0;
}
