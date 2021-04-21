#include <iostream>
#include <deque>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    deque<int> d;
    string str;
    int n;
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>str;
        
        if(str=="push_front"){
            int a;
            cin>>a;
            cin.ignore();
            d.push_front(a);
        }
        else if(str=="push_back"){
            int a;
            cin>>a;
            cin.ignore();
            d.push_back(a);
        }
        else if(str=="pop_front"){
            if(d.empty()) cout<<-1<<'\n';
            else {cout<<d.front()<<'\n'; d.pop_front();}
        }
        else if(str=="pop_back"){
            if(d.empty()) cout<<-1<<'\n';
            else {cout<<d.back()<<'\n'; d.pop_back();}
        }
        else if(str=="size"){
            cout<<d.size()<<'\n';
        }
        else if(str=="empty"){
            if(d.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(str=="front"){
            if(d.empty()) cout<<-1<<'\n';
            else cout<<d.front()<<'\n';
        }
        else if(str=="back"){
            if(d.empty()) cout<<-1<<'\n';
            else cout<<d.back()<<'\n';
        }
    }
    
    return 0;
}
