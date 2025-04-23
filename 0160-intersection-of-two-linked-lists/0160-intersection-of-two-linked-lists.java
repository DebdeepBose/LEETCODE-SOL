/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashMap<ListNode, Integer> mp = new HashMap<>();
        ListNode tmp = headA;
        while (tmp != null) {
            mp.put(tmp, mp.getOrDefault(tmp, 0) + 1);
            tmp = tmp.next;
        }
        tmp = headB;
        while (tmp != null) {
            if (mp.containsKey(tmp)) {
                return tmp;
            }
            tmp = tmp.next;
        }

        return null;
    }
}