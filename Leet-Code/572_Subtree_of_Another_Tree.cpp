
// 1. using recursion to check if the tree is same
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

// 2. make an postorder list and compare
 #define MAX 10001
class Solution {
public:
	bool found = false;
    vector<int> rootPostorder, subRootPostorder, same_index;
    void makeSubPostorder(TreeNode* root){
        int value = root? root->val : MAX;
        if (root){
            makeSubPostorder(root->left);
            makeSubPostorder(root->right);
        }
        subRootPostorder.push_back(value);
    }
    void makeRootPostorder(TreeNode* root){
        int value = root? root->val : MAX;

        if(root) {
            makeRootPostorder(root->left); if(found) return;
            makeRootPostorder(root->right); if(found) return;
        }
        rootPostorder.push_back(value);

        vector<int>::iterator iter;
        for (iter = same_index.begin(); iter != same_index.end(); ) {
            if(subRootPostorder[*iter]==value) {
                (*iter)++;
                if(*iter==subRootPostorder.size()) {found = true; break;}
                iter++;
            }
            else iter = same_index.erase(iter);
        }

        if(subRootPostorder[0]==value) {
            same_index.push_back(1);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
			makeSubPostorder(subRoot);
			makeRootPostorder(root);
			return found;
    }
};
