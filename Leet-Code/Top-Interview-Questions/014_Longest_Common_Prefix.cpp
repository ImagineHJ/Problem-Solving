#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        int pre_len=strs[0].length();
        string prefix=strs[0];
        
        int i, j;
        string ans;
        
        for(i=1; i<strs.size(); i++){
            if(pre_len>strs[i].length()) pre_len=strs[i].length();
        
            
            for(j=0; j<pre_len; j++){
                if(prefix[j]!=strs[i][j]){
                    pre_len=j;
                    break;}
            }
        //cout<<prefix<<" "<<pre_len;
        }

        
        return prefix.substr(0, pre_len);
        
    }
};
