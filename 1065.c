#include <stdio.h>

int main() {
    int n, a, b, temp, diff, ans=0;
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        int x=1;
        temp=i;
        a=temp%10;
        temp/=10;
        b=temp%10;
        temp/=10;
        diff=a-b;
        
        while(temp && x){
            a=b;
            b=temp%10;
            temp/=10;
            if(diff!=a-b) x=0;
        }
        
        if(x==1) ans++;
    }
    printf("%d", ans);
    
    return 0;
}
