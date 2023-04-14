#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool available(long long time, int n, vector<int> &times){
    long long ppl=0;
    for(int i=0; i<times.size(); i++){
        ppl += time/times[i];
    }
    return ppl>=n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long mint, maxt;
    sort(times.begin(), times.end());
    mint = (n/times.size())*times[0];
    maxt = (n/times.size()+1)*times[times.size()-1];
    
    long long s=mint, e=maxt, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(available(mid, n, times)){
            if(mid==mint) break;
            if(!available(mid-1, n, times)) break;
            else e=mid-1;
        }
        else s = mid+1;
    }
    
    answer = mid;
    
    return answer;
}
