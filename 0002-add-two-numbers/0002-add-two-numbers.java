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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Dummy node to build the result list
        ListNode dummyNode = new ListNode(-1);
        ListNode current = dummyNode;

        // Pointers to traverse both lists
        ListNode temp1 = l1;
        ListNode temp2 = l2;

        int carry = 0;

        while (temp1 != null || temp2 != null) {
            int sum = carry;

            if (temp1 != null) {
                sum += temp1.val;
                temp1 = temp1.next;
            }

            if (temp2 != null) {
                sum += temp2.val;
                temp2 = temp2.next;
            }

            carry = sum / 10;
            ListNode newNode = new ListNode(sum % 10);//createnew node with the digit
            current.next = newNode; // link it to the current list

            current = current.next;
        }

        // Add final carry if it exists
        if (carry > 0) {
            current.next = new ListNode(carry); //Instead of carry u may give 1
        }

        return dummyNode.next;
    }
}
