#include <iostream>
#include <deque>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    int t;
    
    cin>>t;

    for(int i=0; i<t; i++){
        deque<int> d;
        int n, e=0, s=0, si=0, r=0;
        string fun, arr, st;
        cin>>fun>>n>>arr;
        for(int j=1; s<n; j++) {
            if(arr[j]!=','&& arr[j]!=']') {st[si]=arr[j]; si++;}
            else{
                int digit=1, k=0;
                for(long l=si;l>0; l--){
                    k+=digit*(st[l-1]-'0');
                    digit*=10;
                }
                d.push_back(k); s++; si=0;
            }
        }
        /*cout<<fun<<':'<<fun.size()<<' '<<arr<<':'<<arr.size()<<'\n';
        while(!d.empty()) {cout<<d.front()<<' '; d.pop_front();}
        cout<<'\n';*/
        
        
        for(int j=0; j<fun.size(); j++){
            if(fun[j]=='R'){ //toggle
                if(r==0) r=1;
                else r=0;
            }
            else if(fun[j]=='D'){
                if(d.empty()) {e=1; break;}
                
                if(r==0){
                    d.pop_front();
                }
                else{
                    d.pop_back();
                }
            }
        }
        if(e==1) {
            cout<<"error\n";
            continue;
        }
        cout<<'[';
        if(r==0){
            while(d.size()>1) {cout<<d.front()<<','; d.pop_front();}
            if(d.size()==1) cout<<d.front();
        }
        else{
            while(d.size()>1) {cout<<d.back()<<','; d.pop_back();}
            if(d.size()==1) cout<<d.back();
        }
        cout<<"]\n";
    
    
    }
    return 0;
}

