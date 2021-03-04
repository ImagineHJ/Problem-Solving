#include <iostream>
#include <algorithm>
#define MAX 1000000
using  namespace std;

int arr[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+n); //O(nlogn) time complexity
    for(int i=0; i<n; i++)
           cout<<arr[i]<<'\n'; //use '\n' instead of endl for speed
    
    return 0;
}
