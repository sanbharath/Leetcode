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

class NodeResult {
    public:
    int height;
    bool isBalanced;
    NodeResult(int h,int b){
        this->height = h;
        this->isBalanced = b;
    }
};


class Solution {
public:
    
    NodeResult isHeightBalanced(TreeNode* node){
        
        if(!node){
            return NodeResult(0,1);
        }
        
        NodeResult leftChildResult = isHeightBalanced(node->left);
        NodeResult rightChildResult = isHeightBalanced(node->right);
        
        int diff = abs(leftChildResult.height - rightChildResult.height);
        
        if(leftChildResult.isBalanced && rightChildResult.isBalanced && diff<=1){
            return NodeResult(max(leftChildResult.height,rightChildResult.height)+1, 1);
        }
        else{
            return NodeResult(0,0);
        }    
    }
    
    bool isBalanced(TreeNode* root) {
        return isHeightBalanced(root).isBalanced;
    }
};