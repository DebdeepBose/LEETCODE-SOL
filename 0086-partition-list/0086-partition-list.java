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
    public ListNode partition(ListNode head, int x) {
        ListNode dummy = new ListNode(-1);
        ListNode dummy2 = new ListNode(-1);
        ListNode cur = dummy;
        ListNode cur2 = dummy2;
        ListNode tmp = head;
        while (tmp != null) {
            if (tmp.val < x) {
                cur.next = tmp;
                cur = tmp;
            } else if (tmp.val >= x) {
                cur2.next = tmp;
                cur2 = tmp;
            }
            tmp = tmp.next;
        }
        cur2.next = null;
        cur.next = dummy2.next;
        return dummy.next;
    }
}