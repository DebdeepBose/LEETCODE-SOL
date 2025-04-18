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
    public ListNode removeNthFromEnd(ListNode head, int n) {
       int len = 0;
        ListNode tmp = head;
        while (tmp != null) {
            len++;
            tmp = tmp.next;
        }

        if (n == len) {
            return head.next;
        }

        int steps = len - n - 1;
        ListNode curr = head;
        while (steps > 0) {
            steps--;
            curr = curr.next;
        }

        curr.next = curr.next.next;

        return head;
    }
}