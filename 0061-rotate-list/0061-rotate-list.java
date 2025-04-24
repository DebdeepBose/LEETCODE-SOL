class Solution {
    // Helper to reverse a linked list and return new head
    public ListNode reverse(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Find length of list
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }

        // Adjust k in case it's >= length
        k = k % length;
        if (k == 0) {
            return head;
        }

        // Reverse whole list
        ListNode revHead = reverse(head);

        //Break into two parts: first k nodes and the rest
        ListNode fhalf_end = revHead;
        for (int i = 1; i < k && fhalf_end != null; i++) {
            fhalf_end = fhalf_end.next;
        }

        ListNode shalf_start = null;
        if (fhalf_end != null) {
            shalf_start = fhalf_end.next;
            fhalf_end.next = null; // Break the list
        }

        //Reverse both parts individually
        ListNode newHead = reverse(revHead); // First part becomes new head
        ListNode secondPart = reverse(shalf_start); // Second part

        //Attach the two parts
        ListNode tail = newHead;
        while (tail.next != null) {
            tail = tail.next;
        }
        tail.next = secondPart;

        return newHead;
    }
}
