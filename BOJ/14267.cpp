#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

vector<int> children[MAX+1];
long long compliment[MAX+1]={0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        int p; cin>>p;
        
        if(p!=-1) children[p].push_back(i);
    }
    
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        
        compliment[a]+=b;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<children[i].size(); j++)
            compliment[children[i][j]]+=compliment[i];
        cout<<compliment[i]<<' ';
    }
    
    return 0;
}
