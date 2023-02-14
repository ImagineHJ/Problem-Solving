#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

struct location{
    int x; int y;
};

int map[51][51];
vector<location> houses, chickens;
int n, m;

int chicken_distance(){
    int ret = 0, dist = 0;
    for(int i=0; i<houses.size(); i++){ // calculate closest chicken in each house
        dist = INF;
        for(int j=0; j<chickens.size(); j++){
            if(map[chickens[j].x][chickens[j].y]!=2) continue;
            dist = min(dist, abs(houses[i].x-chickens[j].x)+abs(houses[i].y-chickens[j].y));
        }
        ret += dist;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int a, ans=INF;
    location l;
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            map[i][j] = a;
            if(a==1){
                l.x=i; l.y=j; houses.push_back(l);
            }
            if(a==2){
                l.x=i; l.y=j; chickens.push_back(l);
            }
        }
    }
    
    vector<bool> closed; // make permutaion vector
    for(int i=0; i<m; i++) closed.push_back(0);
    for(int i=0; i<chickens.size()-m; i++) closed.push_back(1);
    
    
    do {
        for (int i = 0; i < closed.size(); i++){
            if (closed[i]) map[chickens[i].x][chickens[i].y] = 0; // close
        }
        ans = min(ans, chicken_distance()); // calculate the min distance
        // cout<<ans<<endl;
        for (int i = 0; i < closed.size(); i++){
            if (closed[i]) map[chickens[i].x][chickens[i].y] = 2; // open back
        }
    } while(next_permutation(closed.begin(), closed.end()));
    
    cout<<ans;
    return 0;
}
