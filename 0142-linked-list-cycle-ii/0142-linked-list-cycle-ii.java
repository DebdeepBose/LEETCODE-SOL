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
    public ListNode detectCycle(ListNode head) {
        // Initialize slow and fast pointers
        ListNode slowPointer = head;
        ListNode fastPointer = head;

        // Detect if a cycle exists using Floyd's Tortoise and Hare algorithm
        while (fastPointer != null && fastPointer.next != null) {
            slowPointer = slowPointer.next;           // Move slowPointer by 1
            fastPointer = fastPointer.next.next;      // Move fastPointer by 2

            // If they meet, a cycle is detected
            if (slowPointer == fastPointer) {
                //Find the starting point of the cycle
                while (head != slowPointer) {
                    head = head.next;
                    slowPointer = slowPointer.next;
                }
                return slowPointer; // Cycle detected, return entry point
            }
        }

        // If fastPointer reaches null, there is no cycle
        return null;
    }
}
