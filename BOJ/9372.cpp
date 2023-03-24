#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int test, n, m, a, b;
    cin>>test;
    
    for(int t=0; t<test; t++){
        cin>>n>>m;
        for(int i=0; i<m; i++)cin>>a>>b;
        cout<<n-1<<'\n';
    }
    
    return 0;
}
