#include <stdio.h>

int main() {
    char a[51][51];
    char c, temp;
    int n, m, ans=64;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            scanf("%c", &c);
            if(c!='\n') a[i][j]=c;
            else j--;
        }
    
    
    for(int i=0; i<n-7; i++)
        for(int j=0; j<m-7; j++){
            int total=0;
            for(int x=0; x<8; x++){
                if(x%2==0) temp='W';
                else temp='B';
                
                for(int y=0; y<8;y++){
                    if(a[i+x][j+y]!=temp) total++;
                    
                    if(temp=='W') temp='B';
                    else temp='W';
                }
                
            }
            //printf("%d, %d: %d\n", i, j, total);
            if(ans>total) ans=total;
            if(ans>64-total) ans=64-total;
        }
    
    printf("%d", ans);
    
    return 0;
}
