# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    dp = {}
    def rob(self, root: TreeNode) -> int:
        
        if root == None:
            return 0;
        
        if self.dp.get(root)!=None:
            return self.dp[root]
        #MAX
        # 1. take     -  root->val + rob(root->left->left) + rob(root->left->right) 
        #                + rob(left->right->right) + rob(root->right->right)  
        # 2. not take -  rob(root->left) + rob(root->right) 
        total = root.val
        if root.left!=None:
            total += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right!=None:
            total += self.rob(root.right.left) + self.rob(root.right.right)
        
        self.dp[root] = max(total, self.rob(root.left) + self.rob(root.right))
        return self.dp[root]
               
        
        
        