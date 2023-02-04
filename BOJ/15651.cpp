//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/04.
//

#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
vector<int> par;

void num(int n, int s){
    if(s==0){ // end of line
        for(int j=0; j<par.size(); j++) cout<<par[j]<<" "; //print array
        cout<<'\n';
    }
    else{
        for(int i=1; i<=n; i++){
            par.push_back(i); // add to parent array
            num(n, s-1);
        }
    }
    par.pop_back();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int n, m;
    cin>>n>>m;
    
    num(n, m);
    
    return 0;
}
