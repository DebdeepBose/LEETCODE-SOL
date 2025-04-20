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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head; // If list has 0 or 1 node, it's already ordered
        }

        // 'oddPointer' will connect all odd-indexed nodes
        ListNode oddPointer = head;

        // 'evenPointer' will connect all even-indexed nodes
        ListNode evenPointer = head.next;

        // Keep the head of even list to attach at the end of odd list
        ListNode evenHead = evenPointer;

        // Traverse the list while there are more even and odd nodes to rearrange
        while (evenPointer != null && evenPointer.next != null) {
            // Link current odd node to the next odd node
            oddPointer.next = evenPointer.next;
            oddPointer = oddPointer.next;

            // Link current even node to the next even node
            evenPointer.next = oddPointer.next;
            evenPointer = evenPointer.next;
        }

        // Attach the even list after all odd nodes
        oddPointer.next = evenHead;

        return head;
    }
}
