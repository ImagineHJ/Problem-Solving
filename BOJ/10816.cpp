//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using  namespace std;
vector<int> cards;
vector<pair<int, int>> card_num;

int binary_search(int x){
    int start, end, mid;
    start = 0; end = card_num.size()-1;
    
    while(start<=end){
        mid = (start+end)/2;
        if(x==card_num[mid].first) return mid;
        else if(x<card_num[mid].first) end = mid-1;
        else start = mid+1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, a, idx, cnt=0;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        cards.push_back(a);
    }
    sort(cards.begin(), cards.end());
    int last = -1;
    for(int i=0; i<n; i++){ // count the quantity of each number
        if(i==0 || cards[i] != cards[i-1]) {
            card_num.push_back({cards[i], 1});
            last ++;
        }
        else card_num[last].second++;
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>a;
        idx = binary_search(a);
        if (idx == -1) cnt = 0;
        else cnt = card_num[idx].second;
        cout<<cnt<<" ";
    }
    
    return 0;
}

