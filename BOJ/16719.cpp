#include <iostream>

using namespace std;

int map[100]={0};
string s;

void print(){
    string ans="";
    for(int i=0; i<s.size(); i++){
        if(map[i]!=0) ans += s[i];
    }
    cout<<ans<<'\n';
}

void choose(int l, int r){
    int idx=l;
    if(l>r) return;
    
    for(int i=l+1; i<=r; i++){
        if(s[i]<s[idx]){
            idx=i; // find smallest alphabet
        }
    }
    map[idx]=1;
    print();
    
    choose(idx+1, r);
    choose(l, idx-1);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>s;
    choose(0, s.size()-1);
    
    return 0;
    
}
