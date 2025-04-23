class Solution {
    public ListNode swapNodes(ListNode head, int k) {

        // If the list is empty or has only one node, swapping is not needed
        if (head == null || head.next == null) {
            return head;
        }

        // Move to the k-th node from the beginning
        ListNode frontNode = head;
        for (int i = 1; i < k; i++) {
            frontNode = frontNode.next;
        }

        // Initialize two pointers: one to find the k-th node from the end
        // 'runner' starts from the same node as 'frontNode' and moves till the end
        // 'endNode' moves with 'runner' and lands at the k-th node from the end
        ListNode endNode = head;
        ListNode runner = frontNode;
        while (runner.next != null) {
            endNode = endNode.next;
            runner = runner.next;
        }

        // Swap the values of the k-th node from the start and the k-th node from the end
        int temp = frontNode.val;
        frontNode.val = endNode.val;
        endNode.val = temp;

        return head;
    }
}
