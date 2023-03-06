#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int map[20][20];
int dice[7], diceEast = 3, diceWest = 4, diceUp = 1, diceDown = 6, diceNorth = 2, diceSouth = 5;
int n, m, x, y, k;

void moveDice(int move){
    int temp;
    if(move==1 && y+1<m){
        y++;
        temp = diceEast;
        diceEast = diceUp;
        diceUp = diceWest;
        diceWest = diceDown;
        diceDown = temp;
    }
    else if(move==2 && y-1>=0){
        y--;
        temp = diceDown;
        diceDown = diceWest;
        diceWest = diceUp;
        diceUp = diceEast;
        diceEast = temp;
    }
    else if(move==3 && x-1>=0){
        x--;
        temp = diceUp;
        diceUp = diceSouth;
        diceSouth = diceDown;
        diceDown = diceNorth;
        diceNorth = temp;
    }
    else if(move==4 && x+1<n){
        x++;
        temp = diceSouth;
        diceSouth = diceUp;
        diceUp = diceNorth;
        diceNorth = diceDown;
        diceDown = temp;
    }
    else{
        return;
    }
    
    // copy dice&map numbers
    if(map[x][y]==0) map[x][y] = dice[diceDown];
    else{
        dice[diceDown] = map[x][y];
        map[x][y] = 0;
    }
  // print out upper side number of dice
    cout<<dice[diceUp]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>m>>x>>y>>k;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    
    int move;
    for(int i=1; i<7 ;i++){
        dice[i] = 0;
    }
    for(int i=0; i<k ;i++){
        cin>>move;
        moveDice(move);
    }
    
    return 0;
}
