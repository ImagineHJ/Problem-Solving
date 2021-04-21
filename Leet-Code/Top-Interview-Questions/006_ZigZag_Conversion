#include<string>

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strv(numRows);
        int num=0;
        bool up=false;
        string ans;
        
        if(numRows==1) return s;
        
        for(int i=0; i<s.length(); i++){
            strv[num].push_back(s[i]);
            if(up) num--;
            else num++;
            if(num==numRows-1) up=true;
            else if(num==0) up=false;
        }
        cout<<endl;
        for(int i=0; i<numRows; i++){
            ans.append(strv[i]);
        }
        return ans;
        
    }
};
