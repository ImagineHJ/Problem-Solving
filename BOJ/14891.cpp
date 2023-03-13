#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

int wheel[4][8];
int twelve[4] = {0, 0, 0, 0};

int get_right(int num){
    return wheel[num][(twelve[num]+2)%8];
}
int get_left(int num){
    if(twelve[num]<2) {
        return wheel[num][twelve[num]+6];
    }
    return wheel[num][twelve[num]-2];
}

void move(int num, int dir, int par){
    // check if left or right wheel should move
    bool left_move = false, right_move = false;
    if(num!=0 && par!=num-1 && get_left(num)!=get_right(num-1)) left_move = true;
    if(num!=3 && par!=num+1 && get_right(num)!=get_left(num+1)) right_move = true;
    
    
    // rotate
    if(dir == 1) twelve[num] = twelve[num]?twelve[num]-1:7;
    else twelve[num] = (twelve[num]+1)%8;
    
    // move left or right wheel
    if(left_move) move(num-1, -dir, num);
    if(right_move) move(num+1, -dir, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    string s;
    for(int i=0; i<4; i++){
        cin>>s;
        for(int j=0; j<8; j++) wheel[i][j] = s[j]-'0';
    }
    
    int k, n, d;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>n>>d;
        move(n-1, d, 10);
    }
    
    // calculate score
    int ans = 0;
    for(int i=0; i<4; i++){
        if(wheel[i][twelve[i]]==1) ans+=pow(2, i);
    }
    cout<<ans;
    return 0;
}
