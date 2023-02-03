//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/03.
//

#include <iostream>
#define INF 1e9
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int cnt=0;
    string num;
    cin>>num;
    
    
    for(int i=1; i<num.size(); i++){
        if(num[i-1]!=num[i]) cnt++;
    }
    
    cout<<(cnt+1)/2;
    return 0;
}
