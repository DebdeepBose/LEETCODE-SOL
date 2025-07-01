class Tuple {
    TreeNode node;
    int row, col;

    public Tuple(TreeNode node, int row, int col) {
        this.node = node;
        this.row = row;
        this.col = col;
    }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // column -> row -> min-heap of node values
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Tuple> q = new LinkedList<>();

        q.offer(new Tuple(root, 0, 0)); // start with root at (0, 0)

        while (!q.isEmpty()) {
            Tuple t = q.poll();
            TreeNode node = t.node;
            int x = t.row;
            int y = t.col;

            // Ensure the nested maps exist
            map.putIfAbsent(x, new TreeMap<>());
            map.get(x).putIfAbsent(y, new PriorityQueue<>());

            map.get(x).get(y).offer(node.val);

            if (node.left != null) q.offer(new Tuple(node.left, x - 1, y + 1));
            if (node.right != null) q.offer(new Tuple(node.right, x + 1, y + 1));
        }

        List<List<Integer>> result = new ArrayList<>();

        for (TreeMap<Integer, PriorityQueue<Integer>> rows : map.values()) {
            List<Integer> vertical = new ArrayList<>();
            for (PriorityQueue<Integer> pq : rows.values()) {
                while (!pq.isEmpty()) {
                    vertical.add(pq.poll());
                }
            }
            result.add(vertical);
        }

        return result;
    }
}
