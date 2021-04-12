#include <iostream>
#include <algorithm>
#define MAX 1048576
using  namespace std;

int arr[MAX+1];
int temp[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    
    int m;
    m=n/k;
    
    for(int i=0; i<=n-m; i+=m){
        sort(arr+i, arr+i+m); //뒷칸은 마지막 위치가 아니다. 마치막 위치+1
        
       //for(int j=0; j<m; j++){ //copy array
        //    temp[j]=*(arr+i+j);
        //}
       // sort(temp, temp+m);
    }
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    
    return 0;
}
