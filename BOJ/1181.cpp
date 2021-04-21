#include <iostream>
#include <algorithm>
#include <string>
#define MAX 200000
using  namespace std;

struct word{
    string str;
    int l;};

word arr[MAX+1];

bool compare(word a, word b){
    if(a.l!=b.l) return a.l<b.l;
    else return a.str<b.str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i].str;
        arr[i].l=(arr[i].str).length();
    }
    sort(arr, arr+n, compare); //O(nlogn) time complexity
    
    for(int i=0; i<n; i++)
           
        if(arr[i-1].str!=arr[i].str||i==0)cout<<arr[i].str<<'\n'; //use '\n' instead of endl for speed
        

    return 0;
}
