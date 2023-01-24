//
//  main.cpp
//  4-3 Time
//
//  Created by JinnyLim on 2023/01/24.
//

#include <iostream>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, cnt;
    cin>>n;
    
    if(n<3){
        cnt = (15*60 + 45*15) * (n+1); // when hour value does not have 3
    }
    else if (n<13){
        cnt = (15*60 + 45*15) * (n);
        cnt += 60*60*1; // when hour value has 3 -> (3)
    }
    else if (n<23){
        cnt = (15*60 + 45*15) * (n-1);
        cnt += 60*60*2; // when hour value has 3 -> (3, 13)
        
    }
    else{
        cnt = (15*60 + 45*15) * (n-2);
        cnt += 60*60*3; // when hour value has 3 -> (3, 13, 23)
    }
    
    std::cout << cnt << endl;
    return 0;
}
