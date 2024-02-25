#include <iostream>
using  namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
     
    int t, a, b;
     
    cin>>t;
    for(int test=0; test<t; test++){
        cin>>a>>b;
        cout<<"yes\n"; // answer is always yes as A can be expressed with multiples of 1, -1, and itself
    }
     
    return 0;
}
