#include <iostream>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int start=0, end=0, n, m, sum=0, ans=100001, diff;
    int arr[100001];
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sum=arr[0];
    while(end<n){
        
        if(end<start){
            end=start;
            sum=arr[start];
        }
        
        if(sum<m)
            sum+=arr[++end];
        else{
            diff=end-start+1;
            if(diff<ans) ans=diff;
            
            sum-=arr[start++];
        }
    }
    if(ans>n) ans=0;
    cout<<ans;
    
    return 0;
}
