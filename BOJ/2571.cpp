#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 1e9
using namespace std;

int paper[100][100];
int maxSize = 100;

void colorPaper(int x, int y){
    for(int i=x; i<x+10; i++){
        for(int j=y; j<y+10; j++){
            paper[i][j] = 1;
        }
    }
}

bool isBlack(int x1, int x2, int y1, int y2){
    for(int x=x1; x<=x2; x++){
        for(int y=y1; y<=y2; y++){
            if(paper[x][y]==0) return false;
        }
    }
    return true;
}

void rectangleOfSize(int w, int h){
    int size = w*h;
    for(int x=0; x+w-1<100; x++){
        for(int y=0; y+h-1<100; y++){
            if(isBlack(x, x+w-1, y, y+h-1)) maxSize = max(maxSize, size);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, x, y;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        colorPaper(x, y);
    }
    
    for(int w=100; w>=1; w--){
        for(int h=100; h>=1; h--){
            rectangleOfSize(w, h);
        }
    }
    
    cout<<maxSize;
    
    return 0;
}
