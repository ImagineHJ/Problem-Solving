#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int alpha[30];
int ans = 0;

void makeStr(int n, int prev){
    if(n==0) ans++;
    
    for(int i=0; i<30; i++){
        if(alpha[i]>0 && i!=prev){
            alpha[i]--;
            makeStr(n-1, i);
            alpha[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++) alpha[s[i]-'a']++;
    
    makeStr(s.size(), -1);
    cout<<ans;
    
    return 0;
}
