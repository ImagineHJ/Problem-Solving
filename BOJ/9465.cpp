#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<pair<int, int>> sticker;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n, test, a, first, second, prevFirst, prevSecond;
    
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>n;
        sticker.clear();
        for(int i=0; i<n; i++){
            cin>>a;
            sticker.push_back({a, 0});
        }
        for(int i=0; i<n; i++) cin>>sticker[i].second;
        
        prevFirst = sticker[0].first; prevSecond = sticker[0].second;
        for(int i=1; i<n; i++){
            first = max(prevSecond+sticker[i].first, prevFirst);
            second = max(prevFirst+sticker[i].second, prevSecond);
            prevFirst = first; prevSecond = second;
        }
        cout<<max(prevFirst, prevSecond)<<'\n';
    }
    
    return 0;
}
