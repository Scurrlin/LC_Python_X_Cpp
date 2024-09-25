class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        output = []
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            output.append(root.val)
            inorder(root.right)
        inorder(root)
        return output