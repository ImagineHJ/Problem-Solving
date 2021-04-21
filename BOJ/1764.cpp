#include <iostream>
#include <algorithm>
#define MAX 500000
#define COMPARE(x, y) (((x)<(y))?-1 : ((x)==(y))?0 : 1)
using  namespace std;

string not_heard[MAX+1];
string not_both[MAX+1];

bool check(string str, string* arr, int n){
    int mid, left=0, right=n;
    
    while(left<=right){
        mid=(left+right)/2;
        switch(COMPARE(arr[mid], str)){
            case -1: left=mid+1; break;
            case 0: return true;
            case 1: right=mid-1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n, m, idx=0;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        cin>>not_heard[i];
    }
    sort(not_heard, not_heard+n);
    
    for(int i=0; i<m; i++){
        string temp;
        cin>>temp;
        if(check(temp, not_heard, n)) not_both[idx++]=temp;
    }
    sort(not_both, not_both+idx); //O(nlogn) time complexity
    
    cout<<idx<<'\n';
    for(int i=0; i<idx; i++)
           cout<<not_both[i]<<'\n'; //use '\n' instead of endl for speed

    return 0;
}
