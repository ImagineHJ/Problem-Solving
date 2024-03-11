#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster

    long long x, y, z;
    cin>>x>>y;
    z = (long long)(y*100/x);
    int s=1, e=1000000000, m, ans = -1;
    
    while(s<=e){ // binary search
        m = (s+e)/2;
        if((long long)((y+m)*100/(x+m))>z){
            ans = m;
            e = m-1;
        }
        else{
            s = m+1;
        }
        
    }
    cout<<ans;
    
    return 0;
}
