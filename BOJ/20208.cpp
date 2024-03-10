#include <iostream>
#include <vector>

using  namespace std;

struct place{
    int r;
    int c;
};
int map[10][10];
place house;
vector<place> mintChocos;
int ans = 0;
int n, h;

int dist(place a, place b){
    return abs(a.r-b.r)+abs(a.c-b.c);
}

void drinkMintChoco(place current, int m, int num){
    place next;
    int distance;
    
    distance = dist(current, house);
    if(distance<=m) // can arrive home
    {
        ans = max(ans, num);
    }
    
    for(int i=0; i<mintChocos.size(); i++)
    {
        next = mintChocos[i];
        distance = dist(next, current);
        if(map[next.r][next.c]==2 && distance<=m){
            map[next.r][next.c]=0;
            drinkMintChoco(next, m-distance+h, num+1); // DFS
            map[next.r][next.c]=2;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int m;
    cin>>n>>m>>h;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                house = {i, j};
            }
            else if(map[i][j]==2){
                mintChocos.push_back({i, j});
            }
        }
    }
    drinkMintChoco(house, m, 0);
    cout<<ans;
    
    return 0;
}

