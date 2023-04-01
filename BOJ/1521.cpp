#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<int> nums;
vector<char> ops;
int firstNum;

int toInt(string s, int start, int end){
    int digit = 1, ret=0;
    
    for(int i=end; i>=start; i--){
        ret += (s[i]-'0')*digit;
        digit *= 10;
    }
    return ret;
}


void toNums(string s){
    ops.push_back('+');
    
    int start = 0;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='-'|| s[i]=='+'){
            nums.push_back(toInt(s, start, i-1));
            start = i+1;
            ops.push_back(s[i]);
        }
    }
    nums.push_back(toInt(s, start, s.size()-1));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int ans, sum;
    string s;
    
    cin>>s;
    toNums(s);
    
    ans = nums[0];
    
    for(int i=1; i<nums.size();){
        if(ops[i]=='+') {ans+=nums[i]; i++;}
        else{
            sum = nums[i]; i++;
            while(i<nums.size() && ops[i]=='+'){
                sum += nums[i];
                i++;
            }
            ans -= sum;
        }
    }
    cout<<ans;
    
    return 0;
}
