#include <iostream>
#define MAX 100000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int vertex[MAX+1]={0,};
    
    
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int a, b;
        
        cin>>a>>b;
        vertex[a]++;
        vertex[b]++;
    }
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        
        if(a==1 && vertex[b]<2) cout<<"no"<<'\n';

        else cout<<"yes"<<'\n';
    }
    
    return 0;
}
