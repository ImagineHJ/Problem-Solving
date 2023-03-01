class Solution {
public:
    vector<string> ans;
    vector<string> getAlphabets(char digit){
        if(digit=='2') return{"a", "b", "c"};
        if(digit=='3') return{"d", "e", "f"};
        if(digit=='4') return{"g", "h", "i"};
        if(digit=='5') return{"j", "k", "l"};
        if(digit=='6') return{"m", "n", "o"};
        if(digit=='7') return{"p", "q", "r", "s"};
        if(digit=='8') return{"t", "u", "v"};
        if(digit=='9') return{"w", "x", "y", "z"};
        return {};
    }
    void combine(char digit){
        vector<string> alpha = getAlphabets(digit);
        if(ans.size()==0) {ans = alpha; return;}
        int len = ans[0].length();

        for(int i=0; i<ans.size(); i++){
            if(ans[i].length()!=len) break; // new combinations

            for(int j=1; j<alpha.size(); j++){
                ans.push_back(ans[i]+alpha[j]);
            }
            ans[i]+=alpha[0];
        }
    }
    vector<string> letterCombinations(string digits) {
        for(int i=0; i<digits.size(); i++){
            combine(digits[i]);
        }
        return ans;
    }
};
