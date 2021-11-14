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
    
    int findPaths(TreeNode* root,map<int,int> isExists, int ts,int sum){
        
        if(!root)
            return 0;
        
        sum += root->val;
                
        int cnt = 0;
        if(sum == ts)
            ++cnt;
        cnt += isExists[sum - ts];
        isExists[sum]++;
        
        cnt += findPaths(root->left,isExists, ts, sum);
        cnt += findPaths(root->right,isExists, ts, sum);
        
        isExists[sum]--;

        return cnt;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        map<int,int> isExists;
        return findPaths(root,isExists,targetSum,sum);    
    }
};