# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        self.nodes = [[root.val]]
        
        if root.left:
            self.nodes.append([root.left.val])
        if root.right:
            if len(self.nodes) < 2:
                self.nodes.append([root.right.val])
            else:
                self.nodes[1].append(root.right.val)

        self.helper(root.left, 2)
        self.helper(root.right, 2)

        return self.nodes

    def helper(self, node, level):
        if not node: 
            return

        if node.left:
            if level >= len(self.nodes):
                self.nodes.append([node.left.val])
            else:
                self.nodes[level].append(node.left.val)
        if node.right:
            if level >= len(self.nodes):
                self.nodes.append([node.right.val])
            else:
                self.nodes[level].append(node.right.val)

        self.helper(node.left, level+1)
        self.helper(node.right, level+1)

# level order traversal is pretty easy and self explanatory honestly
# just add left and right to the list at index[level] and recurse
# if the list is smaller than the level, append
