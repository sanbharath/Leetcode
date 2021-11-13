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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        stack<vector<int>> s;
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            
            vector<int> parAns;
            
            int k = q.size();
            while(k--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur){
                    parAns.push_back(cur->val);
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);   
                }
            }
            
            s.push(parAns);
            
        }
        
        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
        
        
    }
};