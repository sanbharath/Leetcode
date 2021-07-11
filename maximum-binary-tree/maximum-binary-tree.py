# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        
        if len(nums) == 0:
            return None
        
        maxInd = nums.index(max(nums))
        
        left = self.constructMaximumBinaryTree(nums[:maxInd])
        right = self.constructMaximumBinaryTree(nums[maxInd+1:])
        
        return TreeNode(nums[maxInd], left, right)