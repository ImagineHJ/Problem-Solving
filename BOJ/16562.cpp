#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 1e18
using namespace std;
int parent[10001];
int money[10001];

int find_parent(int a){
    int ret;
    if(parent[a] == a) return a;
    ret = find_parent(parent[a]);
    parent[a] = ret;
    money[ret] = min(money[ret], money[a]); // save the min money in the group
    return ret;
}
void do_union(int a_p, int b_p){
    
    money[a_p] = min(money[a_p], money[b_p]); // save the min money in the group
    money[b_p] = money[a_p];
    
    if(money[a_p]<money[b_p]) parent[b_p] = a_p;
    else parent[a_p] = b_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int a, b, n, m, k, a_p, b_p, sum=0;
    cin>>n>>m>>k;
    
    for(int i=1; i<=n; i++){
        cin>>a;
        money[i] = a;
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a_p = find_parent(a); b_p = find_parent(b);
        if(a_p!=b_p) do_union(a_p, b_p); // not friends then become friends
    }
    for(int i=1; i<=n; i++){
        if(parent[i]==i) {
            sum+=money[i]; // add all the money of parent
        }
        if(sum>k) break;
    }
    if(sum<=k) cout<<sum;
    else cout<<"Oh no";
    
    return 0;
}
