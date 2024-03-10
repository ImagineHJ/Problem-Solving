#include <iostream>
#include <set>
#include <math.h>
using  namespace std;

int weight[10];
int not_prime[9005];
set<int> ans;

int n, m;

void eratos(int s){
    int root = pow(s, 0.5);
    for(int i=2; i<=root; i++){
        if(not_prime[i]==0){
            for(int j=2; j*i<=s; j++){
                not_prime[i*j]=1;
            }
        }
    }
}

void pick(int idx, int sum, int size){
    if(size==0 && !not_prime[sum]){
        ans.insert(sum);
        return;
    }
    if(idx>=n) return;
    
    pick(idx+1, sum+weight[idx], size-1);
    pick(idx+1, sum, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int sum=0;
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>weight[i];
        sum+=weight[i];
    }
    
    eratos(sum);
    pick(0, 0, m);
    
    if(ans.size()==0)
    {
        cout<<-1; // no answer
    }
    else
    {
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        
    }
    
    
    return 0;
}

