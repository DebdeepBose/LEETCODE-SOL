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

import java.util.*;

class Solution {

    public class Pair {
        TreeNode node;
        long index;

        Pair(TreeNode node, long index) {
            this.node = node;
            this.index = index;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        long maxWidth = 0;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 0));

        while (!q.isEmpty()) {
            int size = q.size();
            long levelStartIndex = q.peek().index;
            long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                Pair current = q.poll();
                long normalizedIndex = current.index - levelStartIndex;

                if (i == 0) {
                    first = normalizedIndex;
                }
                if (i == size - 1) {
                    last = normalizedIndex;
                }

                if (current.node.left != null) {
                    q.offer(new Pair(current.node.left, 2 * normalizedIndex + 1));
                }
                if (current.node.right != null) {
                    q.offer(new Pair(current.node.right, 2 * normalizedIndex + 2));
                }
            }

            maxWidth = Math.max(maxWidth, last - first + 1);
        }

        return (int) maxWidth;
    }
}
