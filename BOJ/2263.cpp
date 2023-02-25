#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<int> inorder, postorder;
int preorder[100000];
int n;

void find_preorder(int post_start, int post_end, int in_start, int in_end, int n){
    int root, left_size;
    if(post_start>post_end || in_start>in_end) return;
    
    root = postorder[post_end]; // find root
    preorder[n] = root;
    left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin()-in_start;
    
    // left tree
    find_preorder(post_start, post_start+left_size-1, in_start, in_start+left_size-1, n+1);
    // right tree
    find_preorder(post_start+left_size, post_end-1, in_start+left_size+1, in_end, n+left_size+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        inorder.push_back(a);
    }
    for(int i=0; i<n; i++){
        cin>>a;
        postorder.push_back(a);
    }
    
    find_preorder(0, n-1, 0, n-1, 0);
    for(int i=0; i<n; i++){
        cout<<preorder[i]<<" ";
    }
    
    return 0;
}
