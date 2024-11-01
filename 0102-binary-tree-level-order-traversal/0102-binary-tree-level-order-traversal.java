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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<List<Integer>> v = new ArrayList<List<Integer>>();
        if (root == null) {
            return v;
        }
        q.add(root);
        while (!q.isEmpty()) {
            int qsize = q.size();
            List<Integer> subv = new ArrayList<>();
            for (int i = 0; i < qsize; i++) {
                if (q.peek().left != null) {
                    q.add(q.peek().left);
                }
                if (q.peek().right != null) {
                    q.add(q.peek().right);
                }
                subv.add(q.poll().val);
            }
            v.add(subv);
        }
        return v;
    }
}