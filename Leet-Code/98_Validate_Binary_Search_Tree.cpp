
// 1. make a list using in-order travesal and check if the list is in ascending order
class Solution {
    public:
        int prev; // can save previous val instead of saving all values using list
        bool first=true, ans = true;
        void in_order(TreeNode *root){
            if(!ans) return;
            if(root==NULL) return;
            in_order(root->left);
            if(!first&&prev>=(root->val)) ans = false; // not ascending order
            prev = root->val;
            first = false;
            in_order(root->right);
        }
    bool isValidBST(TreeNode* root) {
        in_order(root);
        return ans;
    }
};

// 2. using post-order traversal to get min, max value of child tree -> validate if it its binary search tree
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
