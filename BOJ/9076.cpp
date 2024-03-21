#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

char flip(char c){
    if(c=='T') return 'H';
    else return 'T';
}

string flip3(int id, string s){
    if(id==0){
        s[0] = flip(s[0]);
        s[1] = flip(s[1]);
        s[2] = flip(s[2]);
    }
    else if(id==1){
        s[3] = flip(s[3]);
        s[4] = flip(s[4]);
        s[5] = flip(s[5]);
    }
    else if(id==2){
        s[6] = flip(s[6]);
        s[7] = flip(s[7]);
        s[8] = flip(s[8]);
    }
    else if(id==3){
        s[0] = flip(s[0]);
        s[3] = flip(s[3]);
        s[6] = flip(s[6]);
    }
    else if(id==4){
        s[1] = flip(s[1]);
        s[4] = flip(s[4]);
        s[7] = flip(s[7]);
    }
    else if(id==5){
        s[2] = flip(s[2]);
        s[5] = flip(s[5]);
        s[8] = flip(s[8]);
    }
    else if(id==6){
        s[0] = flip(s[0]);
        s[4] = flip(s[4]);
        s[8] = flip(s[8]);
    }
    else if(id==7){
        s[2] = flip(s[2]);
        s[4] = flip(s[4]);
        s[6] = flip(s[6]);
    }
    return s;
}

void dfs(string s, int cnt){
    if(um.count(s)==0){
        um[s] = cnt;
    }
    else if(um[s]<=cnt){
        return;
    }
    else{
        um[s] = cnt;
    }
        
    // row1
    dfs(flip3(0, s), cnt+1);
    
    // row2
    dfs(flip3(1, s), cnt+1);
    
    // row3
    dfs(flip3(2, s), cnt+1);
    
    // col1
    dfs(flip3(3, s), cnt+1);
    
    // col2
    dfs(flip3(4, s), cnt+1);
    
    // col3
    dfs(flip3(5, s), cnt+1);
    
    //
    dfs(flip3(6, s), cnt+1);
    
    //
    dfs(flip3(7, s), cnt+1);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int t;
    cin>>t;
    string s="";
    char c;
    for(int tc=0; tc<t; tc++){
        s="";
        um.clear();
        for(int i=0; i<9; i++){
            cin>>c;
            s += c;
        }
        dfs(s, 0);
        if(um.count("HHHHHHHHH")>0 && um.count("TTTTTTTTT")>0){
            cout<<min(um["HHHHHHHHH"], um["TTTTTTTTT"])<<'\n';
        }
        else if(um.count("HHHHHHHHH")>0){
            cout<<um["HHHHHHHHH"]<<'\n';
        }
        else if(um.count("TTTTTTTTT")>0){
            cout<<um["TTTTTTTTT"]<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    
    return 0;
    
}
