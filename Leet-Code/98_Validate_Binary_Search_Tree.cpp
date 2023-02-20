class Solution {
    public:
        bool ans = true;
        // return min, max value of the tree
        pair<int, int> min_max_child(TreeNode *root){
            if(!ans) return {NULL, NULL};
            int max_num = root->val, min_num = root->val; 
            
            pair<int, int> left, right;
            if(root->left!=NULL) {
                left = min_max_child(root->left);
                if(left.second>=root->val) ans = false; // have bigger(or same) value in left child tree
                min_num = left.first;
            }
            if(root->right!=NULL) {
                right = min_max_child(root->right);
                if(right.first<=root->val) ans = false; // have smaller(or same) value in right child tree
                max_num = right.second;
            }
            
            return {min_num, max_num};
        }
    bool isValidBST(TreeNode* root) {
        if(root!=NULL) min_max_child(root);
        return ans;
    }
};
