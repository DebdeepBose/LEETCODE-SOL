/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {

         // Edge Case: If node is null or it's the last node, we can't delete it using this method
        if (node == null || node.next == null) {
            return ;
        }

        //Copy the value of the next node into the current node
        node.val = node.next.val;

        // Link current node to the next of next node
        node.next = node.next.next;
        
    }
}