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
    struct node{
        TreeNode* node;
	    int depth;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<node> pq;
        node n, child;
        int depth, curr = 0;
        TreeNode* now;

        if(root==NULL) return ans;

        n.node = root;
        n.depth = 0;

        ans.push_back(vector<int>()); 
        pq.push(n); 

        while(!pq.empty()){ // Using BFS
            now = pq.front().node;
            depth = pq.front().depth;
            pq.pop();
            
            if(curr<depth){
                ans.push_back(vector<int>());
                curr++;
            }
            ans[depth].push_back(now->val); // push into the list
            
            if(now->left!=NULL){
                child.node = now->left;
                child.depth = depth+1; // 1 level deeper than parent
                pq.push(child);
            }
            if(now->right!=NULL){
                child.node = now->right;
                child.depth = depth+1;
                pq.push(child);
            }
        }
        return ans;
    }
};


// DFS
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* start, int depth){
        
        while(ans.size()<depth+1){
            ans.push_back(vector<int>()); 
        }

        ans[depth].push_back(start->val);
        if(start->left!=NULL){
            dfs(start->left, depth+1);
        }
        if(start->right!=NULL){
            dfs(start->right, depth+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        dfs(root, 0);
        return ans;
    }
};
