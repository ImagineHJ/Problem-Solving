#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<int> blocks[50];

int strToInt(string s){
    int num=0, digit = 1;
    for(int i=s.size()-1; i>=0; i--){
        num += (s[i]-'0')*digit;
        digit*=10;
    }
    //cout<<s<<" to int "<<num<<endl;
    return num;
}

void stringToBlocks(int i, string s){
    string num="";
    for(int j=0; j<s.size(); j++){
        if(s[j]==' ') {
            blocks[i].push_back(strToInt(num));
            num = "";
        }
        else num += s[j];
    }
    blocks[i].push_back(strToInt(num));

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, h, sum;
    long long ans = 0;
    string s;
    
    cin>>n>>m>>h;
    cin.ignore();
    
    for(int i=0; i<n; i++){
        getline(cin, s);
        stringToBlocks(i, s);
    }
    
    vector<long long> cnt(h+1, 0);
    vector<pair<int, long long>> now;
    cnt[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<h; j++){
            if(cnt[j]==0) continue;
            for(int k=0; k<blocks[i].size(); k++){
                sum = j+blocks[i][k];
                if(sum==h) {
                    ans += cnt[j];
                    ans %= 10007;
                };
                if(sum<h) now.push_back({sum, cnt[j]});
            }
        }
        for(int j=0; j<now.size(); j++) {
            cnt[now[j].first]+=now[j].second;
            cnt[now[j].first]%= 10007;
        }
        now.clear();
        
    }
    
    cout<<ans%10007;
    
    return 0;
}
