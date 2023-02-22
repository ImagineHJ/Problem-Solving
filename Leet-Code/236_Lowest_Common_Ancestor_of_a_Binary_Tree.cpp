
// using DFS
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

// iterative solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, bool>> st;
        unordered_map<int, int> um;
        bool p_found=false, q_found=false;
        TreeNode *node;

        st.push({root,(!p_found && !q_found)});
        while(1){
            node = st.top().first;
            if(node==p) p_found = true;
            if(node==q) q_found = true;
            if(node->left && um[node->left->val]!=1) st.push({node->left, (!p_found && !q_found)});
            else if(node->right && um[node->right->val]!=1) st.push({node->right, (!p_found && !q_found)});
            else{
                if(st.top().second && q_found && p_found) break;
                um[node->val] = 1;
                st.pop();
            }
        }
        return st.top().first;
    }
};
