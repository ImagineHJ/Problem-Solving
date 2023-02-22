class Solution {
public:
    // TREE
    class TreeNode{
        public:
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int val){
                this->val = val;
                left = NULL;
                right = NULL;
            }
    };
    TreeNode* root;
    void build_bst(vector<int>& nums){
        TreeNode *node, *p;
        
        node = new TreeNode(nums[0]);
        root = node;

        for(int i=1; i<nums.size(); i++){
            node = new TreeNode(nums[i]);
            p = root;
            while(true){
                if(p->val>nums[i]) {
                    if(p->left==NULL){
                        p->left = node;
                        break;
                    }
                    else p = p->left;
                }
                else if(p->val<nums[i]){
                    if(p->right==NULL){
                         p->right = node;
                         break;
                    }
                    else p = p->right;
                } 
            }
        }
    }
    // TREE 
    
    int arr[1000][1000]; // array used to store nCr
    long long nCr(int n, int r){
        if(n==r) return 1;
        if(r==0) return 1;
        if(r==1) return n;
        if(n<1000 && r<1000 && arr[n][r]!=0) return arr[n][r];  
        long long ret = (nCr(n-1,r)+nCr(n-1,r-1))%(1000000000 + 7);
        if(n<1000 && r<1000) arr[n][r] = ret;
        return ret;
    }
    
    // return (number of ways in the subtree, number of nodes in the subtree -1(root))
    pair<int, int> count_ways(TreeNode* root){
        pair<int, int> p;
        if(root->left==NULL && root->right==NULL) return {1,0};
        if(root->left!=NULL && root->right==NULL) {
            p = count_ways(root->left); p.second++;
            return p;
        }
        if(root->right!=NULL && root->left==NULL){
            p = count_ways(root->right); p.second++;
            return p;
        }

        int left, left_num, right, right_num;
        p = count_ways(root->left); left = p.first; left_num = p.second;
        p = count_ways(root->right); right = p.first; right_num = p.second;
        
        long long left_first = 0, right_first = 0;
        // root -> leftchild -> REST
        // right child can be located in postion which has N(0~left) left-tree nodes ahead
        // in (left-N+right) slots we can choose (left-N) slots for left-tree nodes who comes after the right child
        for(int i=0; i<=left_num; i++){
            left_first += nCr(left_num-i+right_num, left_num-i);
        }
        // root -> rightchild -> REST
        // left child can be located in postion which has N(0~right) right-tree nodes ahead
        // in (left+right-N) slots we can choose (right-N) slots for right-tree nodes who comes after the left child
        for(int i=0; i<=right_num; i++){
            right_first += nCr(left_num+right_num-i, right_num-i);
        }
        long long ret = (left_first+right_first)%(1000000000 + 7);
        ret *=left; ret %=(1000000000 + 7);
        ret *=right; ret %=(1000000000 + 7);
        return {ret, left_num+right_num+2};
    }
    int numOfWays(vector<int>& nums) {
        build_bst(nums);
        return (count_ways(root).first-1)%(1000000000 + 7);
    }
};
