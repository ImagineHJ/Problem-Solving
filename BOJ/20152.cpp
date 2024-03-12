#include <iostream>
#include <queue>

using namespace std;
long long map[35][35];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster

    int h, n, maxn, minn;
    
    cin>>h>>n;
    
    maxn = max(h, n);
    minn = min(h, n);
    
    map[maxn][maxn] = 1;
    for(int i=maxn; i>=minn; i--){
        for(int j=maxn-1; j>=minn; j--){
            if(j>i) continue;
            map[i][j] = map[i+1][j]+map[i][j+1];
        }
    }
    cout<<map[minn][minn];
    
}
