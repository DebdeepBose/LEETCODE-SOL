/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void helper(List<Integer> v, TreeNode node) {
        if (node == null) {
            return;
        }
        v.add(node.val);
        helper(v, node.left);
        helper(v, node.right);
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> v = new ArrayList<>();
        helper(v, root);
        return v;
    }
}