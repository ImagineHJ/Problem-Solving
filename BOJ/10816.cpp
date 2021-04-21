#include <iostream>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int plus[1001]={0, };
    int minus[1001]={0, };
    
    int n, m;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        
        if(a>=0) plus[a]++;
        else minus[-a]++;
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int b;
        cin>>b;
        if(b>=0) cout<<plus[b]<<' ';
        else cout<<minus[-b]<<' ';
    }

    
    return 0;
}
