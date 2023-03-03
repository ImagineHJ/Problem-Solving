class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        unsigned int max_bit = pow(2, maximumBit)-1;
        vector<int> ans(n);
        unsigned int x = 0;
        for(int i=0; i<n; i++){
            x ^= nums[i];
            ans[n-i-1] = (~x)&max_bit; // only consider bits below maximumBit
        }
        return ans;
    }
};
