class Solution {
    public boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }

    public List<String> binaryTreePaths(TreeNode root) {
        ArrayList<String> ans = new ArrayList<>();
        ArrayList<String> tmp = new ArrayList<>();
        helper(root, ans, tmp);
        return ans;
    }

    public void helper(TreeNode node, ArrayList<String> ans, ArrayList<String> tmp) {
        if (node == null) {
            return;
        }

        tmp.add(String.valueOf(node.val));

        if (isLeaf(node)) {
            ans.add(String.join("->", tmp));
        }

        helper(node.left, ans, tmp);
        helper(node.right, ans, tmp);

        tmp.remove(tmp.size() - 1);
    }
}
