#include <iostream>
#include <algorithm>
#define MAX 100000
using  namespace std;

struct member{
    int ent, age;
    string name;
};

member arr[MAX+1];

bool compare(member a, member b){
    if(a.age!=b.age) return a.age<b.age;
    else return a.ent<b.ent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].age>>arr[i].name;
        arr[i].ent=i;
    }
    sort(arr, arr+n, compare); //O(nlogn) time complexity
    for(int i=0; i<n; i++)
           cout<<arr[i].age<<' '<<arr[i].name<<'\n'; //use '\n' instead of endl for speed
    return 0;
}
