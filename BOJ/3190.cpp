//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/07.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18
using namespace std;
int n, k, l, x, y;
int sec, rot, length;
bool game_over;
char c;
int map[101][101];

struct location{
    int x;
    int y;
};

location snake[102];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool move(){
    int pre_x, pre_y, temp_x, temp_y;
    pre_x = snake[0].x; pre_y = snake[0].y;
    
    sec++;
    snake[0].x += dx[rot]; snake[0].y += dy[rot]; // move head
    
    if(snake[0].x<=0 || snake[0].x>n || snake[0].y<=0 || snake[0].y>n) {
        game_over = true; // collision to wall
        return false;
    }
    
    for(int i=1; i<length; i++){
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
            game_over = true; // collision to snake
            return false;
        }
        
        temp_x = snake[i].x; temp_y = snake[i].y;
        snake[i].x = pre_x; snake[i].y = pre_y;
        pre_x = temp_x; pre_y = temp_y;
    }
    
    if(map[snake[0].x][snake[0].y]==1){ // eat apple
        snake[length].x = pre_x; snake[length].y = pre_y;
        length++; // grow length
        map[snake[0].x][snake[0].y] = 0; // apple is gone
    }
    
    return true;
}

void turn_left(){
    if(rot==0) rot=3;
    else rot--;
}
void turn_right(){
    if(rot==3) rot=0;
    else rot++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>k;
    
    for(int i=0; i<k; i++){
        cin>>x>>y;
        map[x][y] = 1;
    }
    cin>>l;
    sec = 0; game_over = 0;
    rot = 1; length = 1; snake[0].x = snake[0].y = 1;
    for(int i=0; i<l; i++){
        cin>>x>>c;
        while(sec < x){
            if(!move()) break;
        }
        if (game_over)  break;
        if(c=='L') turn_left();
        else turn_right();
    }
    while(!game_over) move();
    
    cout<<sec;
    
    return 0;
}
