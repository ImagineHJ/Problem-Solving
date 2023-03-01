class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(!root1&&!root2) return true;
        if(root1==NULL&&root2!=NULL || root1!=NULL&&root2==NULL) return false;
        if(root1->val!=root2->val) return false;
        return isSame(root1->left, root2->left)&&isSame(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* now;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            now = q.front(); q.pop();
            if(isSame(now, subRoot)) return true;
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        return false;
    }
};
