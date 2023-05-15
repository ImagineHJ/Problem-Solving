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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<pair<TreeNode *, int>> q;
        int curlevel, prevlevel, prevval;
        TreeNode *cur;

        prevlevel = 0; prevval = 0;
        
        // queue를 사용한 BFS
        // level이 달라졌다 -> pre node삽입
        if(root==NULL) return ret;
        q.push({root, 1});
        while(!q.empty()){
            curlevel = q.front().second;
            cur = q.front().first;
            q.pop();

            if(prevlevel!=0 && curlevel!=prevlevel) ret.push_back(prevval);
            
            if(cur->left) q.push({cur->left, curlevel+1});
            if(cur->right) q.push({cur->right, curlevel+1});
            
            prevlevel = curlevel;
            prevval = cur->val;
        }
        ret.push_back(prevval);

        return ret;
    }
};
