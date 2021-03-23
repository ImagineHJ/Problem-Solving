#include <iostream>
#include <stack>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    stack<int> s;
    int top, ans=0;
    
    string str;
    getline(cin, str);
    
    for (int i=0; i<str.length(); i++){
        
        if (str[i]=='(') s.push(-1);
        else if(str[i]==')'){
            int temp=0;
            while(1){
                top=s.top(); s.pop();
                if(top>0) temp+=top;
                else if(top==-1){
                    if(temp==0) temp=1;
                    else ans+=temp+1;
                    s.push(temp);
                    break;
                }
            }
        }
    
    }
    cout<<ans;
    return 0;
}
