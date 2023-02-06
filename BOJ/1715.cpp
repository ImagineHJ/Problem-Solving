//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/06.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int n, a;
    long long x, y, sum, cnt = 0;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        pq.push(a);
    }
    if(n==1) cnt = 0;
    else{
        while(1){
            x = pq.top(); pq.pop(); // take 2 of the smallest number
            y = pq.top(); pq.pop();
            sum = x + y;
            cnt += sum;
            if(pq.empty()) break; // end of sorting
            pq.push(sum);
        }
    }

    cout<<cnt;
    
    return 0;
}
