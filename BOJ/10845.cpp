#include <iostream>
#include <queue>
#include <string>
using  namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    queue<int> q;
    string str;
    int n;
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>str;
        
        if(str=="push"){
            int a;
            cin>>a;
            cin.ignore();
            q.push(a);
        }
        else if(str=="pop"){
            if(q.empty()) cout<<-1<<'\n';
            else {cout<<q.front()<<'\n'; q.pop();}
        }
        else if(str=="size"){
            cout<<q.size()<<'\n';
        }
        else if(str=="empty"){
            if(q.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(str=="front"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.front()<<'\n';
        }
        else if(str=="back"){
            if(q.empty()) cout<<-1<<'\n';
            else cout<<q.back()<<'\n';
        }
    }
    
    return 0;
}

