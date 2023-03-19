#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define INF 1e9
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    bool found = false;
    int n, k, kParentGroupNumCnt, kGroupNumCnt, now, prev, numCnt, groupNumCnt, groupCnt, parentGroupI, parentGroupNumCnt;
    vector<int> parentGroupNum, childGroupNum;
    cin>>n>>k;
    while(n!=0){
        // init
        found = false; kGroupNumCnt = -1; kParentGroupNumCnt = -1;
        groupCnt = 0; groupNumCnt = 0;
        prev = -1; numCnt = 1;
        parentGroupI = 0; parentGroupNumCnt = 0;
        parentGroupNum.clear(); childGroupNum.clear(); parentGroupNum.push_back(1);
        
        cin>>now;
        if(now==k) {found = true; kParentGroupNumCnt = 1; kGroupNumCnt = 1;}
        while(numCnt<n){
            cin>>now; numCnt++;
            if(found && kParentGroupNumCnt!=-1 && kGroupNumCnt!=-1) continue;
            
            if(prev!=-1 && prev+1!=now){ // new group
                if(found && kGroupNumCnt==-1) kGroupNumCnt = groupNumCnt; // if this is k's group save num of nodes in this group
                groupCnt++;
                childGroupNum.push_back(groupNumCnt); // save how many nodes in a group
                groupNumCnt = 0;
                if(groupCnt==parentGroupNum[parentGroupI]){ // new parent group (group of cousins)
                    if(found && kParentGroupNumCnt==-1) kParentGroupNumCnt = parentGroupNumCnt;
                    parentGroupI++;
                    parentGroupNumCnt = 0;
                    groupCnt = 0;
                    if(parentGroupNum.size()==parentGroupI){ // new depth
                        parentGroupNum.clear();
                        for(int i=0; i<childGroupNum.size(); i++){
                            parentGroupNum.push_back(childGroupNum[i]); // copy child to p
                        }
                        childGroupNum.clear();
                        parentGroupI = 0;
                    }
                }
            }
            if(now==k) found = true;
            groupNumCnt++; parentGroupNumCnt++;
            prev = now;
        }
        if(found && kGroupNumCnt==-1) kGroupNumCnt = groupNumCnt;
        if(found && kParentGroupNumCnt==-1) kParentGroupNumCnt = parentGroupNumCnt;
        cout<<kParentGroupNumCnt-kGroupNumCnt<<'\n';
        cin>>n>>k;
    }
}
