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
    public int maxPathSum(TreeNode root) {
        int[] v = new int[1];
        v[0] = Integer.MIN_VALUE;
        help(root, v);
        return v[0];
    }

    public int help(TreeNode node, int[] v) {
        if (node == null) {
            return 0;
        }

        int left = help(node.left, v);
        int leftsum = Math.max(0, left);
        int right = help(node.right, v);
        int rightsum = Math.max(0, right);

        v[0] = Math.max(v[0], leftsum + rightsum + node.val);
        return node.val + Math.max(leftsum, rightsum);
    }
}