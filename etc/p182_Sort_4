//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/25.
//

#include <iostream>
#include <vector>
#include <queue>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, k, a, ans=0;
    vector<int> A, B;
    cin>>n>>k;
    
    //input list
    for(int i=0; i<n; i++){
        cin>>a;
        A.push_back(a);
    }
    for(int i=0; i<n; i++){
        cin>>a;
        B.push_back(a);
    }
    
    // sort list
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i<k; i++){
        if(A[i]>B[i]) break; // no more values to change
        A[i]=B[i];
    }
    
    for(int i=0; i<n; i++){
        ans+=A[i]; // calculate sum
    }
    cout<<ans<<'\n';
    
    return 0;
}
