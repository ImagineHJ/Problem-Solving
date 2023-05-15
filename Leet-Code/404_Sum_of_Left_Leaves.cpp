/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        
        if(root==NULL) return ret;
        
        // left child가 leaf면 덧셈
        if(root->left && !root->left->left && !root->left->right) ret += root->left->val;
        else{
            // leaf가 아니면 재귀 호출
            ret += sumOfLeftLeaves(root->left);
        }
        

        // right 재귀 호출
        ret += sumOfLeftLeaves(root->right);
        
        return ret;
    }
};
