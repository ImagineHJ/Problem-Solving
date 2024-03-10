#include <iostream>

using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, n5, n2;
    cin>>n;
    
    if(n%2==0) // 짝수
    {
        n5 = n/5;
        if(n5%2==1){ // 5원 개수도 짝수여야 함
            n5--;
        }
        n2 = (n-5*n5)/2;
    }
    else // 홀수
    {
        n5 = n/5;
        if(n5==0){ // 5원 개수가 홀수가 되는 것이 불가능할 때 -1
            cout<<-1;
            return 0;
        }
        if(n5%2==0){ // 5원 개수도 홀수여야 함
            n5--;
        }
        n2 = (n-5*n5)/2;
        
    }
    cout<<n5+n2;
    
    return 0;
}

