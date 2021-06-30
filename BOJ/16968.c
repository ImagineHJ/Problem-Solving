#include <stdio.h>

int main() {
    char type[5];
    char now, pre;
    int ans;
    
    scanf("%s", type);
    
    if(type[0]=='c') ans=26;
    else ans=10;
    pre=type[0];
        
    for(int i=1; type[i]!='\0'&& i<4; i++){
        now=type[i];
        if(now==pre){
            if(now=='c') ans*=25;
            else ans*=9;
        }
        else{
            if(now=='c') ans*=26;
            else ans*=10;
        }
        pre=now;
    }
    printf("%d", ans);
    
    return 0;
}
