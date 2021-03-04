#include <iostream>
#include <vector>

using namespace std;
int child_num[51]={0,};
vector<int> children[51];

void preorder(int r){
    child_num[r]=-1;
    
    for(int i=0; i<children[r].size(); i++)
        preorder(children[r][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    
    int parent[51];
    
    int n; cin>>n;
    
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        parent[i]=p;
        if(p!=-1){
            children[p].push_back(i);
            child_num[p]++;
        }
    }
    
    int d; cin>>d;
    
    preorder(d);
    child_num[parent[d]]--;
    
    int ans=0;
    for(int i=0; i<n; i++)
        if (child_num[i]==0) ans++;
    
    cout<<ans;
    
    return 0;
}
