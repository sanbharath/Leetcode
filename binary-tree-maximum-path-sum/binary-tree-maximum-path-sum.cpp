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
/*
[1 2 3]


*/
class Solution {
public:
    
    int maxi = -1e7;
    int maxSum(TreeNode* root){
        if(!root)
            return 0;
        
        int leftMax = maxSum(root->left);
        int rightMax = maxSum(root->right);

        //cout<< leftMax << " " << rightMax << endl;
        maxi = max(maxi, root->val + max({leftMax,0}) + max({rightMax,0}));
        
        return max({leftMax, rightMax, 0}) + root->val;
    }
    
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};