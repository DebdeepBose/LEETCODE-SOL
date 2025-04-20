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
    public ListNode reverseList(ListNode head) {
        // If the list is empty or has only one node, it's already reversed
        if (head == null || head.next == null) {
            return head;
        }

        // This will eventually become the new head of the reversed list
        ListNode previousNode = null;

        // Traverse the list and reverse the pointers
        while (head != null) {
            // Store the next node before breaking the link
            ListNode nextNode = head.next;

            // Reverse the current node's pointer
            head.next = previousNode;

            // Move previousNode and head one step forward
            previousNode = head;
            head = nextNode;
        }

        // At the end, previousNode will be pointing to the new head
        return previousNode;
    }
}
