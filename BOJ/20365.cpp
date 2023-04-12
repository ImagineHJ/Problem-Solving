#include <iostream>
#define INF 1e9
using  namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s;
    cin>>n>>s;
    
    int preR=0, preB=0;
    
    if(s[0]=='R') preR++;
    else preB++;
    
    for(int i=1; i<n; i++){
        if(s[i-1]!=s[i]){
            if(s[i]=='R') preR++;
            else preB++;
        }
    }
    
    cout<<min(preR, preB)+1;
    
    return 0;
}
