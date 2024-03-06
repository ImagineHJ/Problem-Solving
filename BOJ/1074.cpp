#include <iostream>
#include <math.h>
using  namespace std;

void getOrder(int n, int start, int r, int c){
    if(n==0){
        cout<<start<<'\n';
        return;
    }
    
    int size = pow(2, n-1);
    
    if(r<size && c<size){
        getOrder(n-1, start, r, c);
    }
    else if(r<size && c>=size){
        getOrder(n-1, start+(size*size), r, c-size);
    }
    else if(r>=size && c<size){
        getOrder(n-1, start+(size*size*2), r-size, c);
    }
    else if(r>=size && c>=size){
        getOrder(n-1, start+(size*size*3), r-size, c-size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, r, c;
    cin>>n>>r>>c;
    getOrder(n, 0, r, c);
    
    return 0;
}

