#include <iostream>
#include <stack>

using  namespace std;

struct tower{
    int idx, height;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    stack<tower> stck;
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        tower t;
        t.idx=i+1; t.height=num;
        
        while(!stck.empty() && stck.top().height<num) stck.pop();
        
        if(stck.empty()) cout<<0<<' ';
        else cout<<stck.top().idx<<' ';
        
        stck.push(t);
    }
  
    return 0;
}

