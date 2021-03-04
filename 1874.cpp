#include <iostream>
#include <stack>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    stack<int> stck;
    
    int k, curr=1;
    string ans;
    
    cin>>k;
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        
        if(curr>n){
            if(stck.top()==n) {stck.pop(); ans.append("-\n");}
            else { cout<<"NO"; return 0; }
        }
        else{
            while(curr<=n) {stck.push(curr++); ans.append("+\n");}
            stck.pop(); ans.append("-\n");
        }
    }
    
    cout<<ans;
    
    return 0;
    
}
