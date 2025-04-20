/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        // If the list is empty or has only one node, it can't have a cycle
        if (head == null || head.next == null) {
            return false;
        }

        // Initialize two pointers for cycle detection
        ListNode slowPointer = head;
        ListNode fastPointer = head;

        // Traverse the list using two pointers at different speeds
        while (fastPointer != null && fastPointer.next != null) {
            slowPointer = slowPointer.next;             // Move by 1 step
            fastPointer = fastPointer.next.next;        // Move by 2 steps

            // If they meet, a cycle exists
            if (slowPointer == fastPointer) {
                return true;
            }
        }

        // If fastPointer reaches the end, there's no cycle
        return false;
    }
}