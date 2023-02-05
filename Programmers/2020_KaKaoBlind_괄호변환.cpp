#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// return the size of front-most balanced str
int cut(string s){
    int i, open_num=0, close_num=0;
    for(i=0; i<s.length(); i++){
        if(s[i]=='(') open_num++;
        else close_num++;
        if(open_num==close_num) break;
    }
    return i+1;
}

// check if the string is correct
bool check_correct(string s){
    stack<char> st;
    
    if(s[0]!='(') return false;
    st.push(s[0]);
    for(int i=1; i<s.length(); i++){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.empty()) return false;
            st.pop();
        } 
    }
    if(st.empty()) return true;
    else return false;
    
}

// erase the first, and last char and reverse the rest string
string erase_and_reverse(string s){
    string r;
    r = s.substr(1, s.length()-2);
    for(int i=0; i<r.length(); i++){
        if(r[i]=='(') r[i]=')';
        else r[i]='(';
    }
    return r;
}

string correct_str(string s){
    int i;
    string u, v;
    
    if(s.length()==0) return s;
    i = cut(s);
    u = s.substr(0, i); v = s.substr(i, s.length()-i); // cut string
    
    if(check_correct(u)) return u+correct_str(v); // if u is correct

    return "("+correct_str(v)+")"+erase_and_reverse(u); // if u is not correct
    
}

string solution(string p) {
    string answer = "";
    
    answer = correct_str(p);
    return answer;
}
