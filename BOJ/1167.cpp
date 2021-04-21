#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;
long long ans=0;

struct child{
    int name;
    int length;
};

vector<child> children[MAX+1];

long long max_length(int root){
    long long max=0;
    
    for(int i=0; i<children[root].size(); i++){
        long long num=max_length(children[root][i].name)+children[root][i].length;
        if(num>max) max=num;
    }
    return max;
}

long long diameter(int root){
    long long max=0, second=0;
    
    for(int i=0; i<children[root].size(); i++){
        long long num=max_length(children[root][i].name)+children[root][i].length;
        if(num>max) {second=max; max=num;}
        else if(num>second) second=num;
    }
    return max+second;
}

void preorder(int root){
    long long num=diameter(root);
    if(num>ans) ans=num;
    for(int i=0; i<children[root].size(); i++)
        preorder(children[root][i].name);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n; cin>>n;
    int visited[MAX+1]={0, };
    
    for(int i=0; i<n; i++){
        int p; cin>>p;
        visited[p]=1;
        
        int c; cin>>c;
        while(c!=-1){
            int l; cin>>l;
            
            if(visited[c]==0){
                child ch; ch.name=c; ch.length=l;
                children[p].push_back(ch);
            }
            cin>>c;
        }
    }
    
    preorder(1);
    
    cout<<ans;
    
    return 0;
}
