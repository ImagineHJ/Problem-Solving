#include <iostream>
#include <unordered_map>

using namespace std;
int p;

int square(int a, int b){
    int ans=1;
    
    while(b--){
        ans*=a;
    }
    return ans;
}

int next_num(int n){
    int ans=0;
    while(n!=0){
        ans+=square(n%10, p);
        n/=10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    unordered_map<int, int> s;
    int a, idx=0; cin>>a>>p;
    
    while(true){
        if(s.find(a)!=s.end()) break;
        
        s.emplace(a, idx++);
        a=next_num(a);
    }
    
    cout<<s[a];
    
    return 0;
}
