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
    public int diameterOfBinaryTree(TreeNode root) {
        int[] maxleftRightPathLen = new int[1];
        findMaxPathLengthOnBothSides(root, maxleftRightPathLen);
        return maxleftRightPathLen[0];
    }

    public int findMaxPathLengthOnBothSides(TreeNode node, int[] maxleftRightPathLen) {
        if (node == null) {
            return 0;
        }

        int leftLen = findMaxPathLengthOnBothSides(node.left, maxleftRightPathLen);
        int rightLen = findMaxPathLengthOnBothSides(node.right, maxleftRightPathLen);
        maxleftRightPathLen[0] = Math.max(maxleftRightPathLen[0], leftLen + rightLen);

        return 1 + Math.max(leftLen, rightLen);
    }
}