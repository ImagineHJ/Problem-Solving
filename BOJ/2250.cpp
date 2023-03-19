#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define INF 1e9
using namespace std;

int n, nowCol = 1;
int maxWidth = 0, maxWidthLevel = 0;
pair<int, int> tree[10001]; //first: left, second: right
vector<pair<int, int>> levelWidth; // first: min, second: max

void addlevelWidthSpace(int depth){ // make vector size bigger
    while(levelWidth.size()<=depth){
        levelWidth.push_back({10001, 0});
    }
}

void inorder(int root, int depth){
    if(tree[root].first!=-1) inorder(tree[root].first, depth+1); // left tree
    
    addlevelWidthSpace(depth);
    levelWidth[depth].first = min(levelWidth[depth].first, nowCol); // update min val
    levelWidth[depth].second = max(levelWidth[depth].second, nowCol); // update max val
    int width = levelWidth[depth].second-levelWidth[depth].first+1;
    if(width>maxWidth){ // update max width
        maxWidth = width;
        maxWidthLevel = depth;
    }
    else if(width==maxWidth) maxWidthLevel = min(maxWidthLevel, depth);
    nowCol++;
    
    if(tree[root].second!=-1) inorder(tree[root].second, depth+1); // right tree
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int nn, l, r;
    cin>>n;
    vector<bool> isChild(n+1, false);
    for(int i=0; i<n; i++){
        cin>>nn>>l>>r;
        tree[nn] = {l, r};
        if(l!=-1) isChild[l] = true;
        if(r!=-1) isChild[r] = true;
    }
    int i;
    for(i=1; i<=n; i++){
        if(!isChild[i]) break; // found root
    }
    inorder(i, 1);
    cout<<maxWidthLevel<<" "<<maxWidth;
    
    return 0;
}
