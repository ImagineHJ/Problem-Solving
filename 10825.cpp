#include <iostream>
#include <algorithm>
#define MAX 100000
using  namespace std;

struct student{
    string name;
    int k, e, m; };

student arr[MAX+1];

bool compare(student a, student b){
    if(a.k!=b.k) return a.k>b.k;
    else if(a.e!=b.e) return a.e<b.e;
    else if(a.m!=b.m) return a.m>b.m;
    else return a.name<b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i].name>>arr[i].k>>arr[i].e>>arr[i].m;
    sort(arr, arr+n, compare); //O(nlogn) time complexity
    for(int i=0; i<n; i++)
           cout<<arr[i].name<<'\n'; //use '\n' instead of endl for speed
    return 0;
}
