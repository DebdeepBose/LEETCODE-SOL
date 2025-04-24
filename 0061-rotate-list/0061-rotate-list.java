class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Find the length and tail
        int len = 1; // Start from 1 because we're already at head
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            len++;
        }

        // Connect tail to head to make it circular
        tail.next = head;

        // Find the new tail: (len - k % len - 1) steps from head
        k = k % len;
        int stepsToNewTail = len - k;
        ListNode newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        // Break the circle and return the new head
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
