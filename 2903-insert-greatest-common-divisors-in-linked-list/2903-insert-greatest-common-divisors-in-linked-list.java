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
    // Function to calculate GCD using Euclidean algorithm
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to insert GCD of consecutive nodes in the list
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        // Use a temporary pointer to traverse the list
        ListNode tmp = head;
        
        // Traverse the list to find GCD of consecutive nodes and insert it
        while (tmp != null && tmp.next != null) {
            int insVal = gcd(tmp.val, tmp.next.val);  // Get the GCD of current and next node
            ListNode newNode = new ListNode(insVal);  // Create a new node with the GCD value

            // Insert the new node after the current node
            newNode.next = tmp.next;
            tmp.next = newNode;

            // Move the temporary pointer forward by two steps (skip the inserted node)
            tmp = tmp.next.next;
        }

        return head;
    }
}