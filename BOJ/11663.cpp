#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int n, m;
vector<int> dots;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    int ans, a, b, temp;
    for(int i=0; i<n; i++){
        cin>>a;
        dots.push_back(a);
    }
    sort(dots.begin(), dots.end());
    
    for(int i=0; i<m; i++){
        cin>>a>>b;
        
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
     
        ans = upper_bound(dots.begin(), dots.end(), b) - lower_bound(dots.begin(), dots.end(), a); // binary search
        cout<<ans<<'\n';
    }
    return 0;
}
