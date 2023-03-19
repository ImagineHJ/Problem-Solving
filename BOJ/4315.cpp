#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define INF 1e9
using namespace std;

int marbles[10001];
int parent[10001];
bool isChild[10001];
int n, cnt = 0;


void postOrder(int root, vector<vector<int>> &child){
    for(int i=0; i<child[root].size(); i++) postOrder(child[root][i], child);
    if(marbles[root]==1) return;
    int par = parent[root];
    if(marbles[root]<=0){
        marbles[par] -= (1-marbles[root]);
        cnt += (1-marbles[root]);
    }
    else if(marbles[root]>1){
        marbles[par] += (marbles[root]-1);
        cnt += (marbles[root]-1);
    }
}


int findRoot(){
    for(int i=1; i<=n; i++){
        if(!isChild[i]) return i;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int v, m, d, c;
    vector<vector<int>> child;
    cin>>n;
    while(n>0){
        // init
        cnt = 0;
        child.clear();
        for(int i=0; i<=n; i++){
            parent[n] = 0;
            isChild[i] = false;
            child.push_back(vector<int>());
        }
        for(int i=0; i<n; i++){
            cin>>v>>m>>d;
            marbles[v] = m;
            for(int j=0; j<d; j++){
                cin>>c;
                child[v].push_back(c);
                parent[c] = v;
                isChild[c] = true;
            }
        }
        int root = findRoot();
        postOrder(root, child);
        cout<<cnt<<'\n';
        cin>>n;
    }
    
    return 0;
}
