unordered_map<int, int> um;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        um.clear();
        for(int i=0; i<nums.size(); i++){
            if(um[nums[i]]==1) return true;
            um[nums[i]] = 1;
        }
        return false;
    }
};
