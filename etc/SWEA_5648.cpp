/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo&categoryId=AWXRFInKex8DFAUo&categoryType=CODE&problemTitle=&orderBy=SUBMIT_COUNT&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct won{
    int x; int y;
    int d; int k;
    bool dead;
};
struct collision{
    int i; int j;
    int time;
};
struct comp{
    bool operator()(collision a, collision b){
        return a.time>b.time;
    }
};
vector<won> wons;
priority_queue<collision, vector<collision>, comp> collisions;

int n, energy=0;

void checkCollision(int i, int j){
    collision c;
    if(wons[i].d==0 && wons[j].d==1 && wons[i].x==wons[j].x && wons[i].y<wons[j].y){
        c.time = (wons[j].y-wons[i].y)/2;
    }
    else if(wons[i].d==1 && wons[j].d==0 && wons[i].x==wons[j].x && wons[i].y>wons[j].y){
        c.time = (wons[i].y-wons[j].y)/2;
    }
    else if(wons[i].d==2 && wons[j].d==3 && wons[i].y==wons[j].y && wons[i].x>wons[j].x){
        c.time = (wons[i].x-wons[j].x)/2;
    }
    else if(wons[i].d==3 && wons[j].d==2 && wons[i].y==wons[j].y && wons[i].x<wons[j].x){
        c.time = (wons[j].x-wons[i].x)/2;
    }
    else if(wons[i].d==0 && wons[j].d==2 && wons[i].y<wons[j].y && wons[i].x<wons[j].x && wons[j].y-wons[i].y == wons[j].x-wons[i].x){
        c.time = wons[j].x-wons[i].x;
    }
    else if(wons[i].d==0 && wons[j].d==3 && wons[i].y<wons[j].y && wons[i].x>wons[j].x && wons[j].y-wons[i].y == wons[i].x-wons[j].x){
        c.time = wons[i].x-wons[j].x;
    }
    else if(wons[i].d==1 && wons[j].d==2 && wons[i].y>wons[j].y && wons[i].x<wons[j].x && wons[i].y-wons[j].y == wons[j].x-wons[i].x){
        c.time = wons[j].x-wons[i].x;
    }
    else if(wons[i].d==1 && wons[j].d==3 && wons[i].y>wons[j].y && wons[i].x>wons[j].x && wons[i].y-wons[j].y == wons[i].x-wons[j].x){
        c.time = wons[i].x-wons[j].x;
    }
    else if(wons[i].d==2 && wons[j].d==0 && wons[i].y>wons[j].y && wons[i].x>wons[j].x && wons[i].y-wons[j].y == wons[i].x-wons[j].x){
        c.time = wons[i].x-wons[j].x;
    }
    else if(wons[i].d==2 && wons[j].d==1 && wons[i].y<wons[j].y && wons[i].x>wons[j].x && wons[j].y-wons[i].y == wons[i].x-wons[j].x){
        c.time = wons[i].x-wons[j].x;
    }
    else if(wons[i].d==3 && wons[j].d==0 && wons[i].y>wons[j].y && wons[i].x<wons[j].x && wons[i].y-wons[j].y == wons[j].x-wons[i].x){
        c.time = wons[j].x-wons[i].x;
    }
    else if(wons[i].d==3 && wons[j].d==1 && wons[i].y<wons[j].y && wons[i].x<wons[j].x && wons[j].y-wons[i].y == wons[j].x-wons[i].x){
        c.time = wons[j].x-wons[i].x;
    }
    else return; // no collision
    c.i = i; c.j = j; collisions.push(c);
}

void getAllCollisions(){
    for(int i=0; i<wons.size(); i++){
        for(int j=i+1; j<wons.size(); j++){
            checkCollision(i, j);
        }
    }
}

void simulateCollisions(){
    int time, i, j;
    set<int> exploded;
    
    while(!collisions.empty()){
        exploded.clear();
        time = collisions.top().time;
        i = collisions.top().i; j = collisions.top().j;
        collisions.pop();
        if(!wons[i].dead && !wons[j].dead) {
            exploded.insert(i); exploded.insert(j);
        }
        
        while(collisions.top().time==time && !collisions.empty() ){
            i = collisions.top().i; j = collisions.top().j; collisions.pop();
            if(!wons[i].dead && !wons[j].dead) {
                exploded.insert(i); exploded.insert(j);
            }
        }
        for(auto e:exploded){
            wons[e].dead = true;
            energy += wons[e].k;
        }
    }
    
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    won w;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        wons.clear(); energy = 0; w.dead = false;
        for(int i=0; i<n; i++){
            cin>>w.x>>w.y>>w.d>>w.k;
            w.x *= 2; w.y *=2;
            wons.push_back(w);
        }
        getAllCollisions();
        simulateCollisions();
        
        cout<<'#'<<test_case<<' '<<energy<<'\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

