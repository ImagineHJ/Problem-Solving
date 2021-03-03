#include <iostream>
#include <deque>
using  namespace std;
int pushed[51]={0,};
int n;

int two_or_three(int loc, int front);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    deque<int> d;
    
    int location[51];
    int m, ans=0, front=1, remain;
    
    cin>>n>>m;
    remain=n;
    
    for(int i=0; i<m; i++){
        int l;
        cin>>l;
        location[i]=l;
    }
    for(int i=0; i<m; i++){
        ans+=two_or_three(location[i], front);
        pushed[location[i]]=1;
        remain--;
        
        if(remain==0) break;
        
        front=location[i];
        if(front==n) front=1;
        else front++;
               
        while(pushed[front]!=0) {
            if(front==n) front=1;
            else front++;
        }
        
    }
    cout<<ans;
    return 0;
}

int two_or_three(int loc, int f){
    int two_cnt=0, three_cnt=0;
    int front=f;
    
    while(loc!=front){
        if(front==n) front=1;
        else front++;
        two_cnt++;
        
        while(pushed[front]!=0) {
            if(front==n) front=1;
            else front++;
        }
    }
    
    front=f;
    while(loc!=front){
        if(front==1) front=n;
        else front--;
        three_cnt++;
        
        while(pushed[front]!=0) {
            if(front==1) front=n;
            else front--;
        }
    }
    
    if(two_cnt>three_cnt) return three_cnt;
    else return two_cnt;
}
