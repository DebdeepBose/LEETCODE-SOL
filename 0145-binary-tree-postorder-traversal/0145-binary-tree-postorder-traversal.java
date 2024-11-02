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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> v = new ArrayList<>();
        Deque<TreeNode> st = new ArrayDeque<>();
        while(root != null || !st.isEmpty()){
            if(root != null){
                v.add(root.val);
                st.push(root);
                root = root.right;
            }
            else{
                root = st.pop();
                root = root.left;
            }
        }
        Collections.reverse(v);
        return v;
    }
}