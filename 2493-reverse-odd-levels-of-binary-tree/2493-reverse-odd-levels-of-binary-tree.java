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
    public TreeNode reverseOddLevels(TreeNode root) {
        dfs(root.left, root.right, 1);
        return root;
    }

    public void dfs(TreeNode lbr, TreeNode rbr, int lvl) {
        if (lbr == null || rbr == null) {
            return;
        }
        if (lvl % 2 == 1) {
            int tmp = lbr.val;
            lbr.val = rbr.val;
            rbr.val = tmp;
        }
        dfs(lbr.left, rbr.right, lvl + 1);
        dfs(lbr.right, rbr.left, lvl + 1);
    }
}