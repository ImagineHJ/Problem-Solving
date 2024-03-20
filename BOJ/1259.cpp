#include <iostream>

using namespace std;

int check(string s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i++]!=s[j--]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s;
    while(1){
        cin>>s;
        
        if(s=="0") break;
        if(check(s)) cout<<"yes\n";
        else cout<<"no\n";
    }
    
    return 0;
    
}
