#include <stdio.h>

/*int go(int n){
    int ans=0;
    
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 3;
    
    for(int i=1; i<4; i++){
        ans+=go(n-i);
        if(n-i<4) ans++;
    }
    return ans;

}*/


int go(int n){
    
    if(n<0) return 0;
    if(n<=1) return 1;
    
    return go(n-1)+go(n-2)+go(n-3);

}

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &m);
        printf("%d\n", go(m));
    }

    return 0;
}
