#include <stdio.h>

int pop(int*, int*);
void push(int, int*, int*);
void initialize(int, int*);


int main() {
    char c[11];
    int visited[11], temp[11];
    int n, num, next, top=-1;
    
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%c", c+i);
        visited[i]=0;
    }
    
    for(int start=0; start<10; start++){
        num=start;
        
        next=0;
        visited[num]=1;
        push(num, &top, temp); //temp[ind]=num;
        
            while(top<=n && -1<top){
        
                if(c[top]=='<'){
                    for(int i=0; i<n; i++){
                        if(visited[i]==1) continue;
                        if(i>num) num=i; next=1; break;
                    }
                }//end if
        
                if(c[top]=='>'){
                    for(int i=0; i<n; i++){
                        if(visited[i]==1) continue;
                        if(i<num) num=i; next=1; break;
                    }
                }//end if
        
                if(next==0){
                    visited[temp[top]]=0;
                    pop(&top, temp);
                    continue;
                }//end if
        
                next=0;
                visited[num]=1;
                push(num, &top, temp); //temp[ind]=num;
                
                    }//end while
        if(top>n+1) break; //found min
     }//end for
        
    return 0;
}

int pop(int* top, int* a){
    if((*top)==-1) return -1; //empty stack
    else return a[(*top)--];
}

void push(int item, int* top, int* a){
    a[++(*top)]=item;
      }

void initialize(int n, int* a){
    for(int i=0; i<n; i++){
        a[i]=0;
    }
    return;
}
