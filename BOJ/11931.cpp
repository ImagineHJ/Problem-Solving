#include <iostream>
#include <algorithm>
#define MAX 1000000
using  namespace std;

struct c{
    int x, y; };

c arr[MAX+1];

bool compare(c a, c b){
    if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i].x>>arr[i].y;
    sort(arr, arr+n, compare); //O(nlogn) time complexity
    for(int i=0; i<n; i++)
           cout<<arr[i].x<<' '<<arr[i].y<<'\n'; //use '\n' instead of endl for speed
    return 0;
}
