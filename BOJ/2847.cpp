#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<int> points;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a, ans=0;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        points.push_back(a);
    }
    
    for(int i=points.size()-2; i>=0; i--){
        if(points[i+1]<=points[i]) {
            ans += (points[i] - (points[i+1]-1));
            points[i] = points[i+1]-1;
        }
    }
    cout<<ans;
    
    return 0;
}
