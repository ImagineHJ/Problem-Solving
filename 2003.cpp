#include <iostream>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int start=0, end=0, n, m, sum=0, cnt=0;
    int arr[10001];
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sum=arr[0];
    while(end<n){
        if(end<start){
            end=start;
            sum=arr[start];
        }
        if(sum==m){
            cnt++;
            sum+=arr[++end];
        }
        else if(sum<m)
            sum+=arr[++end];
        else
            sum-=arr[start++];
    }
    
    cout<<cnt;
    
    return 0;
}
