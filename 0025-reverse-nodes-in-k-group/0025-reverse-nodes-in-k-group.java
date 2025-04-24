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
    public ListNode getKthNode(ListNode tmpNode, int k) {
        for (int i = 0; i < k - 1; i++) {
            if (tmpNode == null) {
                return null;
            }
            tmpNode = tmpNode.next;
        }
        return tmpNode;
    }

    public ListNode reverse(ListNode subHead) {
        ListNode prev = null;
        while (subHead != null) {
            ListNode nxt = subHead.next;
            subHead.next = prev;
            prev = subHead;
            subHead = nxt;
        }
        return prev;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode tmp = head;
        ListNode prevLast = null;
        while (tmp != null) {
            ListNode kthNode = getKthNode(tmp, k);
            if (kthNode == null) {
                if (prevLast != null) {
                    prevLast.next = tmp;
                }
                break;
            }
            ListNode knext = kthNode.next;
            kthNode.next = null;
            reverse(tmp);
            if (tmp == head) {
                head = kthNode;
            } else {
                prevLast.next = kthNode;
            }
            prevLast = tmp;
            tmp = knext;
        }
        return head;
    }
}