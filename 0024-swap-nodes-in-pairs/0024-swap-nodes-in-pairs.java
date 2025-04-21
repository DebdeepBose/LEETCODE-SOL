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
    public ListNode swapPairs(ListNode head) {
        // If the list is empty or has only one node, nothing to swap
        if (head == null || head.next == null) {
            return head;
        }

        // New head will be the second node after the first swap
        ListNode newHead = head.next;

        ListNode prev = null; // Tracks the previous node to connect with swapped pair
        ListNode first = head; // First node of the current pair
        ListNode second = first.next; // Second node of the current pair

        // Loop to process all pairs
        while (first != null && second != null) {
            first.next = second.next; // Point first to the node after the pair
            second.next = first; // Second points to first, completing the swap

            if (prev != null) {
                prev.next = second; // Connect the previous pair to the current swapped pair
            }

            prev = first; // Move prev to the end of the current pair
            first = first.next; // Move first to the next pair's first node

            // If there's a next node, update second to be its next (2nd in the pair)
            if (first != null) {
                second = first.next;
            }
        }

        return newHead;
    }
}