#include <iostream>
#define MAX 100000

using namespace std;

void preorder(int r, int* left, int* right){
    cout<<r<<' ';
    if(left[r]!=0) preorder(left[r], left, right);
    if(right[r]!=0) preorder(right[r], left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
        int n; cin>>n;
        
        int post[MAX+1]; int in_idx[MAX+1];
        int left[MAX+1]={0, }; int right[MAX+1]={0, };
        
        for(int i=0; i<n; i++){
            int a; cin>>a;
            in_idx[a]=i;
        }
        for(int i=0; i<n; i++){
            int a; cin>>a;
            post[i]=a;
        }

        int root=0;
        for(int i=n-1; i>=0; i--){
            if(i==n-1) {root=post[i]; continue;}
            
            int point=root, node=post[i];
            while(true){
                if(in_idx[point]>in_idx[node]){ //left child
                    if(left[point]!=0)
                        point=left[point];
                    else {left[point]=node; break;} //왼쪽 자녀가 없는 경우
                }
                else{ //right child
                    if(right[point]!=0)
                        point=right[point];
                    else {right[point]=node; break;} //오른쪽 자녀가 없는 경우
                }
            }//while
        }
        
        preorder(root, left, right);
        cout<<'\n';
    
    return 0;
}
