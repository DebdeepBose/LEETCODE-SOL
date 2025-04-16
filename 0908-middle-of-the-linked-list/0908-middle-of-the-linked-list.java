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
    public ListNode middleNode(ListNode head) {
        // 'slowPointer' will move one step at a time
        ListNode slowPointer = head;

        // 'fastPointer' will move two steps at a time
        ListNode fastPointer = head;

        // Traverse the list until 'fastPointer' reaches the end
        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;  // Move two steps ahead
            slowPointer = slowPointer.next;       // Move one step ahead
        }

        // 'slowPointer' is now at the middle node
        return slowPointer;
    }
}
