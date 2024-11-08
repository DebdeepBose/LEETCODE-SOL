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
    public int maxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int[] maxi = new int[1];
        maxi[0] = Integer.MIN_VALUE;
        maxPathFind(root, maxi);
        return maxi[0];
    }
    public int maxPathFind(TreeNode node, int[] maxi) {
        if (node == null) {
            return 0;
        }
        int lps = maxPathFind(node.left, maxi);
        int lh = Math.max(0, lps);

        int rps = maxPathFind(node.right, maxi);
        int rh = Math.max(0, rps);

        maxi[0] = Math.max(maxi[0], node.val + lh + rh);
        return node.val + Math.max(lh, rh);
    }
}
