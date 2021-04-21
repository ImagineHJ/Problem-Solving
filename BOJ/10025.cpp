#include <iostream>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n, k, max=0, min=1000000, ans=0;
    int arr[1000001]={0,};
    
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        int g, x;
        cin>>g>>x;
        arr[x]=g;
        if(x>max) max=x;
        if(x<min) min=x;
    }
    int sum=0;
    
    for(int i=min; i<min+k*2+1; i++){
        if(i>max) break;
        sum+=arr[i];
    }
    ans=sum;
    for(int i=min; i+k*2+1<=max; i++){
        sum=sum-arr[i]+arr[i+k*2+1];
        if(sum>ans) ans=sum;
    }
    cout<<ans;
    
    return 0;
}
