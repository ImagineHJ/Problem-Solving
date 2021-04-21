#include <stdio.h>

int top=-1;
char A[101];

//take a peak at the char in top
char peak(){
    return A[top];
}

void push(char c){
    A[++top]=c;
    return ;
}

char pop(){
    return A[top--];
}
 

//when the sentence is unbalanced from the middle, it reads till the end of the sentence and prints no
//saves time
void tilltheend(){
    char c;
    
    while(1){
        scanf("%c", &c);
        if (c=='.') break;
    }
    printf("no\n");
    return;
}

int main() {
    int B=0; //variable that seperates the two cases when the input meets '.'
    char c;
    
    
    while(1){
        scanf("%c", &c);
        
        //two cases: end of the sentence and end of the program
        if(c=='.') {
            if(top==-1 && B==1) {printf("yes\n"); B=0;} //there was a input, balanced
            else if(top!=-1 && B==1) {printf("no\n"); top=-1; B=0;} //there was a input, but not balanaced
            else if(B==0) break; //break out of the while loop and end the program
        }
        
        else if (c=='[') {push('['); B=1;}
            
        else if (c==']') {
            B=1;
            if (top==-1||peak()!='[') {tilltheend(); B=0; top=-1;}
            else if(peak()=='[') pop();
        }
            
        else if (c=='(') {push('('); B=1;}
            
        else if (c==')') {
            B=1;
            if (top==-1||peak()!='(')  {tilltheend(); B=0; top=-1;}
            else pop();}
            
        else if (c!='\n') B=1; //'\n'should be regarded as no input in this case
    
        }
     
    return 0;
}
