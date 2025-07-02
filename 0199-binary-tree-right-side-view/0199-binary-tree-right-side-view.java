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
    public List<Integer> rightSideView(TreeNode root) {
        int horizontalLevel = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        reversePreOrder(root,horizontalLevel,ans);

        return ans;
    }
    public void reversePreOrder(TreeNode node, int depth, ArrayList<Integer> ans){
        if(node == null){
            return;
        }
        if(depth == ans.size()){
            ans.add(node.val);
        }

        reversePreOrder(node.right,depth+1,ans);
        reversePreOrder(node.left,depth+1,ans);
    }
}