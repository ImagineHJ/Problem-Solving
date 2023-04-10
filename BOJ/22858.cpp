#include <iostream>
#include <vector>
using  namespace std;

int n, k;
int cards[10001];
int D[10001];

void undo(){
    int temp[10001];
    
    for(int i=1; i<=n; i++){
        temp[D[i]] = cards[i];
    }
    for(int i=1; i<=n; i++){
        cards[i] = temp[i];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>cards[i];
    for(int i=1; i<=n; i++) cin>>D[i];
    
    for(int i=0; i<k; i++) undo();
    
    for(int i=1; i<=n; i++) cout<<cards[i]<<' ';
    
    return 0;
}
