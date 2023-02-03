//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cave[126][126];
int shortest[126][126];
int visited[126][126];

struct Node{
    int x; int y;
    int cost;
};

struct compare{
    bool operator()(Node a, Node b){
        return a.cost>b.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int test=1, n, a, x, y, c, new_x, new_y, new_cost;
    Node node;
    while(1){
        
        cin>>n;
        if(n==0) break;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>a;
                cave[i][j] = a;
                shortest[i][j] = INF; // initialize
                visited[i][j] = 0; // initialize
            }
        }
        
        // dijkstra
        priority_queue<Node, vector<Node>, compare> q;
        node.x = 0; node.y = 0; node.cost = cave[0][0];
        shortest[0][0] = cave[0][0];
        
        q.push(node);
        while(1){
            x = q.top().x; y = q.top().y; c = q.top().cost;
            q.pop();
            visited[x][y] = 1; // visit the closest node
            
            if(x==n-1 && y==n-1) break; // calculated the shortest path to destination
            
            for(int i=0; i<4; i++){ // check all the connected node
                new_x = x + dx[i]; new_y = y + dy[i]; new_cost = c + cave[new_x][new_y];
                if(0<=new_x && new_x<n && 0<=new_y && new_y<n && visited[new_x][new_y]==0 && shortest[new_x][new_y]>new_cost){
                    shortest[new_x][new_y] = new_cost; // found a shorter path
                    node.x = new_x; node.y = new_y; node.cost = new_cost;
                    q.push(node);
                }
            }
        }
        
        cout<<"Problem "<<test<<": "<<shortest[n-1][n-1]<<'\n';
        test++;
    }
    
    return 0;
}
