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

struct planet{
    int i; int x; int y; int z;
};
struct edge{
    int a; int b; int cost;
};
struct comp{
    bool operator()(edge a, edge b){
        return a.cost>b.cost;
    }
};
bool comp_x(planet a, planet b){
    return a.x<b.x;
}
bool comp_y(planet a, planet b){
    return a.y<b.y;
}
bool comp_z(planet a, planet b){
    return a.z<b.z;
}

vector<int> parent;

int find_parent(int a){
    int ret;
    
    if(parent[a]==a) return a;
    ret = find_parent(parent[a]);
    parent[a] = ret;
    return ret;
}

void do_union(int a_p, int b_p){
    if(a_p>b_p) parent[a_p] = b_p;
    else parent[b_p] = a_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, x, y, z, cnt, a_p, b_p, dist;
    long long total_cost=0;
    planet p;
    edge e, now;
    vector<planet> planets;
    priority_queue<edge, vector<edge>, comp> pq;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        p.i = i; p.x = x; p.y = y; p.z = z;
        planets.push_back(p);
        parent.push_back(i); // initialize
    }
    
    sort(planets.begin(), planets.end(), comp_x); // get min n-1 edges sorted by x
    for(int i=1; i<n; i++){
        dist = min({abs(planets[i].x-planets[i-1].x), abs(planets[i].y-planets[i-1].y), abs(planets[i].z-planets[i-1].z)});
        if (dist == abs(planets[i].x-planets[i-1].x)){
            e.a = planets[i].i; e.b = planets[i-1].i; e.cost = dist;
            pq.push(e);
        }
    }
    sort(planets.begin(), planets.end(), comp_y); // get min n-1 edges sorted by y
    for(int i=1; i<n; i++){
        dist = min({abs(planets[i].x-planets[i-1].x), abs(planets[i].y-planets[i-1].y), abs(planets[i].z-planets[i-1].z)});
        if (dist == abs(planets[i].y-planets[i-1].y)){
            e.a = planets[i].i; e.b = planets[i-1].i; e.cost = dist;
            pq.push(e);
        }
    }
    sort(planets.begin(), planets.end(), comp_z); // get min n-1 edges sorted by z
    for(int i=1; i<n; i++){
        dist = min({abs(planets[i].x-planets[i-1].x), abs(planets[i].y-planets[i-1].y), abs(planets[i].z-planets[i-1].z)});
        if (dist == abs(planets[i].z-planets[i-1].z)){
            e.a = planets[i].i; e.b = planets[i-1].i; e.cost = dist;
            pq.push(e);
        }
    }
    planets.clear();
    cnt = 0;
    // kruskal
    while(cnt<n-1){
        now = pq.top(); pq.pop();
        a_p = find_parent(now.a);
        b_p = find_parent(now.b);
        if(a_p!=b_p){ // not connected yet
            do_union(a_p, b_p); // connect two
            total_cost += now.cost;
            cnt++;
        }
    }
    cout<<total_cost;
    
    return 0;
}
