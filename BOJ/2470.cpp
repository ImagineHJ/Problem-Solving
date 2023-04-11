#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18
using  namespace std;

vector<int> liquid;
long long mindiff = INF;
int ans1, ans2;

void diff(int a, int b){
    long long diff = abs(a+b);
    
    if(mindiff>diff){
        ans1 = a;
        ans2 = b;
        mindiff = diff;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, a;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a;
        liquid.push_back(a);
    }
    
    sort(liquid.begin(), liquid.end());
    
    for(int i=0; i<n; i++){
        a = lower_bound(liquid.begin(), liquid.end(), -liquid[i])-liquid.begin(); // binary search
        if(a>=0 && a<n && i!=a) diff(liquid[i], liquid[a]);
        if(a-1>=0 && a-1<n && i!=a-1) diff(liquid[i], liquid[a-1]);
        if(a+1>=0 && a+1<n && i!=a+1) diff(liquid[i], liquid[a+1]);
        if(mindiff==0) break;
    }
    
    cout<<min(ans1, ans2)<<' '<<max(ans1, ans2);
    
    return 0;
}



