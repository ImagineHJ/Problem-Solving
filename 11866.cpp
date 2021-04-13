#include <iostream>
#include <queue>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    queue<int> q;
    int n, k;
    
    cin>>n>>k;

    for(int i=0; i<n; i++) q.push(i+1);
    
    cout<<'<';
    while(!q.empty()){
        if(q.size()!=n) cout<<", ";
        for(int i=0; i<k-1; i++){
            int n;
            n=q.front();
            q.pop();
            q.push(n);
        }
        cout<<q.front();
        q.pop();
    }
    
    cout<<'>';
    
    return 0;
}

