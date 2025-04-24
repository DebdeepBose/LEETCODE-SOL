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
    public ListNode reverse(ListNode tmpHead) {
        ListNode prev = null;
        while (tmpHead != null) {
            ListNode nxt = tmpHead.next;
            tmpHead.next = prev;
            prev = tmpHead;
            tmpHead = nxt;
        }
        return prev;
    }

    public ListNode getKthNode(ListNode start, int k) {
        for (int i = 0; i < k - 1; i++) {
            if (start == null) {
                return null;
            }
            start = start.next;
        }
        return start;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode tmp = head;
        ListNode prevLast = null;
        while (tmp != null) {
            ListNode kth = getKthNode(tmp, k);
            if (kth == null) {
                if(prevLast != null){
                    prevLast.next = tmp;
                }
                break;
            }
            ListNode nextOfK = kth.next; //Preserve next node ok k , for linking
            kth.next = null;
            reverse(tmp);
            if (tmp == head) { //First k - Group
                head = kth;
            } else {
                prevLast.next = kth;
            }
            prevLast = tmp;
            tmp = nextOfK;
        }
        return head;
    }
}