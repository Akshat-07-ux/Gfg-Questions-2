class Solution:
    def preOrder(self, root):
        result = []

        def traverse(node):
            if not node:
                return
            result.append(node.data)   # Visit root
            traverse(node.left)        # Visit left subtree
            traverse(node.right)       # Visit right subtree

        traverse(root)
        return result