#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 1e9
using namespace std;

vector<int> probs;
int a, n, l, r, x, ans=0;

void choose(int start, int sum, int maxP, int minP, int cnt){
    if(start>=n) return;
    
    choose(start+1, sum, maxP, minP, cnt); // don't use this problem
    maxP = max(maxP, probs[start]); minP = min(minP, probs[start]);
    sum += probs[start]; cnt++;
    if(sum>=l && sum<=r && maxP-minP>=x && cnt>=2) ans++; // satisfy the rule
    choose(start+1, sum, maxP, minP, cnt); // use this problem
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>l>>r>>x;
    for(int i=0; i<n; i++){
        cin>>a;
        probs.push_back(a);
    }
    
    choose(0, 0, 0, INF, 0);
    
    cout<<ans;
    
    return 0;
}
