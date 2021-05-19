#include <iostream>
#include <algorithm>
#define MAX 100000
using  namespace std;

int arr[MAX+2][MAX+2];
int size[MAX+2]={0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, ans=0;
    cin>>n;
    
    cout<<size[n];
    
    for(int i=0; i<n; i++){
        int loc, col;
        cin>>loc>>col;
        arr[col][size[col]++]=loc;
    }
    
    for(int i=1; i<n+1; i++)
        sort(arr[i], arr[i]+size[i]);
    
    for(int i=1; i<n+1; i++){
        //cout<<i<<':';
        for(int j=0; j<size[i]; j++){
            //cout<<arr[i][j]<<' ';
            int add;
            if(j==0) add=(arr[i][j+1]-arr[i][j]);
            else if (j==size[i]-1) add=(arr[i][j]-arr[i][j-1]);
            else if ( (arr[i][j]-arr[i][j-1]) < (arr[i][j+1]-arr[i][j]) ) add=(arr[i][j]-arr[i][j-1]);
            else add=(arr[i][j+1]-arr[i][j]);
            
            //cout<<"add:"<<add<<' ';
            ans+=add;
        }
        //cout<<'\n';
        
    }
    
    cout<<ans;
    
     }
