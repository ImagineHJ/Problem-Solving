#include <iostream>

using namespace std;
                                    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s, k, t="";
    cin>>s>>k;
    
    for(int i=0; i<s.size(); i++){
        if(!(s[i]>='0' && s[i]<='9')) t+=s[i]; // remove number
    }
    
    if(t.find(k) != string::npos) cout<<1;
    else cout<<0;
}
