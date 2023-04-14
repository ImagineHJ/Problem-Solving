#include <vector>
#include <string>
#include <iostream>
#define INF 1e9
using namespace std;

int mindp[105][105];
int maxdp[105][105];
vector<char> ops;
vector<int> nums;

int toInt(string s){
    int ret = 0, digit=1;
    for(int i=s.size()-1; i>=0; i--){
        ret += digit*(s[i]-'0');
        digit*=10;
    }
    return ret;
}

int solution(vector<string> arr)
{
    int answer = -1;
    int start, end;
    
    // parse
    ops.push_back('+');
    nums.push_back(toInt(arr[0]));
    for(int i=1; i<arr.size(); i+=2){
        ops.push_back(arr[i][0]);
        nums.push_back(toInt(arr[i+1]));
    }
    // init
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size(); j++){
            if(i==j){
                mindp[i][i] = nums[i];
                maxdp[i][i] = nums[i];
            }
            else{
                mindp[i][j] = INF;
                maxdp[i][j] = -INF;
            }
        }
    }
    
    for(int s=2; s<=nums.size(); s++){
        for(int i=0; i<=nums.size()-s+1; i++){
            start = i; end = i+s-1;
            for(int j=start+1; j<=end; j++){
                if(ops[j]=='+'){
                    mindp[start][end] = min(mindp[start][end], mindp[start][j-1]+mindp[j][end]);
                    maxdp[start][end] = max(maxdp[start][end], maxdp[start][j-1]+maxdp[j][end]);
                }
                else{
                    mindp[start][end] = min(mindp[start][end], mindp[start][j-1]-maxdp[j][end]);
                    maxdp[start][end] = max(maxdp[start][end], maxdp[start][j-1]-mindp[j][end]);
                }
            }
        }
    }
    answer = maxdp[0][nums.size()-1];
    
    return answer;
}
