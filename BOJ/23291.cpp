#include <iostream>


using  namespace std;

int tank[100][100];
int n, k,minF=10001, maxF=0;

int dx[] = {};
int dy[] = {};
void fishDivide(){
    int temp[100][100] = {0, };
    int d;
    
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(tank[x][y]==0) continue;
            if(y+1<n && tank[x][y+1]!=0){
                d = abs(tank[x][y]-tank[x][y+1])/5;
                if(d>0){
                    if(tank[x][y]>tank[x][y+1]){
                        temp[x][y] -= d;
                        temp[x][y+1] += d;
                    }
                    else{
                        temp[x][y] += d;
                        temp[x][y+1] -= d;
                    }
                }
            }
            
            if(x+1<n && tank[x+1][y]!=0){
                d = abs(tank[x][y]-tank[x+1][y])/5;
                if(d>0){
                    if(tank[x][y]>tank[x+1][y]){
                        temp[x][y] -= d;
                        temp[x+1][y] += d;
                    }
                    else{
                        temp[x][y] += d;
                        temp[x+1][y] -= d;
                    }
                }
            }
        }
    }
    
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(temp[x][y]!=0) tank[x][y] += temp[x][y];
        }
    }
}

void stackUp(int start, int w, int h){
    int baseY = start+w, baseX = 1;;
    
    for(int j=start+w-1; j>=start; j--){
        for(int i=0; i<h; i++){
            tank[baseX][baseY] = tank[i][j];
            tank[i][j] = 0;
            baseY++;
        }
        baseX++; baseY = start+w;
    }
}

void cleanUp(){
    
    // 1
    for(int i=0; i<n; i++){
        if(tank[0][i]==minF) tank[0][i]++;
    }
    
    //2
    int h=3, w=2, start = 0;
    while(start+w/2+h/2-1<n){
        stackUp(start, w/2, h/2);
        start += w/2;
        w++; h++;
    }
    
    //3
    fishDivide();
    //4
    int base = 0, y=0;
    while(tank[0][y]==0) y++;
    
    for(int j=y; j<n; j++){
        for(int i=0; i<n; i++){
            if(tank[i][j]==0) break;
            if(i!=0 || j!=base){
                tank[0][base] = tank[i][j];
                tank[i][j] = 0;
            }
            base++;
        }
    }
    // 5
    int num = n/4;
    base = 0;
    for(int j=n-1; j>=n-num; j--){
        tank[1][j] = tank[0][base];
        tank[0][base] = 0;
        base++;
    }
    for(int j=n-num; j<n; j++){
        tank[2][j] = tank[0][base];
        tank[0][base] = 0;
        base++;
    }
    for(int j=n-1; j>=n-num; j--){
        tank[3][j] = tank[0][base];
        tank[0][base] = 0;
        base++;
    }
    // 6
    fishDivide();
    //7
    base = 0;
    minF = 10001; maxF = 0;
    for(int j=n-num; j<n; j++){
        for(int i=0; i<4; i++){
            tank[0][base] = tank[i][j];
            minF = min(minF, tank[0][base]); maxF = max(maxF, tank[0][base]);
            tank[i][j] = 0;
            base++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int cnt = 0;
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>tank[0][i];
        minF = min(minF, tank[0][i]); maxF = max(maxF, tank[0][i]);
    }
    
    while(maxF-minF>k){
        cleanUp();
        cnt++;
    }
    cout<<cnt;
    
    return 0;
}
