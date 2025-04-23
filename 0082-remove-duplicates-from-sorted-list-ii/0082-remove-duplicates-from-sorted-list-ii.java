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

        if (head == null || head.next == null) {
            return head;
        }

        ListNode dummy = new ListNode(-1);
        ListNode left = dummy;
        dummy.next = head;
        ListNode right = left.next;
        while (right != null) {
            while (right.next != null && right.val == right.next.val) {
                right = right.next;
            }
            if (left.next == right) {
                left = left.next;
                right = right.next;
            } else if (left.next != right) {
                left.next = right.next;
                right = left.next;
            }
        }
        return dummy.next;
    }
}