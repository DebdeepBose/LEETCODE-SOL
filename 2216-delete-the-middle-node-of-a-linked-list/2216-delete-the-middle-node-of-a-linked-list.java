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
    public ListNode deleteMiddle(ListNode head) {
        // If list has 0 or 1 node, the middle is itself — return null
        if (head == null || head.next == null) {
            return null;
        }

        // 'slowPointer' will land just before the middle node
        ListNode slowPointer = head;

        // 'fastPointer' is advanced ahead to ensure 'slowPointer' stops just before the middle
        ListNode fastPointer = head.next.next;

        // Traverse the list until 'fastPointer' reaches the end
        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;
            slowPointer = slowPointer.next;
        }

        // Delete the middle node by skipping it
        slowPointer.next = slowPointer.next.next;

        // Return the modified head
        return head;
    }
}
