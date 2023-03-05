#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
char map[10][10];
int n, m;
int min_cnt = 11;

void move(int cnt, int redX, int redY, int blueX, int blueY){
    if(cnt>=10) return;
    
    if(map[blueX][blueY]=='O') return; // if blue is located on the hole at first
    if(map[redX][redY]=='O'){ // if red is located on the hole at first
        min_cnt = min(min_cnt, cnt);
        return;
    }
    
    int redXt = redX, redYt = redY, blueXt = blueX, blueYt = blueY; // temp variables
    int redXl, redYl, blueXl, blueYl; // save location variable for each 4 moves
    int redXr, redYr, blueXr, blueYr;
    int redXu, redYu, blueXu, blueYu;
    int redXd, redYd, blueXd, blueYd;
    
    //left
    bool redIn = false, blueIn = false; // check if red&blue got in the hole
    // move red
    while(map[redX][redY-1]!='#' && !(redX==blueX&&redY-1==blueY)){
        redY--;
        if(map[redX][redY]=='O') {
            redIn = true;
            redX = redY = -1;
            break;
        }
    }
    // move blue
    while(map[blueX][blueY-1]!='#' && !(redX==blueX&&redY==blueY-1)){
        blueY--;
        if(map[blueX][blueY]=='O') {
            blueIn = true;
        }
    }
    if(!blueIn && redIn){ // if red is in the hole and blue is not
        min_cnt = min(min_cnt, cnt+1);
        return;
    }
    
    if(blueIn){ // if blue is in the hole -> stop operation
        redXl = -1;
    }
    else{
        // if red was blocked by blue before -> move more
        while(map[redX][redY-1]!='#' && !(redX==blueX&&redY-1==blueY)){
            redY--;
        }
        // save moved location for next operation
        redXl = redX; redYl = redY; blueXl = blueX; blueYl = blueY;
    }
    
    //right
    redIn = false;blueIn = false;
    redX = redXt; redY = redYt; blueX = blueXt; blueY = blueYt;
    while(map[redX][redY+1]!='#' && !(redX==blueX&&redY+1==blueY)){
        redY++;
        if(map[redX][redY]=='O') {
            redIn = true;
            redX = redY = -1;
            break;
        }
    }
    while(map[blueX][blueY+1]!='#' && !(redX==blueX&&redY==blueY+1)){
        blueY++;
        if(map[blueX][blueY]=='O') {
            blueIn = true;
        }
    }
    if(!blueIn &&redIn){
        min_cnt = min(min_cnt, cnt+1);
        return;
    }
    if(blueIn){
        redXr = -1;
    }
    else{
        while(map[redX][redY+1]!='#' && !(redX==blueX&&redY+1==blueY)){
            redY++;
        }
        redXr = redX; redYr = redY; blueXr = blueX; blueYr = blueY;
    }
    
    //up
    redIn = false;blueIn = false;
    redX = redXt; redY = redYt; blueX = blueXt; blueY = blueYt;
    while(map[redX-1][redY]!='#' && !(redX-1==blueX&&redY==blueY)){
        redX--;
        if(map[redX][redY]=='O') {
            redIn = true;
            redX = redY = -1;
            break;
        }
    }
    while(map[blueX-1][blueY]!='#' && !(redX==blueX-1&&redY==blueY)){
        blueX--;
        if(map[blueX][blueY]=='O') {
            blueIn = true;
        }
    }
    if(!blueIn &&redIn){
        min_cnt = min(min_cnt, cnt+1);
        return;
    }
    
    if(blueIn){
        redXu = -1;
    }
    else{
        while(map[redX-1][redY]!='#' && !(redX-1==blueX&&redY==blueY)){
            redX--;
        }
        redXu = redX; redYu = redY; blueXu = blueX; blueYu = blueY;
    }
    
    //down
    redIn = false;blueIn = false;
    redX = redXt; redY = redYt; blueX = blueXt; blueY = blueYt;
    while(map[redX+1][redY]!='#' && !(redX+1==blueX&&redY==blueY)){
        redX++;
        if(map[redX][redY]=='O') {
            redIn = true;
            redX = redY = -1;
            break;
        }
    }
    while(map[blueX+1][blueY]!='#' && !(redX==blueX+1&&redY==blueY)){
        blueX++;
        if(map[blueX][blueY]=='O') {
            blueIn = true;
        }
    }
    if(!blueIn &&redIn){
        min_cnt = min(min_cnt, cnt+1);
        return;
    }
    
    if(blueIn){
        redXd = -1;
    }
    else{
        while(map[redX+1][redY]!='#' && !(redX+1==blueX&&redY==blueY)){
            redX++;
        }
        redXd = redX; redYd = redY; blueXd = blueX; blueYd = blueY;
    }
    
    
    if(redXl!=-1) move(cnt+1, redXl, redYl, blueXl, blueYl);
    if(redXr!=-1) move(cnt+1, redXr, redYr, blueXr, blueYr);
    if(redXu!=-1) move(cnt+1, redXu, redYu, blueXu, blueYu);
    if(redXd!=-1) move(cnt+1, redXd, redYd, blueXd, blueYd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int redX, redY, blueX, blueY;
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j]=='R'){redX=i; redY=j; map[i][j] = '.';}
            if(map[i][j]=='B'){blueX=i; blueY=j; map[i][j] = '.';}
        }
    }
    move(0, redX, redY, blueX, blueY);
    
    if(min_cnt==11) cout<<-1;
    else cout<<min_cnt;
    
    return 0;
}
