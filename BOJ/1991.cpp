#include <iostream>

using namespace std;
char left_child[27];
char right_child[27];

void preorder(char root){
    cout<<root;
    if(left_child[root-'A']!='.')
        preorder(left_child[root-'A']);
    if(right_child[root-'A']!='.')
        preorder(right_child[root-'A']);
    
}
void inorder(char root){
    if(left_child[root-'A']!='.')
        inorder(left_child[root-'A']);
    cout<<root;
    if(right_child[root-'A']!='.')
        inorder(right_child[root-'A']);
}
void postorder(char root){
    if(left_child[root-'A']!='.')
        postorder(left_child[root-'A']);
    if(right_child[root-'A']!='.')
        postorder(right_child[root-'A']);
    cout<<root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char p, l, r;
        cin>>p>>l>>r;
        
        left_child[p-'A']=l;
        right_child[p-'A']=r;
    }
    
    preorder('A'); cout<<'\n';
    inorder('A'); cout<<'\n';
    postorder('A'); cout<<'\n';
    
    return 0;
}
