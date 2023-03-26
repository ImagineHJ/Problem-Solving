#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
vector<long long> waitTime;

int isEnough(long long t){
    long long p1 = 0, p2 = 0;
    for(int i=0; i<n; i++){
        p1+=t/waitTime[i];
        p2+=(t-1)/waitTime[i];
    }
    if(p1>=m && p2<m) return 1; // this is the minimum time
    if (p1>=m) return 2; // enough but not min
    return 3; // not enough, need more
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m;
    
    long long a,maxT = 0, minT = INF, s, e, mid;
    for(int i=0; i<n; i++){
        cin>>a; maxT = max(maxT, a); minT = min(minT, a);
        waitTime.push_back(a);
    }
    
    if(m%n==0) a = m/n;
    else a = m/n+1;
    
    s = minT*a; e = maxT*a;

    while(s<=e){ // binary search
        mid = (s+e)/2; a = isEnough(mid);
        if(a==1) break;
        else if(a==2) e = mid-1;
        else if(a==3) s = mid+1;
    }
    
    cout<<mid;
    
    return 0;
}
