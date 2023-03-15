#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

bool check[101];
bool first_check[101];
bool second_check[101];
int second[101];
int n, cnt = 0;

void copy_check(){
    for(int i=0; i<=n; i++){
        if(first_check[i]) {check[i] = true; cnt++;}
    }
}

void reset(){
    for(int i=0; i<=n; i++){
        first_check[i] = second_check[i] = false;
    }
}

void pick(int start){
    if(check[start]) return;
    
    reset();
    int next;
    bool success = false;
    while(true){
        next = second[start];
        if(first_check[start]) {success = true; break;}
        first_check[start] = true;
        
        if(second_check[next]) {success = false; break;}
        second_check[next] = true;
        start = next;
    }
    if(success) copy_check();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>second[i];
    for(int i=1; i<=n; i++){
        pick(i);
    }
    cout<<cnt<<'\n';;
    for(int i=1; i<=n; i++){
        if(check[i])cout<<i<<'\n';
    }
    
}
