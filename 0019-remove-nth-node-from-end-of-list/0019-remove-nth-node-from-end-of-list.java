/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Initialize two pointers that will be used to create a gap of 'n' nodes
        ListNode fastPointer = head;
        ListNode slowPointer = head;

        // Move fastPointer 'n' steps ahead
        for (int i = 0; i < n; i++) {
            fastPointer = fastPointer.next;
        }

        // If fastPointer is null after moving 'n' steps, we remove the head node
        if (fastPointer == null) {
            return head.next;
        }

        // Move both pointers one step at a time until fastPointer reaches the last node
        while (fastPointer.next != null) {
            fastPointer = fastPointer.next;
            slowPointer = slowPointer.next;
        }

        // Remove the nth node from the end
        slowPointer.next = slowPointer.next.next;

        return head;
    }
}
