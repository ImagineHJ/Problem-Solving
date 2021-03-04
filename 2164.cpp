#include <iostream>
#include <queue>
using  namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    queue<int> q;
    int n;
    
    cin>>n;
    for(int i=1; i<=n; i++)
        q.push(i);
    
    while(q.size()>1){
        int f;
        q.pop();
        f=q.front();
        q.pop();
        q.push(f);
    }
    cout<<q.front();
    
    return 0;
}


