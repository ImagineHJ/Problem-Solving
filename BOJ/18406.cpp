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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int left_sum=0, right_sum=0;
    string s;
    cin>>s;
    
    for(int i=0; i<s.size()/2; i++){ // calculate left sum
        left_sum += s[i]-'0'; // change char to int
    }
    for(int i=s.size()/2; i<s.size(); i++){ // calculate right sum
        right_sum += s[i]-'0';
    }
    if(left_sum == right_sum) cout<<"LUCKY"; // compare
    else cout<<"READY";
    
    return 0;
}
