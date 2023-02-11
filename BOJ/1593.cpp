#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#define INF 1e18
using namespace std;

unordered_map<char, int> wm;
unordered_map<char, int> sm;

bool is_perm(){
    for(auto a : wm){
        if(sm[a.first] != a.second) return false;
    }
    return true;
}

// #1593
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int w_len, s_len, cnt=0;
    string s, w;
    
    cin>>w_len>>s_len;
    cin>>w>>s;
    
    for(int i=0; i<w_len; i++){
        wm[w[i]]++;
        sm[s[i]]++;
    }
    if(is_perm()){
        cnt++;
    }
    for(int i=1; i<=(s_len-w_len+1); i++){ // sliding window
        sm[s[i-1]]--;
        sm[s[i+w_len-1]]++;
        if(is_perm()){
            cnt++;
        }
    }
    
    cout<<cnt;
    
    return 0;
}
