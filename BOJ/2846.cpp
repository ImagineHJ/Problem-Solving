#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, max=0, len=0, pre;
    cin>>n;
    vector<int> road(n);
    
    for(int i=0; i<n; i++){
        cin>>road[i];
    }
    pre=road[0];
    for(int i=1; i<n;i++){
        if(pre<road[i]){
            len+=(road[i]-pre);
            if(len>max) max=len;
        }
        else{
            len=0;
        }
        pre=road[i];
    }
    
    cout<<max;
    
    return 0;
}
