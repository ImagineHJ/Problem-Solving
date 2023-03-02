class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, pre_reach,  max_jump = nums[0];
        while(true){
            pre_reach = reach;
            reach = max_jump;
            if(reach>=nums.size()-1) break; // can reach to the end
            max_jump = 0;
            for(int i = pre_reach+1; i<=reach; i++){
                max_jump = max(max_jump, i+nums[i]); // update the maxium reacheable location
            }
            if (max_jump<=reach) break; // cannot reach further anymore
        }
        return reach>=nums.size()-1;
    }
};
