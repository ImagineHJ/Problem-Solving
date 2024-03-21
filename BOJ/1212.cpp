#include <iostream>

using namespace std;

string getTwo(char c){
    if(c=='0') return "000";
    if(c=='1') return "001";
    if(c=='2') return "010";
    if(c=='3') return "011";
    if(c=='4') return "100";
    if(c=='5') return "101";
    if(c=='6') return "110";
    if(c=='7') return "111";
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s, ans="";
    cin>>s;
    int i;
    for(i=0; i<s.size(); i++){
        ans += getTwo(s[i]);
    }
    for(i=0; i<ans.size(); i++){
        if(ans[i]!='0') break;
    }
    if(i!=ans.size())cout<<ans.substr(i, ans.size())<<'\n';
    else cout<<"0\n";
    
    return 0;
    
}
