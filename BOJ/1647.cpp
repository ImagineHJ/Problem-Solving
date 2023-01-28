//
//  main.cpp
//
//  Created by JinnyLim on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18

struct Road{
    int a;
    int b;
    int cost;
};

bool comp(Road x, Road y){
    return x.cost < y.cost;
}

using  namespace std;
int parent[100001];
vector<Road> roads;

int find_parent(int c){
    if (parent[c]==c) return c;
    
    parent[c] = find_parent(parent[c]); // save root
    return parent[c];
}

void do_union(int a_p, int b_p){
    if(a_p > b_p) parent[a_p] = parent[b_p];
    else parent[b_p] = parent[a_p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m, c, a, b, a_p, b_p, cnt=0;
    long long ret=0;
    Road r;
    cin>>n>>m;
    
    for(int i=1; i<n+1; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        r.a = a; r.b = b ;r.cost = c;
        roads.push_back(r);
    }
    sort(roads.begin(), roads.end(), comp); // sort by cost
    
    for(int i=0; i<m; i++){
        r = roads[i]; // choose min cost
        a=r.a; b=r.b; c=r.cost;
        a_p = find_parent(a); b_p = find_parent(b);
        if(a_p != b_p) { // if not connected
            do_union(a_p, b_p); // connect
            ret += c; // add cost
            cnt++;
        }
        if(cnt == n-2) break; // select only n-2 roads
    }
    cout<<ret;
    return 0;
}
