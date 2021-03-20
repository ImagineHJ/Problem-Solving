#include <iostream>
#define MAX 1023

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int arr[MAX+1];
    int k, init=1; cin>>k;
    
    for(int i=0; i<k; i++) init*=2;
    
    for(int i=0; i<init-1; i++){
        int n; cin>>n;
        arr[i]=n;
    }
    int level=1, num_count=1;
    init=(init-1)/2;
    
    while(level<=k){
        int diff, idx=init;
        diff=init*2+2;
        for(int i=0; i<num_count; i++){
            cout<<arr[idx]<<' ';
            idx+=diff;
        }
        cout<<'\n';
        num_count*=2;
        init/=2;
        level++;
    }
    
    return 0;
}
