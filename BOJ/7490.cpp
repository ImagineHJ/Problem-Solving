#include <iostream>

using  namespace std;

int expression[15];
int n;

void print()
{
    cout<<"1";
    for(int j=2; j<=n; j++){
        if(expression[j]==0){
            cout<<" ";
        }
        else if(expression[j]==1){
            cout<<"+";
        }
        else if(expression[j]==2){
            cout<<"-";
        }
        cout<<j;
    }
    cout<<'\n';
    
}

void makeExpression(int i)
{
    if(i==(n+1))
    {
        int ans=0, sum=0, digit=1;
        expression[1]=1;
        for(int j=n; j>=1; j--)
        { // calculate expression
            if(expression[j]==0){
                sum += j*digit;
                digit *= 10;
            }
            else if(expression[j]==1){
                sum += j*digit;
                ans += sum;
                sum = 0; digit=1;
            }
            else if(expression[j]==2){
                sum += j*digit;
                ans -= sum;
                sum = 0; digit=1;
            }
            
        }
        if(ans==0)
        {
            print();
        }
        return;
    }
    expression[i]=0;
    makeExpression(i+1); // DFS
    
    expression[i]=1;
    makeExpression(i+1);
    
    expression[i]=2;
    makeExpression(i+1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int t;
    cin>>t;
    for(int tc=0; tc<t; tc++)
    {
        cin>>n;
        makeExpression(2);
        cout<<'\n';
    }
    
    return 0;
}

