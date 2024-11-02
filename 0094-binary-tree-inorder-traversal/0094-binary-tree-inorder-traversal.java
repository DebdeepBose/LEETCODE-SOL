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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> v = new ArrayList<Integer>();
        if (root == null) {
            return v;
        }
        Stack<TreeNode> st = new Stack<>();

        while (root != null) {
            st.push(root);
            root = root.left;
        }

        while (!st.isEmpty()) {
            root = st.pop();
            v.add(root.val);
            root = root.right;
            while (root != null) {
                st.push(root);
                root = root.left;
            }
        }
        return v;
    }
}
