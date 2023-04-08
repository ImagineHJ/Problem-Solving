#include <iostream>
#include <vector>
using  namespace std;

int m, s, sX, sY, cnt=0;
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int map[5][5][9];

int nextD(int d){
    if(d==1) return 8;
    return d-1;
}

int DtoDic(int d){
    if(d==1) return 2;
    if(d==3) return 1;
    if(d==5) return 4;
    if(d==7) return 3;
    return 0;
}

void practice(){
    int tempMap[5][5][9] = {0,};
    bool cannotMove = false;
    int newX, newY, newD;
    
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            for(int d=1; d<9; d++){
                if(map[i][j][d]==0) continue;
                newD = d; newX = i + dx[newD]; newY = j + dy[newD];
                cannotMove = false;
                while(newX<1 || newX>4 || newY<1 || newY>4 || map[newX][newY][0]!=0 ||(newX==sX && newY==sY)){
                    newD = nextD(newD);
                    if(newD==d){cannotMove = true; break;}
                    newX = i + dx[newD]; newY = j + dy[newD];
                }
                if(!cannotMove){
                    tempMap[newX][newY][newD] += map[i][j][d];
                }
                else{
                    tempMap[i][j][d] += map[i][j][d];
                }
            }
        }
    }
    
    
    int x1, y1, x2, y2, x3, y3;
    int maxD1=1, maxD2=1, maxD3=1, maxD=555, maxF=0, fish1=0, fish2=0, fish3 = 0;
    
    // get shark dir
    for(int d1=1; d1<=7; d1+=2){
        x1 = sX + dx[d1]; y1 = sY + dy[d1]; fish1 = 0;
        if(x1<1 || x1>4 || y1<1 || y1>4) continue;
        for(int d=1; d<9; d++){
            fish1 += tempMap[x1][y1][d];
        }
        for(int d2=1; d2<=7; d2+=2){
            x2 = x1; y2 = y1;
            x2 += dx[d2]; y2 += dy[d2]; fish2 = fish1;
            if(x2<1 || x2>4 || y2<1 || y2>4) continue;
            for(int d=1; d<9; d++){
                fish2 += tempMap[x2][y2][d];
            }
            for(int d3=1; d3<=7; d3+=2){
                x3 = x2; y3 = y2;
                x3 += dx[d3]; y3 += dy[d3]; fish3 = fish2;
                if(x3<1 || x3>4 || y3<1 || y3>4) continue;
                if(x3!=x1||y3!=y1){
                    for(int d=1; d<9; d++){
                        fish3 += tempMap[x3][y3][d];
                    }
                }
                if(maxF<fish3){
                    maxF = fish3;
                    maxD = DtoDic(d1)*100+DtoDic(d2)*10+DtoDic(d3);
                    maxD1 = d1; maxD2 = d2; maxD3 = d3;
                }
                else if(maxF==fish3 && DtoDic(d1)*100+DtoDic(d2)*10+DtoDic(d3)<maxD){                    maxF = fish3;
                    maxD = DtoDic(d1)*100+DtoDic(d2)*10+DtoDic(d3);
                    maxD1 = d1; maxD2 = d2; maxD3 = d3;
                }
            }
        }
    }
    
    // move shark
    newX = sX+dx[maxD1]; newY = sY+dy[maxD1];
    for(int d=1; d<9; d++){
        if(tempMap[newX][newY][d]>0) map[newX][newY][0] = cnt+2; // mark smell
        tempMap[newX][newY][d] = 0;
    }
    newX += dx[maxD2]; newY += dy[maxD2];
    for(int d=1; d<9; d++){
        if(tempMap[newX][newY][d]>0) map[newX][newY][0] = cnt+2; // mark smell
        tempMap[newX][newY][d] = 0;
    }
    newX += dx[maxD3]; newY += dy[maxD3];
    for(int d=1; d<9; d++){
        if(tempMap[newX][newY][d]>0) map[newX][newY][0] = cnt+2; // mark smell
        tempMap[newX][newY][d] = 0;
    }
    sX = newX; sY = newY;
    
    
    // remove smell
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            if(map[i][j][0]==cnt) map[i][j][0] = 0;
        }
    }
    
    // duplicate
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            for(int d=1; d<9; d++){
                map[i][j][d] += tempMap[i][j][d];
            }
        }
    }
    
    cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>m>>s;
    int x, y, d;
    for(int i=0; i<m; i++){
        cin>>x>>y>>d;
        map[x][y][d]++;
    }
    cin>>sX>>sY;
    
    for(int i=0; i<s; i++){
        practice();
    }
    
    long long ans = 0;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            for(int d=1; d<9; d++){
                ans += map[i][j][d];
            }
        }
    }
    cout<<ans;
    
    
    return 0;
}
