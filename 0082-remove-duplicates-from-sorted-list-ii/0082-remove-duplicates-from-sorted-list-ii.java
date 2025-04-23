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
    public ListNode deleteDuplicates(ListNode head) {

        // If the list is empty or has only one node, return it as is.
        if (head == null || head.next == null) {
            return head;
        }

        // Create a dummy node before the head to simplify edge-case handling.
        ListNode dummyNode = new ListNode(-1);
        dummyNode.next = head;

        // Initialize two pointers: one trailing (leftPointer) and one leading (rightPointer).
        ListNode leftPointer = dummyNode;
        ListNode rightPointer = leftPointer.next;

        // Traverse the list with rightPointer.
        while (rightPointer != null) {

            // Move rightPointer forward as long as duplicate values are found.
            while (rightPointer.next != null && rightPointer.val == rightPointer.next.val) {
                rightPointer = rightPointer.next;
            }

            // If no duplicates were found between leftPointer and rightPointer, move both forward.
            if (leftPointer.next == rightPointer) {
                leftPointer = leftPointer.next;
                rightPointer = rightPointer.next;
            } 
            // If duplicates were found, skip all of them by linking leftPointer to the node after rightPointer.
            else {
                leftPointer.next = rightPointer.next;
                rightPointer = leftPointer.next;
            }
        }

        // Return the modified list, skipping the dummy node.
        return dummyNode.next;
    }
}
