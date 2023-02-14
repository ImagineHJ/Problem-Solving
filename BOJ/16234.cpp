#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int map[51][51];
int alumni[51][51];
int n, l, r, a;

struct nation{
    int x;
    int y;
};

struct alum{
    int nat_cnt;
    int pop_cnt;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool open(){
    int x, y, new_x, new_y, pop_cnt, nat_cnt, alumni_num = 0, diff;
    nation na;
    alum al;
    queue<nation> q;
    vector<alum> alumi_info;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            alumni[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(alumni[i][j]!=-1) continue; // already visited
            
            while(!q.empty()) q.pop(); // clear queue
            pop_cnt = 0; nat_cnt = 0;
            
            na.x = i; na.y = j; q.push(na); // BFS
            while(!q.empty()){
                x = q.front().x; y = q.front().y; q.pop();
                if(alumni[x][y]!=-1) continue; // already visited
                
                alumni[x][y] = alumni_num; // mark alumni num
                pop_cnt+=map[x][y]; nat_cnt++;
                for(int k = 0; k<4; k++){
                    new_x=x+dx[k]; new_y=y+dy[k];
                    if(new_x<0||new_x>=n||new_y<0||new_y>=n||alumni[new_x][new_y]!=-1) continue;
                    diff = abs(map[x][y]-map[new_x][new_y]);
                    if(diff>=l && diff<=r){
                        na.x = new_x; na.y = new_y; q.push(na); // can open boarder
                    }
                }
            }
            al.nat_cnt = nat_cnt; al.pop_cnt = pop_cnt;
            alumi_info.push_back(al);
            alumni_num++;
        }
    }
    bool move = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            alumni_num = alumni[i][j];
            if(alumi_info[alumni_num].nat_cnt>1){
                map[i][j] = alumi_info[alumni_num].pop_cnt/alumi_info[alumni_num].nat_cnt; // make population move
                move = true;
            }
        }
    }
    return move;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            map[i][j] = a;
        }
    }
    
    int day=0;
    while(open()) day++;
    
    cout<<day;
    return 0;
}
