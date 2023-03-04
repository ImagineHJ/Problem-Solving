class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> oneIndex;
        int i, prev, digit, val;
        for(i=s.size()-1; i>=0; i--){
            if(s[i]=='1') oneIndex.push_back(i);
        }
        prev = 0;
        if(k==0) return s.size()-oneIndex.size();

        for(i=0; i<oneIndex.size(); i++){
            digit = s.size()-1-oneIndex[i];
            if(digit>log2(k-prev)) break;
            val = prev + pow(2, digit);
            if(val>k) break;
            prev = val;
        }
        return s.size()-oneIndex.size()+i;
    }
};
