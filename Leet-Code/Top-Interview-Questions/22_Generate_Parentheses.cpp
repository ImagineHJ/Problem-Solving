class Solution {
public:
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        makeParenthesis("", n, n, 0);
        return ans;
    }

    void makeParenthesis(string cur,  int remainLeft, int remainRight, int nonMatchedLeft){
        if(remainLeft==0 && remainRight==0) {
            ans.push_back(cur);
            return;
        }

        // put )
        if(remainRight!=0 && nonMatchedLeft!=0){
             makeParenthesis(cur+")", remainLeft, remainRight-1, nonMatchedLeft-1);
        }

        // put (
        if(remainLeft!=0){
            makeParenthesis(cur+"(", remainLeft-1, remainRight, nonMatchedLeft+1);
        }
    }
};
