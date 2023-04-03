#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int map[100][100];
int up[100][100];
int n, l, ans=0;

void checkRow(int x){
    int cnt=1;
    
    for(int y=0; y<n; y++) up[x][y]=0; // initialize
    
    for(int y=1; y<n; y++){
        if(abs(map[x][y-1]-map[x][y])>1) return;
        if(map[x][y-1]<map[x][y] && cnt<l) return;
        if(map[x][y-1]<map[x][y] && cnt>=l){
            for(int i=1; i<=l; i++) up[x][y-i] = 1; // make up path
            cnt = 1;
        }
        else if(map[x][y-1]==map[x][y]){cnt++;}
        else{cnt=1;}
    }
    cnt=1;
    for(int y=n-2; y>=0; y--){
        if(map[x][y+1]<map[x][y] && cnt<l) return;
        if(map[x][y+1]<map[x][y] && cnt>=l){
            for(int i=1; i<=l; i++) {
                if(up[x][y+i]) return; // up path already exists
                up[x][y+i] = 1; // make up path
            }
            cnt = 1;
        }
        else if(map[x][y+1]==map[x][y]) {cnt++;}
        else{cnt=1;}
    }
    ans++;
}
void checkCol(int y){
    int cnt=1;
    
    for(int x=0; x<n; x++) up[x][y]=0; // initialize
    
    for(int x=1; x<n; x++){
        if(abs(map[x-1][y]-map[x][y])>1) return;
        if(map[x-1][y]<map[x][y] && cnt<l) return;
        if(map[x-1][y]<map[x][y] && cnt>=l){
            for(int i=1; i<=l; i++) up[x-i][y] = 1; // make up path
            cnt = 1;
        }
        if(map[x-1][y]==map[x][y]){cnt++;}
        else{cnt=1;}
    }
    cnt=1;
    for(int x=n-2; x>=0; x--){
        if(map[x+1][y]<map[x][y] && cnt<l) return;
        if(map[x+1][y]<map[x][y] && cnt>=l){
            for(int i=1; i<=l; i++) {
                if(up[x+i][y]) return; // up path already exists
                up[x+i][y] = 1; // make up path
            }
            cnt = 1;
        }
        if(map[x+1][y]==map[x][y]) {cnt++;}
        else{cnt=1;}
    }
    ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        checkCol(i);
        checkRow(i);
    }
    cout<<ans;
    
    return 0;
}
