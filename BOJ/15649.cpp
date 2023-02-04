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
int visited[10];

void num(int n, int s){
    
    if(s==0){ // end of line
        for(int j=0; j<par.size(); j++) cout<<par[j]<<" "; //print array
        cout<<'\n';
    }
    else{
        for(int i=1; i<=n; i++){
            if(visited[i]) continue; // don't pick visited num
            visited[i] = 1;
            par.push_back(i); // add to parent array
            num(n, s-1);
            visited[i] = 0;
        }
    }
    
    if(par.size()!=0) par.pop_back();
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int n, m;
    cin>>n>>m;
    
    num(n, m);
    
    return 0;
}
