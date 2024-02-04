#include <iostream>
#include <set>
using  namespace std;

set<int> dp[100][100];
int group[101];
int n, m, t, c;

int solve(){
    if(m<0) return 0;
    if(m==0) return 1;
    
    dp[0][0].insert(0);
    for(int i=0; i<=c-1; i++){
        for(int j=0; j<=n-c; j++){
            if(i-1>=0){ // iterate all nums in dp[i-1][j]
                for(auto s:dp[i-1][j]){
                    dp[i][j].insert(s); // do not choose group[c-i]
                    if(s+group[c-i]<=m) dp[i][j].insert(s+group[c-i]);
                }
            }
            if(j-1>=0){ // iterate all nums in dp[i][j-1]
                for(auto s:dp[i][j-1]){
                    dp[i][j].insert(s); // do not choose group[c+j]
                    if(s+group[c+j]<=m) dp[i][j].insert(s+group[c+j]);
                }
            }
            /*
            printf("%d %d : ", i, j);
            for(auto s:dp[i][j]){
                printf("%d, ", s);
            }
            printf("\n");
            */
            if(i+j+min(i, j)<=t && dp[i][j].count(m)>0) return 1;
        }
    }
    
    return 0;
        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m>>t;
    
    for(int i=1; i<=n; i++){
        cin>>group[i];
    }
    cin>>c;
    
    m = m-group[c];
    group[c]=0;
    
    int answer = solve();
    if(answer==1) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}

