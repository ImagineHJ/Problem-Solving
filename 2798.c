#include <stdio.h>

int main() {
    int n, m, sum=0, ans=0;
    int card[101];
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &card[i]);
    
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++){
                sum=card[i]+card[j]+card[k];
                if(sum<=m && sum>ans) ans=sum;
            }
    printf("%d", ans);
    
    return 0;
}
