#include <iostream>
using  namespace std;

// union - find
int par[300005];
int getPar(int i){
    if(par[i]!=i) par[i] = getPar(par[i]);
    return par[i];
}
void doUnion(int a, int b){
    int ap = getPar(a);
    int bp = getPar(b);
    
    if(ap<bp) par[bp]=ap;
    else par[ap]=bp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, b;
    
    cin>>n;
    for(int i=1; i<=n; i++){
        par[i]=i; // initialize
    }
  
    for(int i=0; i<n-2; i++){
        cin>>a>>b;
        doUnion(a, b);
    }

    getPar(1); // update Par
    for(int i=2; i<=n; i++){
        if(par[1]!=getPar(i)){
            cout<<1<<' '<<i<<'\n';
            break;
        }
    }
    
    return 0;
}

