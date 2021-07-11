# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


def addChild(parent, newVal):
    if parent!=None:
        left = TreeNode(newVal, left = parent.left)
        right = TreeNode(newVal, right = parent.right)
        parent.left = left
        parent.right = right


class Solution:
    def addOneRow(self, root: TreeNode, val: int, depth: int) -> TreeNode:
        queue = deque()
        queue.appendleft(root)
        level = 1
        
        if depth == 1:
            return TreeNode(val, left = root)
        
        while len(queue)!=0:
            size = len(queue)
            while (size!=0):
                size-=1
                node = queue.pop()
                if level == depth-1:
                    addChild(node,val)
                elif node!=None:
                    queue.appendleft(node.left)
                    queue.appendleft(node.right)
            level+=1
            
        return root
        