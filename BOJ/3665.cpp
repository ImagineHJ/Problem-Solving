#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#define INF 1e18
using namespace std;

struct team_rank{
    int team;
    int rank;
};

bool comp(team_rank a, team_rank b){
    return a.rank<b.rank;
}


vector<team_rank> last_rank;
vector<int> graph[501];
vector<int> final_rank;
int has[501];
int n, over = 0; // 1 = impossible, 2 = ?


bool comp_has(int a, int b){
    return graph[a].size()> graph[b].size();
}

void make_last_graph(){
    int team;
    sort(last_rank.begin(), last_rank.end(), comp);
    for(int i=0; i<n; i++){
        team = last_rank[i].team;
        for(int j=i+1; j<n; j++){ // point to all teams that has lower rank
            graph[team].push_back(last_rank[j].team);
        }
    }
}

void change_rank(int a, int b){
    bool change = false;
    for(int i=0; i<graph[a].size(); i++){ // a had higher rank than b (a->b)
        if(graph[a][i] == b){
            graph[a].erase(graph[a].begin()+i);
            graph[b].push_back(a); // now b has higher rank than a (b->a)
            change = true;
            break;
        }
    }
    if(change) return;
    
    for(int i=0; i<graph[b].size(); i++){ // b had higher rank than a (b->a)
        if(graph[b][i] == a){
            graph[b].erase(graph[b].begin()+i);
            graph[a].push_back(b); // // now a has higher rank than b (a->b)
            break;
        }
    }
}

void print_now_rank(){
    int team;
    sort(has, has+n, comp_has); // sort by number of pointing edges the team has = highest team
    for(int i = 0; i<n; i++){
        team = has[i];
        if(graph[team].size() != n-i-1){
            over = 1 ; // (i+1)th ranked team has to have n-i-1 teams pointing(lower rank teams)
            break; // if not impossible to make rank
        }
        final_rank.push_back(team);
    }
    // print
    if(over ==1 ){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0; i<n; i++){
            cout<<final_rank[i]<<" ";
        }
    }
    cout<<'\n';
}

void initialize(){
    over = 0;
    final_rank.clear();
    last_rank.clear();
    for(int i=0; i<=n; i++){
        graph[i].clear();
        has[i] = i+1;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int test, m, a, b;
    team_rank r;
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>n;
        initialize();
        for(int i=1; i<=n; i++){
            cin>>a;
            r.team = a; r.rank = i;
            last_rank.push_back(r);
        }
        make_last_graph(); // make graph of the last year's ranking
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            change_rank(a, b); // change the direction of the edge
        }
        print_now_rank();
    }
    return 0;
}
