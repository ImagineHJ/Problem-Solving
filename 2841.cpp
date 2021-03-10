#include <iostream>
#include <stack>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    stack<int> line[7];
    
    int n, p, ans=0;
    cin>>n>>p;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        
        while( !line[a].empty() && line[a].top()>b ) {
            line[a].pop(); ans++;
        }
        
        if(line[a].empty()){
            line[a].push(b); ans++;
        }
        else if(line[a].top()<b){
            line[a].push(b); ans++;
        }
    }
    
    cout<<ans;
    return 0;
    
}

