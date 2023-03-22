#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#define INF 1e9
using namespace std;

int d, p;
vector<pair<int, int>> pipes;
bool isIn[100001];

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second) return a.first>b.first;
    else return a.second>b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>d>>p;
    
    int l, c;
    for(int i=0; i<p; i++){
        cin>>l>>c;
        pipes.push_back({l, c});
    }
    sort(pipes.begin(), pipes.end(), compare);
    
    vector<int> dp;
    int ans=0, includeLength, pipeLength, preSize;
    for(int i=0; i<p; i++){
        pipeLength = pipes[i].first;
        if(pipeLength>d)continue;
        if(pipeLength==d && ans==0) {ans = pipes[i].second; break;}
        preSize = dp.size();
        for(int j=0; j<preSize; j++){
            includeLength = dp[j]+pipeLength;
            if(includeLength==d && ans==0) {ans = pipes[i].second; break;}
            else if(includeLength<d && !isIn[includeLength]){
                dp.push_back(includeLength);
                isIn[includeLength] = true;
            }
        }
        if(ans>0) break;
        if(!isIn[pipeLength]) {dp.push_back(pipeLength); isIn[pipeLength] = true;}
    }
    
    cout<<ans;
    
    return 0;
}
