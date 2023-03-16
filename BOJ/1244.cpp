#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

int n;
int swi[101];

void boy(int k){
    int mul = 1, num = mul*k;
    while(num<=n){
        swi[num] = 1-swi[num];
        mul++; num = mul*k;
    }
}

void girl(int k){
    int s=k-1, e=k+1;
    swi[k] = 1-swi[k];
    
    while(s>0 && e<=n && swi[s]==swi[e]){
        swi[s] = 1-swi[s];
        swi[e] = 1-swi[e];
        s--; e++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n;
    
    for(int i=1; i<=n; i++) cin>>swi[i];
    
    int s, m, k;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>s>>k;
        if(s==1) boy(k);
        else girl(k);
    }
    for(int i=1; i<=n; i++) {
        cout<<swi[i]<<' ';
        if(i%20==0) cout<<'\n';
    }
}
