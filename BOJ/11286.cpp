#include <iostream>
#include <queue>

using namespace std;

struct num{
    int val, plus;
};

struct comp{
    bool operator() (const num& a, const num& b){
        if(a.val==b.val) return a.plus>b.plus;
        return a.val>b.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    priority_queue<num, vector<num>, comp> pq;
    
    int n; cin>>n;
    
    while(n--){
        int type; cin>>type;
        
        if(type==0){
            if(!pq.empty()){
                num a=pq.top(); pq.pop();
                if(a.plus>0) cout<<a.val<<'\n';
                else cout<<-a.val<<'\n';
            }
            else cout<<0<<'\n';
        }
        else if(type>0){
            num a; a.val=type; a.plus=1;
            pq.push(a);
        }
        else{
            num a; a.val=-type; a.plus=-1;
            pq.push(a);
        }
    }
    
    return 0;
}
