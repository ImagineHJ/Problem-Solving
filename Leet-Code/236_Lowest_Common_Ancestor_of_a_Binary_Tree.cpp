class Solution {
public:
    bool found = false, p_found=false, q_found=false;
    TreeNode *ans;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root==NULL) return;

        bool both_not_found = false;
        if(!p_found && !q_found) both_not_found = true;

        if(root == p) p_found = true;
        if(root == q) q_found = true;
        dfs(root->left, p, q);
        dfs(root->right, p, q);

        // get the first common ancestor
        if(!found && both_not_found && q_found && p_found){ // both are found in child tree -> common ancestor
            found = true;
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
