#include <stdio.h>

int main() {
    int n, sum=0, num;
    
    scanf("%d", &n);
    
    for(int i=1; i<n; i++){
        num=i;
        sum=i;
        while(num){
            sum+= num%10;
            num/=10;
        }
        if(sum==n) {printf("%d",i); return 0;}
    }
    
    printf("%d",0);
    return 0;
}
