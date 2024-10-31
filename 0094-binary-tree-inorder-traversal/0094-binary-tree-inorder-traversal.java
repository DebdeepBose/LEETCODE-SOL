/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    private void inorderHelper(TreeNode Node, List<Integer> ans) {
        if (Node == null) {
            return;
        }
        inorderHelper(Node.left, ans);
        ans.add(Node.val);
        inorderHelper(Node.right, ans);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        inorderHelper(root, ans);
        return ans;
    }
}