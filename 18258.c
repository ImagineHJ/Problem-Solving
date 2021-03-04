#include <stdio.h>
#include <string.h>

#define MAX 2000000

int rear=0, front2=0;
int arr[MAX];

void push(int x){
    arr[rear++]=x;
}

int pop(){
    if(front2==rear) return -1;
    
    return arr[front2++];
}

int size(){
    return rear-front2;
}

int empty(){
    if (front2==rear) return 1;
    else return 0;
}

int front(){
    if(front2==rear) return -1;
    return arr[front2];
}

int back(){
    if(front2==rear) return -1;
    return arr[rear-1];
}

int main() {
    char c[6];
    int s, n;
    
    scanf("%d", &s);
    
    for(int i=0; i<s; i++){
        scanf("%s", c);
        
        //문자열 비교할 때 주의합시다
        if(strncmp(c, "push", 4)==0) {
            scanf("%d", &n);
            push(n);
        }
        else if(strncmp(c, "pop", 3)==0) printf("%d\n", pop());
        
        else if(strncmp(c, "size", 4)==0) printf("%d\n", size());
        
        else if(strncmp(c, "empty", 5)==0) printf("%d\n", empty());
        
        else if(strncmp(c, "front", 5)==0) printf("%d\n", front());
        
        else if(strncmp(c, "back", 4)==0) printf("%d\n", back());
    }
    
    return 0;
}
