class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string s = countAndSay(n-1);
        string ret;
        char cnt='1'; char prev = s[0];
        for(int i=1; i<s.size(); i++){
            if(prev==s[i]){
                cnt++;
            }
            else{
                ret+=cnt; ret+=prev;
                prev = s[i]; cnt = '1';
            }
        }
        ret+=cnt; ret+=prev;
        return ret;
    }
};
