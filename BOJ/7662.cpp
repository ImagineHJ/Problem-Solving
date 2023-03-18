#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define INF 1e9
using namespace std;

unordered_map<int, int> um;
priority_queue<int> large;
priority_queue<int, vector<int>, greater<int>> small;

void ins(int n){
    um[n]++;
    large.push(n); small.push(n);
}

// pop numbers already deleted
void cleanLarge(){
    int n;
    while(!large.empty()){
        n = large.top();
        if(um[n]>0) break;
        large.pop();
    }
}
void cleanSmall(){
    int n;
    while(!small.empty()){
        n = small.top();
        if(um[n]>0) break;
        small.pop();
    }
}

void del(int i){
    int n;
    if(i==1){
        cleanLarge();
        if(large.empty()) return;
        n = large.top(); large.pop();
        if(um[n]>0) um[n]--;
    }
    if(i==-1){
        cleanSmall();
        if(small.empty()) return;
        n = small.top(); small.pop();
        if(um[n]>0) um[n]--;
    }
}

void init(){
    for(auto a : um) um[a.first] = 0;
    while(!small.empty()) small.pop();
    while(!large.empty()) large.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int test, k, n;
    char c;
    cin>>test;
    
    for(int t=0; t<test; t++){
        init();
        cin>>k;
        for(int i=0; i<k; i++){
            cin>>c>>n;
            if(c=='D') del(n);
            if(c=='I') ins(n);
        }
        cleanLarge(); cleanSmall();
        if(large.empty() || small.empty()) cout<<"EMPTY\n";
        else cout<<large.top()<<" "<<small.top()<<'\n';
    }
}
