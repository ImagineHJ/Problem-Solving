class Solution {
public:
    vector<int> nums;
    TreeNode* make_tree(int start, int end){
        if(start>end)return NULL; 
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = make_tree(start, mid-1);
        node->right = make_tree(mid+1, end);
        return node;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return make_tree(0, nums.size()-1);
    }
};
