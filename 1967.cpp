#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;
int ans=0;

struct child{
    int name;
    int length;
};

vector<child> children[MAX+1];

int max_length(int root){
    int max=0;
    
    for(int i=0; i<children[root].size(); i++){
        int num=max_length(children[root][i].name)+children[root][i].length;
        if(num>max) max=num;
    }
    return max;
}

int diameter(int root){
    int max=0, second=0;
    
    for(int i=0; i<children[root].size(); i++){
        int num=max_length(children[root][i].name)+children[root][i].length;
        if(num>max) {second=max; max=num;}
        else if(num>second) second=num;
    }
    return max+second;
}

void preorder(int root){
    int num=diameter(root);
    if(num>ans) ans=num;
    for(int i=0; i<children[root].size(); i++)
        preorder(children[root][i].name);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n; cin>>n;
    
    
    for(int i=1; i<n; i++){
        int a, b, c;
        
        cin>>a>>b>>c;
        
        child ch; ch.name=b; ch.length=c;
        children[a].push_back(ch);
    }
    
    preorder(1);
    
    cout<<ans;
    
    return 0;
}
