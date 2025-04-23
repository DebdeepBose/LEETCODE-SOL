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
    public void reorderList(ListNode head) {

        if(head == null || head.next == null){
            return;
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode tail1 = null;
        while (fast != null && fast.next != null) {
            tail1 = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        tail1.next = null;

        ListNode prev = null;
        while (slow != null) {
            ListNode nxt = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nxt;
        }

        ListNode left = head;
        ListNode right = prev;

        while (left != null) {
            ListNode rightOfLeft = left.next;
            ListNode rightOfRight = right.next;

            left.next = right;

            if (rightOfLeft == null) {
                break;
            }

            right.next = rightOfLeft;
            left = rightOfLeft;
            right = rightOfRight;
        }
    }
}