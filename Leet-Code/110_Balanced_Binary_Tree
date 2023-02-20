class Solution {
public:
    bool ans = true;
    int depth(TreeNode* root){
        if(!ans) return 0; // answer already found
        if(root==NULL) return 0;
        
        int left_depth, right_depth;
        left_depth = depth(root->left);
        right_depth = depth(root->right);
        if(abs(left_depth-right_depth)>1) ans = false; // unbalanced tree

        return 1+max(left_depth, right_depth); // depth of the tree
    }
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;      
    }
};
