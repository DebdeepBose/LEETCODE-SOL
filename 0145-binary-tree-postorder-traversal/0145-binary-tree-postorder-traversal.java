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
    private void pst(TreeNode Node,List<Integer> ans){
        if(Node == null){
            return;
        }
        pst(Node.left,ans);
        pst(Node.right,ans);
        ans.add(Node.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        pst(root,ans);
        return ans;
    }
}