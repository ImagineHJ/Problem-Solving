#include <iostream>
#include <queue>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n; cin>>n;
    
    while(n--){
        int type; cin>>type;
        if(type>0){
            pq.push(type);
        }
        else {
            if(pq.empty()) cout<<0<<'\n';
            else {
                int i=pq.top();
                pq.pop(); cout<<i<<'\n';
            }
        }
    }
    
    return 0;
}
