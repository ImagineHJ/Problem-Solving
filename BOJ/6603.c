#include <stdio.h>

int a[13];

void go(int, int, int, int*);
void copy(int *, int*, int);

int main() {
    int n;
    int b[7]={0, };
    
    while(1){
        scanf("%d", &n);
        if(n==0) break;
        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        go(0, n, 0, b);
        printf("\n");
    }
    
    return 0;
}

void go(int idx, int length, int cnt, int* b){
    int c[7], d[7];
    
    if(cnt==6){ //basecase 1
        for(int i=0; i<6; i++){
            printf("%d ", b[i]);
        }
        printf("\n");
        return;
    }//end if
    
    if(idx>=length) return; //basecase2
    
    copy(b, c, 7); c[cnt]=a[idx]; //copy array
    copy(b, d, 7);
    
    go(idx+1, length, cnt+1, c); //include the number
    go(idx+1, length, cnt, d); //pass the number
    
}

void copy(int* a, int*b, int n){
    for(int i=0; i<n; i++)
        b[i]=a[i];
}
