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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        boolean flag = false;
        q.add(root);
        while (!q.isEmpty()) {
            List<Integer> tmp = new ArrayList<>();
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();

                tmp.add(node.val);

                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }
            }
            if (flag) {
                Collections.reverse(tmp);
                flag = false;
            } else {
                flag = true;
            }
            ans.add(tmp);
        }

        return ans;
    }
}