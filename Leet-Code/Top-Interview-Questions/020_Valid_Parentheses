class Solution {
public:
    char pair(char c){
        if (c==')') return '(';
        if (c=='}') return '{';
        if (c==']') return '[';
        return ' ';
    }
    
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='[')
                st.push(s[i]);
            
            else{
                if(!st.empty() && pair(s[i])==st.top()) st.pop();
                else return false;
            }
            
        }
        
        if(st.empty()) return true;
        return false;
    }
};
