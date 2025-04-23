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
    public void reorderList(ListNode head) {

        // If the list is empty or has only one node, no need to reorder
        if (head == null || head.next == null) {
            return;
        }

        // Find the middle of the linked list using slow and fast pointers
        ListNode slow = head;
        ListNode fast = head;
        ListNode tail = null;
        while (fast != null && fast.next != null) {
            tail = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Break the list into two halves: [head -> ... -> tail1] and [slow -> ...]
        tail.next = null;

        // Reverse the second half of the list
        ListNode prev = null;
        while (slow != null) {
            ListNode nxt = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nxt;
        }

        // Merge the two halves alternately
        ListNode left = head;
        ListNode right = prev;
        while (left != null) {
            ListNode rightOfLeft = left.next;
            ListNode rightOfRight = right.next;

            left.next = right;

            // If the left half ends, we're done
            if (rightOfLeft == null) {
                break;
            }

            right.next = rightOfLeft;

            // Move to the next pair of nodes in both halves
            left = rightOfLeft;
            right = rightOfRight;
        }
    }
}
