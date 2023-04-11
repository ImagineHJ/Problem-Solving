#include <iostream>
using  namespace std;

int U[1000001];
int V[1000001];
int frontUMin[1000001];
int backUMax[1000001];
int backVMin[1000001];
int frontVMax[1000001];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n;
    
    int Umin = 1000000001, Vmax = -1;
    for(int i=1; i<=n; i++) {
        cin>>U[i]>>V[i];
        if(U[i]!=0) Umin = min(Umin, U[i]);
        if(V[i]!=0) Vmax = max(Vmax, V[i]);
        frontUMin[i] = Umin; frontVMax[i] = Vmax;
    
    }
    
    int Umax = -1, Vmin = 1000000001;
    for(int i=n; i>=1; i--){
        if(U[i]!=0) Umax = max(Umax, U[i]);
        if(V[i]!=0) Vmin = min(Vmin, V[i]);
        backUMax[i] = Umax; backVMin[i] = Vmin;
    }
    
    int ans = -1;
    for(int i=1; i<n; i++) {
        if(frontUMin[i]>backUMax[i+1] && frontVMax[i]<backVMin[i+1]) ans = i;
    }
    cout<<ans;
    
    return 0;
}




