#include <iostream>
#include <stack>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    stack<int> stck;
    
    int k, ans=0;
    cin>>k;
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        
        if(n!=0){
            stck.push(n);
            ans+=n;
        }
        else{
            ans-=stck.top();
            stck.pop();
        }
    }
    cout<<ans;
    return 0;
    
}
