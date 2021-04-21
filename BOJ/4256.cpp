#include <iostream>

using namespace std;

void postorder(int r, int* left, int* right){
    if(left[r]!=0) postorder(left[r], left, right);
    if(right[r]!=0) postorder(right[r], left, right);
    cout<<r<<' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        
        int pre[1001]; int in_idx[1001];
        int left[1001]={0, }; int right[1001]={0, };
        
        for(int i=0; i<n; i++){
            int a; cin>>a;
            pre[i]=a;
        }
        for(int i=0; i<n; i++){
            int a; cin>>a;
            in_idx[a]=i;
        }
        int root=0;
        for(int i=0; i<n; i++){
            if(i==0) {root=pre[i]; continue;}
            
            int point=root, node=pre[i];
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
        
        postorder(root, left, right);
        cout<<'\n';
    }
    
    return 0;
}
