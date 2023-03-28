#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

struct paper{
    int x1; int x2; int y1; int y2;
};

int map[2200][2200];
int ans[3];
queue<paper> curPaper;

bool isSameNum(paper p){
    for(int x=p.x1; x<=p.x2; x++){
        for(int y=p.y1; y<=p.y2; y++){
            if(map[x][y]!=map[p.x1][p.y1]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, cutSize;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    paper p, smallP;
    p.x1 = 0; p.x2 = n-1; p.y1 = 0; p.y2 = n-1;
    curPaper.push(p);
    
    while(!curPaper.empty()){
        p = curPaper.front(); curPaper.pop();
        if(!isSameNum(p)){ // not same num -> cut into 9 pieces
            cutSize = (p.x2-p.x1+1)/3;
            for(int i=p.x1; i<=p.x2-cutSize+1; i+=cutSize){
                for(int j=p.y1; j<=p.y2-cutSize+1; j+=cutSize){
                    smallP.x1 = i; smallP.x2 = i+cutSize-1;
                    smallP.y1 = j; smallP.y2 = j+cutSize-1;
                    curPaper.push(smallP);
                }
            }
        }
        else{ // if same num -> save ans
            if(map[p.x1][p.y1]==-1) ans[0]++;
            if(map[p.x1][p.y1]==0) ans[1]++;
            if(map[p.x1][p.y1]==1) ans[2]++;
        }
    }
    
    for(int i=0; i<3; i++) cout<<ans[i]<<'\n';
    
    return 0;
}
