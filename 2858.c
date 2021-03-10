
#include <stdio.h>

int main() {
    int r, b, t, w, l;
    
    scanf("%d %d", &r, &b);
    t=r+b;
    
    for(int i=3; i<=t/2; i++){
        if(t%i==0){
            w=i;
            l=t/i;
            if((w-2)*(l-2)==b) {
                printf("%d %d", l, w);
                return 0;}
        }
    }
    return 0;
}
