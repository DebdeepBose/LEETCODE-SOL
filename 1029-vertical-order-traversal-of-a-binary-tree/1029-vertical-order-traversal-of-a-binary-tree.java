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
class Tuple {
    TreeNode node;
    int verticalColumn;
    int depthLevel;

    public Tuple(TreeNode node, int verticalColumn, int depthLevel) {
        this.node = node;
        this.verticalColumn = verticalColumn;
        this.depthLevel = depthLevel;
    }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer,TreeMap<Integer,PriorityQueue<Integer>>> mp = new TreeMap<>();
        Queue<Tuple> q = new LinkedList<>();

        q.offer(new Tuple(root,0,0));

        while(!q.isEmpty()){

            Tuple t = q.poll();
            TreeNode n = t.node;
            int vertical = t.verticalColumn;
            int depth = t.depthLevel;

            mp.putIfAbsent(vertical,new TreeMap<>());
            mp.get(vertical).putIfAbsent(depth, new PriorityQueue<>());
            mp.get(vertical).get(depth).offer(n.val);

            if(n.left != null){
                q.offer(new Tuple(n.left,vertical-1,depth+1));
            }

            if(n.right != null){
                q.offer(new Tuple(n.right,vertical+1,depth+1));
            }
        }

        List<List<Integer>> v = new ArrayList<>();

        for(TreeMap<Integer,PriorityQueue<Integer>> innerMp : mp.values()){
            
            List<Integer> temp = new ArrayList<>();

            for(PriorityQueue<Integer> innerPq : innerMp.values()){
                while(!innerPq.isEmpty()){
                    temp.add(innerPq.poll());
                }
            }
            v.add(temp);
        } 

        return v;
    }
}